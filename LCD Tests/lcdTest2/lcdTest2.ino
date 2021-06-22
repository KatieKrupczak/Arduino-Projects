#include <LiquidCrystal.h>
LiquidCrystal lcd = LiquidCrystal(12,11,5,4,3,2);

const int switchPin = 7;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);

  lcd.begin(16,2);
  lcd.write("Testing");
  lcd.setCursor(0,1);
  lcd.write("123");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    //if(switchState == LOW) {
      reply = random(3);
      lcd.clear();
      
      lcd.setCursor(0,0);
      lcd.write("Reply is: ");
      
      lcd.print(reply);
      lcd.setCursor(0,1);
      
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
      }
      delay(1000);
    //}
  }

  prevSwitchState = switchState;
}
