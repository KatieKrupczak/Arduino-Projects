#include <SPI.h>
#include <WiFiNINA.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  // check for wifi
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WIFI failed!");
    // stop
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  // print our mac address
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  printMacAddress(mac);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void printMacAddress(byte mac[]) {
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}
