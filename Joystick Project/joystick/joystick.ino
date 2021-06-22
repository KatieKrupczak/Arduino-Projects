const int VRxPin = A0;
const int VRyPin = A1;
const int SWPin = 5;

int VRx = 0;        // value read from the horizontal pot
int VRy = 0;        // value read from the vertical pot
int SW = 0;         // value read from the switch

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(VRxPin, INPUT);
  pinMode(VRyPin, INPUT);
  pinMode(SWPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  VRx = analogRead(VRxPin);
  VRy = analogRead(VRyPin);
  SW = digitalRead(SWPin);

  // print the results to the Serial Monitor:
  Serial.print("VRrx = ");
  Serial.print(VRx);
  Serial.print("\tVRry = ");
  Serial.print(VRy);
  Serial.print("\tSW = ");
  Serial.println(SW);

  delay(2000);
}
