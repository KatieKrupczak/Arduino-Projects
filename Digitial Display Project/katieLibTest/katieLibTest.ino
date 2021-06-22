#include "DisSeg.h"
DisSeg disseg;

void setup() {
  // put your setup code here, to run once:
  int numDigits = 4;
  int digitPins[] = {9, 10, 11, 12};
  int segmentPins[] = {2,3,4,5,6,7,8};
  disseg.begin(digitPins, segmentPins, numDigits);
}

void loop() {
  // put your main code here, to run repeatedly:
  disseg.setChar(0, '1');
  delay(10000);
}
