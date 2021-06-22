const int rLEDPin = 10;
const int bLEDPin = 11;
const int gLEDPin = 9;

const int rSensorPin = A0;
const int gSensorPin = A1;
const int bSensorPin = A2;

int rValue = 0;
int gValue = 0;
int bValue = 0;

int rSensorValue = 0;
int gSensorValue = 0;
int bSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);

}

void loop() {
  rSensorValue = analogRead(rSensorPin);
  delay(5);
  gSensorValue = analogRead(gSensorPin);
  delay(5);
  bSensorValue = analogRead(bSensorPin);
  delay(5);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(rSensorValue);
  Serial.print("\t Green: ");
  Serial.print(gSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(bSensorValue);

  rValue = rSensorValue/4;
  gValue = gSensorValue/4;
  bValue = bSensorValue/4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(rValue);
  Serial.print("\t Green: ");
  Serial.print(gValue);
  Serial.print("\t Blue: ");
  Serial.println(bValue);

  analogWrite(rLEDPin, rValue);
  analogWrite(gLEDPin, gValue);
  analogWrite(bLEDPin, bValue);
}
