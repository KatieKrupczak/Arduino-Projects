const int sensorPin = A0;
const float baselineTemp = 30.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temp = (voltage - 0.5) * 100;
  
  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);
  Serial.print("Temperature: ");
  Serial.println(temp);

  if (temp < baselineTemp + 2){
    for(int pinNumber = 2; pinNumber < 5; pinNumber++){
      digitalWrite(pinNumber, LOW);
    }
  } else if (temp >= baselineTemp + 6) {
      for(int pinNumber = 2; pinNumber < 5; pinNumber++){
        digitalWrite(pinNumber, HIGH);
      }
  } else if (temp >= baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  
  delay(1);
}
