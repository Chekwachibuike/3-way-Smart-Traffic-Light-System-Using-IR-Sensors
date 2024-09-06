// Define pin assignments for LEDs
#define ledA1 2 // Green
#define ledA2 3 // Yellow
#define ledA3 4 // Red

#define ledB1 5 // Green
#define ledB2 6 // Yellow
#define ledB3 7 // Red

#define ledC1 8 // Green
#define ledC2 9 // Yellow
#define ledC3 10 // Red

// Define variables for sensor readings
int a1, a2, b1, b2, c1, c2;

// Define the time for yellow light (in milliseconds)
#define YELLOW_TIME 3000 // Time for yellow light

void setup() {
  Serial.begin(9600);

  // Set pin modes for LEDs
  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);
}

void loop() {
  // Read sensor values
  readSensor();

  // Determine traffic density on each road
  int roadDensities[3] = {a1 + a2, b1 + b2, c1 + c2};
  int order[3] = {0, 1, 2}; // Initial order

  // Sort roads by density (Bubble Sort for simplicity)
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 - i; j++) {
      if (roadDensities[order[j]] > roadDensities[order[j + 1]]) {
        int temp = order[j];
        order[j] = order[j + 1];
        order[j + 1] = temp;
      }
    }
  }

  // Open roads in order of least density
  for (int i = 0; i < 3; i++) {
    if (roadDensities[order[i]] != 0) {
      openRoad(order[i], (i < 2 && roadDensities[order[i + 1]] != 0) ? order[i + 1] : -1, i);
    }
  }
}

void readSensor() {
  // Read analog values from sensors and convert to binary
  a1 = analogRead(A0) < 400 ? 1 : 0;
  a2 = analogRead(A1) < 400 ? 1 : 0;
  b1 = analogRead(A2) < 400 ? 1 : 0;
  b2 = analogRead(A3) < 400 ? 1 : 0;
  c1 = analogRead(A4) < 400 ? 1 : 0;
  c2 = analogRead(A5) < 400 ? 1 : 0;
}

void openRoad(int roadIndex, int nextRoadIndex, int densityRank) {
  // Determine the open time based on density rank
  int openTime;
  if (densityRank == 0) { // Least density
    openTime = 5000; // 5 seconds
  } else if (densityRank == 1) { // Medium density
    openTime = 6000; // 6 seconds
  } else if (densityRank == 2) { // Most density
    openTime = 8000; // 8 seconds
  }

  // Start with yellow light for 3 seconds
  if (roadIndex == 0) { // Road A
    digitalWrite(ledA2, HIGH); // Yellow light on
    digitalWrite(ledA3, LOW);  // Red light off
    digitalWrite(ledB1, LOW);  // Green light off for other roads
    digitalWrite(ledB3, HIGH); // Red light on for other roads
    digitalWrite(ledC1, LOW);  // Green light off for other roads
    digitalWrite(ledC3, HIGH); // Red light on for other roads
  } else if (roadIndex == 1) { // Road B
    digitalWrite(ledB2, HIGH); // Yellow light on
    digitalWrite(ledB3, LOW);  // Red light off
    digitalWrite(ledA1, LOW);  // Green light off for other roads
    digitalWrite(ledA3, HIGH); // Red light on for other roads
    digitalWrite(ledC1, LOW);  // Green light off for other roads
    digitalWrite(ledC3, HIGH); // Red light on for other roads
  } else if (roadIndex == 2) { // Road C
    digitalWrite(ledC2, HIGH); // Yellow light on
    digitalWrite(ledC3, LOW);  // Red light off
    digitalWrite(ledA1, LOW);  // Green light off for other roads
    digitalWrite(ledA3, HIGH); // Red light on for other roads
    digitalWrite(ledB1, LOW);  // Green light off for other roads
    digitalWrite(ledB3, HIGH); // Red light on for other roads
  }

  // Wait for the yellow light duration (3 seconds)
  delay(YELLOW_TIME);

  // Turn off the yellow light and turn on the green light
  if (roadIndex == 0) { // Road A
    digitalWrite(ledA2, LOW); // Yellow light off
    digitalWrite(ledA1, HIGH); // Green light on
  } else if (roadIndex == 1) { // Road B
    digitalWrite(ledB2, LOW); // Yellow light off
    digitalWrite(ledB1, HIGH); // Green light on
  } else if (roadIndex == 2) { // Road C
    digitalWrite(ledC2, LOW); // Yellow light off
    digitalWrite(ledC1, HIGH); // Green light on
  }

  // Calculate the time when the next yellow light should start
  unsigned long yellowStartTime = millis() + openTime - 3000;

  // Wait for the green light duration (open time minus the 3 seconds for yellow light)
  while (millis() < yellowStartTime) {
    // Do nothing, just wait
  }

  // Turn on the yellow light for the next road
  if (nextRoadIndex != -1) {
    if (nextRoadIndex == 0) { // Road A
      digitalWrite(ledA2, HIGH); // Yellow light on
    } else if (nextRoadIndex == 1) { // Road B
      digitalWrite(ledB2, HIGH); // Yellow light on
    } else if (nextRoadIndex == 2) { // Road C
      digitalWrite(ledC2, HIGH); // Yellow light on
    }
  }

  // Wait for the remaining time of the green light duration (3 seconds)
  while (millis() < yellowStartTime + 3000) {
    // Do nothing, just wait
  }

  // Turn off the green light and turn on the red light for the current road
  if (roadIndex == 0) { // Road A
    digitalWrite(ledA1, LOW); // Green light off
    digitalWrite(ledA3, HIGH); // Red light on
  } else if (roadIndex == 1) { // Road B
    digitalWrite(ledB1, LOW); // Green light off
    digitalWrite(ledB3, HIGH); // Red light on
  } else if (roadIndex == 2) { // Road C
    digitalWrite(ledC1, LOW); // Green light off
    digitalWrite(ledC3, HIGH); // Red light on
  }

  // Turn off the yellow light for the next road
  if (nextRoadIndex != -1) {
    if (nextRoadIndex == 0) { // Road A
      digitalWrite(ledA2, LOW); // Yellow light off
    } else if (nextRoadIndex == 1) { // Road B
      digitalWrite(ledB2, LOW); // Yellow light off
    } else if (nextRoadIndex == 2) { // Road C
      digitalWrite(ledC2, LOW); // Yellow light off
    }
  }
}
