# Arduino Snippets
Arduino related stuff

## servo\_custom\_scale

Implements a function to move a servo on a defined angle range using a custom scale

    int move_servo(Servo servo,float min_angle,float max_angle, float min_val, float max_val, float value, bool reverse)

### arguments

 - servo: a Servo instance (see Servo.h)
 - min\_angle: minimum servo angle
 - max\_angle: maximum servo angle
 - min\_val: minimum value on the custom scale
 - max\_val: maximum value on the custom scale
 - value: value on the custom scale to move the servo to
 - reverse: reverse movement
 
## TM1637Display\_distance\_SR04

Display a distance detected with SR04 sonar on a TM1637 display.