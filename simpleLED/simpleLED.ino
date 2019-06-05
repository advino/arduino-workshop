//Example 1: Turning on an LED
const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
}
