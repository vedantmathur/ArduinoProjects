#include <Servo.h>

int sevendigit[][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH},
};

//{LETTER, PIN},
int displayArray[][2] = {
  {0, 6},
  {1, 5},
  {2, 4},
  {3, 3},
  {4, 2},
  {5, 7},
  {6, 8}
};

struct Arm{
  void attach(Servo arm, int armPin){
    arm.attach(armPin);
  }
  
  void setArm(Servo arm, int degrees){
    arm.write(degrees);
  }
  
};


int lastButtonState = 0;
struct LEDDISPLAY{
  
  void numberDisplay(int c){
    for (int k = 0; k < 7; k++){ //LED
        digitalWrite(displayArray[k][1], sevendigit[c][k]);
    }
  }
  
  void blinkDisplay(int c){
    delay(500);
    for (int k = 0; k < 7; k++){ //LED
        digitalWrite(displayArray[k][1], LOW);
    }
    delay(500);
    numberDisplay(c);
  }

  int reduceOne(int c){
    if (c > 0)
    {
       c--; 
    } else
    {
      blinkDisplay(c);
    }
    numberDisplay(c);
    return c;
  }
  
};


Servo armR;
Servo armL;
int counter = 0;
int servoPos = 160;
int pot = A5;
int gate = 11;
int button = 13;

Arm servoArm;
LEDDISPLAY disp;

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 7; i++){
     pinMode(displayArray[i][1], OUTPUT);
  }
  

  pinMode(pot, INPUT);
  pinMode(gate, INPUT);
  pinMode(button, INPUT_PULLUP);

  servoArm.attach(armR, 10);
  servoArm.attach(armL, 12);
  
  //armR.attach(10);
  //armL.attach(9);

  armL.write(servoPos);
  armR.write(30);

  Serial.begin(9600);
}
int buttonState = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED, sd[NUMBER TO DISPLAY][ON OFF]); 
  buttonState = digitalRead(button);

  if (buttonState == 0 && lastButtonState == 1)
  {
    counter = disp.reduceOne(counter);
  }

  if (counter == 5)
  {
     if (digitalRead(gate) == 1){ 
        disp.blinkDisplay(counter);
     }
  } else if (counter < 5)
  {   
      if (digitalRead(gate) == 1)
      { 
        servoArm.setArm(armL, 90);
        delay(2000);
        servoArm.setArm(armL, 160);
        counter++;       
      }
  }

  //int convVal = map(potRead, 0, 1023, 10, 170);
  //servoArm.setArm(armR, analogRead(pot));

  disp.numberDisplay(counter);
  
  delay(30);
  Serial.println(digitalRead(button));
  lastButtonState = buttonState;
}
