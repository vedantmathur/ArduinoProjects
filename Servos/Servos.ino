#include <Servo.h>

Servo armR;
Servo armL;
int servoPos = 160;
int pot = A5;

void setup() {
  // put your setup code here, to run once:

  pinMode(pot, INPUT);
  
  armR.attach(10);
  armL.attach(9);

  armL.write(servoPos);
  armR.write(30);
}

void setArm(Servo arm, int potRead){
  int convVal = map(potRead, 0, 1023, 10, 170);
  arm.write(convVal);
}

void loop() {
  // put your main code here, to run repeatedly:

  setArm(armL, analogRead(pot));
  setArm(armR, analogRead(pot));
  
}
