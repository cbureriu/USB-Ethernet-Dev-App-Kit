#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE};
const char* hostname = "DevApp";

void setup() {
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
  Serial.write(27); Serial.print("[2J");  //ESC+clear screen
  Serial.write(27); Serial.print("[H");   //home
  Serial.println("USB+Ethernet Dev/App");
  Serial.println("--------------------");
  
  Serial.print("HostName: "); Serial.println(hostname);
  
  Ethernet.begin(mac,hostname);

  Serial.print("DHCP IP:  ");
  for (byte b=0;b<4;b++){
    Serial.print(Ethernet.localIP()[b], DEC);
    if(b<3) Serial.print("."); 
    }
  Serial.println();
  
  Serial.println(".");
}

void loop() {
  digitalWrite(PC13, HIGH);
  delay(1000);
  digitalWrite(PC13, LOW);
  delay(1000);
}
