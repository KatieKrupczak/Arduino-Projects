#ifndef DisSeg_h
#define DisSeg_h

#ifndef MAXNUMDIGITS
#define MAXNUMDIGITS 8 // Can be increased, but the max number is 2^31
#endif

class DisSeg {
public:
	DisSeg();

	void begin(const int digitPinsIn[], const int segmentPinsIn[], int numDigitsIn);
	void digitClear(int digitNum);
	void setChars(const char str[]);
	void setChar(int digitNum, const char ch);


private:
	int digitPins[4];
 	int segmentPins[7];
 	int numDigits;
  	int numSegments;
  	int digitCodes[MAXNUMDIGITS]; // The active setting of each segment of each digit

 	void segmentOn(int segmentNum);
  	void segmentOff(int segmentNum);
  	void digitOn(int digitNum);
  	void digitOff(int digitNum);
  	void writeChar(int digitNum);
};
	
#endif //DisSeg_h
/// END ///