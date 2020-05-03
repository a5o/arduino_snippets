#include <Servo.h>
Servo servo1;


int move_servo(Servo servo,float min_angle,float max_angle, float min_val, float max_val, float value, bool reverse){
   float range_angle = max_angle-min_angle+1;
   float range_vals = max_val-min_val+1;
   int angle = (value-min_val)/range_vals*range_angle+min_angle;
   if (reverse == true) {
    angle = max_angle-angle;
   }
   servo.write(angle);
   return (value);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  float values[] = {-3,-2,-1,0,1,2,3,3};
  for (int i = 0;i<8;i++) {
    int a = move_servo(servo1,2.0,178.0, -3, 3, values[i], true);
    Serial.println(a);
    delay(5000);
  }
}
