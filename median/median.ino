
float values[5] = {5.0,0.1,2.1,3.0,7.0};

float cmpfunc (const void * a, const void * b) {
   return ( *(float*)a - *(float*)b );
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  qsort(values,5,sizeof(float),cmpfunc);
  Serial.println(values[5/2]);
  delay(10000);
}
