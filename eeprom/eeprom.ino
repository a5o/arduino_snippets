#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  int v = 6;
  int v2 = 3;
  EEPROM.write(0,v); //only 100.000 cycles!
  EEPROM.write(1,v2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r = EEPROM.read(0);
  int r2 = EEPROM.read(1);
  Serial.print(r);
  Serial.print("; ");
  Serial.println(r2);
  delay(100000);
}
