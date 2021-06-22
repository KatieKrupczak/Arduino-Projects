#include "DisSeg.h"

#define BLANK_IDX 36 // Must match with 'digitCodeMap'
#define DASH_IDX 37
#define PERIOD_IDX 38
#define ASTERISK_IDX 39
#define UNDERSCORE_IDX 40

DisSeg::DisSeg(){
static const int digitCodeMap[] = {
  // GFEDCBA  Segments      7-segment map:
  0b00111111, // 0   "0"          AAA
  0b00000110, // 1   "1"         F   B
  0b01011011, // 2   "2"         F   B
  0b01001111, // 3   "3"          GGG
  0b01100110, // 4   "4"         E   C
  0b01101101, // 5   "5"         E   C
  0b01111101, // 6   "6"          DDD
  0b00000111, // 7   "7"
  0b01111111, // 8   "8"
  0b01101111, // 9   "9"
  0b01110111, // 65  'A'
  0b01111100, // 66  'b'
  0b00111001, // 67  'C'
  0b01011110, // 68  'd'
  0b01111001, // 69  'E'
  0b01110001, // 70  'F'
  0b00111101, // 71  'G'
  0b01110110, // 72  'H'
  0b00110000, // 73  'I'
  0b00001110, // 74  'J'
  0b01110110, // 75  'K'  Same as 'H'
  0b00111000, // 76  'L'
  0b00000000, // 77  'M'  NO DISPLAY
  0b01010100, // 78  'n'
  0b00111111, // 79  'O'
  0b01110011, // 80  'P'
  0b01100111, // 81  'q'
  0b01010000, // 82  'r'
  0b01101101, // 83  'S'
  0b01111000, // 84  't'
  0b00111110, // 85  'U'
  0b00111110, // 86  'V'  Same as 'U'
  0b00000000, // 87  'W'  NO DISPLAY
  0b01110110, // 88  'X'  Same as 'H'
  0b01101110, // 89  'y'
  0b01011011, // 90  'Z'  Same as '2'
  0b00000000, // 32  ' '  BLANK
  0b01000000, // 45  '-'  DASH
  0b10000000, // 46  '.'  PERIOD
  0b01100011, // 42 '*'  DEGREE ..
  0b00001000, // 95 '_'  UNDERSCORE
};

// Constant pointers to constant data
const int * const numeralCodes = digitCodeMap;
const int * const alphaCodes = digitCodeMap + 10;

//Constructor
DisSeg(){
	int i = 0;
}

void begin(const int digitPinsIn[], const int segmentPinsIn[], int numDigitsIn) {
	numDigits = numDigitsIn;
	numSegments = 7;

	for (int segmentNum = 0 ; segmentNum < numSegments ; segmentNum++) {
    	segmentPins[segmentNum] = segmentPinsIn[segmentNum];
  	}

  	for (int digitNum = 0 ; digitNum < numDigits ; digitNum++) {
    	digitPins[digitNum] = digitPinsIn[digitNum];
  	}

  	// Set the pins as outputs, and turn them off
  	for (int digit = 0 ; digit < numDigits ; digit++) {
    	pinMode(digitPins[digit], OUTPUT);
    	digitalWrite(digitPins[digit], LOW);
  }

  	for (int segmentNum = 0 ; segmentNum < numSegments ; segmentNum++) {
    	pinMode(segmentPins[segmentNum], OUTPUT);
    	digitalWrite(segmentPins[segmentNum], HIGH);
  	}

  blank(); // Initialise the display
}

void segmentOn(int segmentNum){
	digitalWrite(segmentPins[segmentNum], HIGH);
}
void segmentOff(int segmentNum){
	digitalWrite(segmentPins[segmentNum], LOW);
}

void digitOn(int digitNum) {
	digitalWrite(digitPins[digitNum], LOW);
}

void digitOff(int digitNum) {
	digitalWrite(digitPins[digitNum], HIGH);
}

void digitClear(int digitNum){
	for(int digit = 0; digit < numDigits; digit++) {
		digitOff(digit);
	}

	digitOn(digitNum);

	for(int seg = 0; seg < segmentNum; seg++) {
		segmentOff(seg);
	}
	digitOff(digitNum);
}

void setChar(int digitNum, const char ch) {
	if (ch == '\0') return; // NULL string terminator
    if (ch >= '0' && ch <= '9') { // Numerical
      digitCodes[digitNum] = numeralCodes[ch - '0'];
    }
    else if (ch >= 'A' && ch <= 'Z') {
      digitCodes[digitNum] = alphaCodes[ch - 'A'];
    }
    else if (ch >= 'a' && ch <= 'z') {
      digitCodes[digitNum] = alphaCodes[ch - 'a'];
    }
    else if (ch == ' ') {
      digitCodes[digitNum] = digitCodeMap[BLANK_IDX];
    }
    else if (ch == '.') {
      digitCodes[digitNum] = digitCodeMap[PERIOD_IDX];
    }
    else if (ch == '*') {
      digitCodes[digitNum] = digitCodeMap[ASTERISK_IDX];
    }
    else if (ch == '_') {
      digitCodes[digitNum] = digitCodeMap[UNDERSCORE_IDX];
    }
    else {
      // Every unknown character is shown as a dash
      digitCodes[digitNum] = digitCodeMap[DASH_IDX];
    }

    writeChar(digitNum);
}

// Displays the string on the display, as best as possible.
// Only alphanumeric characters plus '-' and ' ' are supported
void setChars(const char str[]) {
  for (int digit = 0; digit < numDigits; digit++) {
    digitCodes[digit] = 0;
  }

  int strIdx = 0; // Current position within str[]
  for (int digitNum = 0; digitNum < numDigits; digitNum++) {
    char ch = str[strIdx];
    setChar(digitNum, ch);
    strIdx++;
  }
}

void writeChar(int digitNum) {
	digitalWrite(digitPins[digitNum], LOW);
	digitClear(digitNum);
  	for (int segmentNum = 0 ; segmentNum < numSegments ; segmentNum++) {
    	if (digitCodes[digitNum] & (1 << segmentNum)) { // Check a single bit
      		digitalWrite(segmentPins[segmentNum], HIGH);
    	}
    }
    digitalWrite(digitPins[digitNum], HIGH);
}
}