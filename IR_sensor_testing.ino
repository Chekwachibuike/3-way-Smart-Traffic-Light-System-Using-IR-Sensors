void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValues[6];
  sensorValues[0] = analogRead(A0);
  sensorValues[1] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[3] = analogRead(A3);
  sensorValues[4] = analogRead(A4);
  sensorValues[5] = analogRead(A5);
  
  Serial.print("Sensor A0: ");
  Serial.print(sensorValues[0]);
  if (sensorValues[0] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  Serial.print("Sensor A1: ");
  Serial.print(sensorValues[1]);
  if (sensorValues[1] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  Serial.print("Sensor A2: ");
  Serial.print(sensorValues[2]);
  if (sensorValues[2] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  Serial.print("Sensor A3: ");
  Serial.print(sensorValues[3]);
  if (sensorValues[3] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  Serial.print("Sensor A4: ");
  Serial.print(sensorValues[4]);
  if (sensorValues[4] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  Serial.print("Sensor A5: ");
  Serial.print(sensorValues[5]);
  if (sensorValues[5] < 400) {
    Serial.print(" - Obstruction detected");
  }
  Serial.println();
  
  delay(1000); // Wait for 1 second before reading again
}
