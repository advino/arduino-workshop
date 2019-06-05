//Final Project: Arduino + Processing Sequencer

int pot1 =  A0;
int pot2 = A2;
int pot3 = A4;



void setup() {
  // put your setup code here, to run once:
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(pot3,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int potRead1 = analogRead(pot1);
  int potRead2 = analogRead(pot2);
  int potRead3 = analogRead(pot3);

  Serial.print(potRead1);
  Serial.print(",");
  Serial.print(potRead2);
  Serial.print(",");
  Serial.print(potRead3);
  Serial.println();

  delay(100);

}
