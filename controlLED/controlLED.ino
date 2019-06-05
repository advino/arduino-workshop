const int led = 11;
int pot = A0;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potRead = analogRead(pot);
  Serial.println(potRead);

  controlBlink(potRead);
}

void controlBlink(int _read) {
  
  analogWrite(led,255);
  delay(_read);
  analogWrite(led,0);
  delay(_read);
}


void controlFade(int _read) {
  analogWrite(led,_read);
}

