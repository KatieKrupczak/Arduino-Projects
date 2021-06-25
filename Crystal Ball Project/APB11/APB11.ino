#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9600);
  
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Ball");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if(switchState == LOW) {
      Serial.println("Switch State LOW");
      reply = random(8);
      lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      
      Serial.print("Reply: ");
      Serial.println(reply);
      
      lcd.write("The ball says:");
      lcd.setCursor(0,1);
      
      //waitVoltage();
      switch(reply){
        case 0:
          lcd.write("Yes");
          break;
        case 1:
          lcd.write("Most likely");
          break;
        case 2:
          lcd.write("Certainly");
          break;
        case 3:
          lcd.write("Outlook good");
          break;
        case 4:
          lcd.write("Unsure");
          break;
        case 5:
          lcd.write("Ask again");
          break;
        case 6:
          lcd.write("Doubtful");
          break;
        case 7:
          lcd.write("No");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}

void waitVoltage(){
  while(true){
    Serial.println(analogRead(12));
    if(analogRead(11)>613){
      break;
    }
    delay(50);
  }
}
