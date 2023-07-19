#define right 7
#define left 6
#define sp 3
void setup() {
  // put your setup code here, to run once:
pinMode(right,OUTPUT);
pinMode(left,OUTPUT);
pinMode(sp,OUTPUT);
analogWrite(sp,100);
digitalWrite(right,0);
digitalWrite(left,1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
