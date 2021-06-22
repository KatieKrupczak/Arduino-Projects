const int pingPin = 9; //Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo pin of sensor
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  
  digitalWrite(pingPin, LOW);
  delay(2);
  
  digitalWrite(pingPin, HIGH);
  delay(10);

  digitalWrite(pingPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
