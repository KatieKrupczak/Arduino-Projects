#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(12,11,5,4,3,2);
const int pingPin = 9; //Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo pin of sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.write("Dist");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long duration;
  int cm;

  pinMode(pingPin, OUTPUT);
  
  digitalWrite(pingPin, LOW);
  delay(2);
  
  digitalWrite(pingPin, HIGH);
  delay(10);

  digitalWrite(pingPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (int) microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println("cm");
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("Dist:");
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.write(" cm");
  delay(2000);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
