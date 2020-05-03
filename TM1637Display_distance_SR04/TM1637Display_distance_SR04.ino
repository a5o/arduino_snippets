#include <TM1637Display.h>
#include "SR04.h"

// connections pins:
#define CLK 2
#define DIO 3
#define TRIG_PIN 7
#define ECHO_PIN 6

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

// Ultrasonic sensor
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

void setup() {
  Serial.begin(9600);
  display.clear();
  display.setBrightness(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  long dist=sr04.Distance();
  Serial.print(dist);
  Serial.println(" cm"); 
  display.showNumberDec(dist);   
  delay(500);
}
