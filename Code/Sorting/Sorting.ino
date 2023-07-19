#include <Servo.h>
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define motor 9
#define sensorOut 8


int state = 90;
// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
 
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  servomotor.attach(motor);
  servomotor.write(state);
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  // Set Pulse Width scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  // Setup Serial Monitor
  Serial.begin(9600);
}
 
void loop() {
  
  // Read Red Pulse Width
  redPW = getRedPW();
  delay(200);
  // Read Green Pulse Width
  greenPW = getGreenPW();
  delay(200);
  // Read Blue Pulse Width
  bluePW = getBluePW();
  delay(200);
  if(RedPw <= 11 && RedPw >= 11 && GreenPw <= 11 && GreenPw >= 11&& BluePw <= 11 && BluePw >= 11)
  {
    state = 180;
    servomotor.write(state);
    }
    if(RedPw <= 11 && RedPw >= 11 && GreenPw <= 11 && GreenPw >= 11&& BluePw <= 11 && BluePw >= 11)
  {
    state = 180;
    servomotor.write(state);
    }
}
// Function to read Red Pulse Widths
int getRedPW() {
  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  return PW;
}
int getGreenPW() {
  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
// Function to read Blue Pulse Widths
int getBluePW() {
  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}
