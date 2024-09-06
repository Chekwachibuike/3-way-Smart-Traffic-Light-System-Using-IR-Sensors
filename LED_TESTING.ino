// Define pin assignments for LEDs
#define ledA1 2
#define ledA2 3
#define ledA3 4

#define ledB1 5
#define ledB2 6
#define ledB3 7

#define ledC1 8
#define ledC2 9
#define ledC3 10

void setup() {
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
  // Turn on each LED for 500 milliseconds and then turn off
  digitalWrite(ledA1, HIGH);
  delay(500);
  digitalWrite(ledA1, LOW);

  digitalWrite(ledA2, HIGH);
  delay(500);
  digitalWrite(ledA2, LOW);

  digitalWrite(ledA3, HIGH);
  delay(500);
  digitalWrite(ledA3, LOW);

  digitalWrite(ledB1, HIGH);
  delay(500);
  digitalWrite(ledB1, LOW);

  digitalWrite(ledB2, HIGH);
  delay(500);
  digitalWrite(ledB2, LOW);

  digitalWrite(ledB3, HIGH);
  delay(500);
  digitalWrite(ledB3, LOW);

  digitalWrite(ledC1, HIGH);
  delay(500);
  digitalWrite(ledC1, LOW);

  digitalWrite(ledC2, HIGH);
  delay(500);
  digitalWrite(ledC2, LOW);

  digitalWrite(ledC3, HIGH);
  delay(500);
  digitalWrite(ledC3, LOW);
}
