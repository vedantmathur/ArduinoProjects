int pot = A5;
int button = 2;
int ledR = 9;
int ledG = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode (ledR, OUTPUT);
  pinMode (ledG, OUTPUT);
  pinMode (button, INPUT_PULLUP);
  pinMode (pot, INPUT);

  digitalWrite(ledR, HIGH);

  Serial.begin(9600);
}

void fade(int led, int reader){
  reader /= 4;
  analogWrite(led, reader);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(button));

  int readingPot = analogRead(pot);
  
  fade(ledG, readingPot);
}
