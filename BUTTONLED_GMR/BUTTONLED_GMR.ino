int ledOrange = 9;
int ledGreen = 3;
int button = 2;

int inCount = 0;
int outCount = 255;

bool clickOne = false;
bool clickTwo = false;
unsigned long initTime = 0;
unsigned long finTime = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledOrange, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  
}

bool isPressed(int button){
  return digitalRead(button) == LOW;
}

void blinkDelays(int led, int delayTime){
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led, LOW);
  delay(delayTime);
}

void fadeIn(int led, int delayTime){
  for (int i = 0; i < 255; i++){
    analogWrite(led, i);
    delay(delayTime);
  }
}

void fadeOut(int led, int delayTime){
  for (int i = 255; i > 0; i--){
    analogWrite(led, i);
    delay(delayTime);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    fadeIn(ledOrange, 10);
    fadeIn(ledGreen, 10);
    //blinkDelays(ledGreen, 500);
    //blinkDelays(ledOrange, 500);
    delay(500);
    fadeOut(ledOrange, 10);
    fadeOut(ledGreen, 10);
/*
    if (inCount < 255){
      analogWrite(ledOrange, inCount);
      inCount++;
      delay(10);
    }
    else if (outCount > 0){
      analogWrite(ledOrange, outCount);
      outCount--;
      delay(10);
    }

    
    Serial.println(digitalRead(button));


    if (inCount == 255 && outCount == 0){
      inCount = 0;
      outCount = 255;
    }
    
    if (digitalRead(button) == 1){
      if (inCount < 255){
        analogWrite(ledOrange, inCount);
        analogWrite(ledGreen, inCount);
        inCount++;
        delay(10);
      }
      else if (outCount > 0){
        analogWrite(ledOrange, outCount);
        analogWrite(ledGreen, outCount);
        outCount--;
        delay(10);
      }
    } else if (digitalRead(button) == 0){
      digitalWrite(ledGreen, HIGH); 
    } else{
      digitalWrite(ledGreen, LOW);
    }
    */
/*
    if (digitalRead(button) == 0 && clickOne == false && clickTwo == false)
    {
      clickOne = true;
      initTime = millis();
      delay(200);
    } 
    else if (digitalRead(button) == 0 && clickOne == true && clickTwo == false)
    {
      clickTwo = true;
      finTime = millis();
      delay(200);
      
      if ((finTime - initTime) < 500)
      {
        digitalWrite(ledGreen, HIGH);
      } 
    }
    else if((finTime - initTime) > 500)
    {
      clickOne = false;
      clickTwo = false;  
    }

    Serial.println(digitalRead(button)); */
}


