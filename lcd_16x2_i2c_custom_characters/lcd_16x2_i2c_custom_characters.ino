#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 


byte upup[] = {
  B00100,
  B01110,
  B11111,
  B00000,
  B00100,
  B01110,
  B11111,
  B00000
};

byte up[] = {
  B00000,
  B00000,
  B00100,
  B01110,
  B11111,
  B00000,
  B00000,
  B00000
};

byte equal[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

byte down[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte downdown[] = {
  B00000,  
  B11111,
  B01110,
  B00100,
  B00000,
  B11111,
  B01110,
  B00100
};

byte up_arrow[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
};

byte down_arrow[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, downdown);
  lcd.createChar(1, down);
  lcd.createChar(2, equal);
  lcd.createChar(3, up);
  lcd.createChar(4, upup);
  lcd.createChar(5, up_arrow);
  lcd.createChar(6, down_arrow);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  //lcd.write((byte)2);
  lcd.print("=");
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)6);
}

void loop() { }
