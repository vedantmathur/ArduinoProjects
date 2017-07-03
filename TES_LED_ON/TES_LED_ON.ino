
int led = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void fadeIn(int led, int delayT){
  for(int i = 0; i < 255; i++){
    analogWrite(led, i);
    delay(delayT);
  }
}

void pwm(int led, int count){
  while (count < 2000){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    count++;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int count = 0;
  fadeIn(led, 10);
  delay(500);
  //pwm(led, count);
  //digitalWrite(led, HIGH);
  
}
