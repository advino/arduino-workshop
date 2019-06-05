//Example 2: Pulsing an LED
const int led = 11;
int brightness = 1;
int fade = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse();
}

void pulse() {
   if (brightness >= 255 || brightness <= 0) {
    fade = -fade;
  }
  
  brightness = brightness + fade;
  
  analogWrite(led, brightness);
  
  delay(1);
}

void blinking() {
  analogWrite(led,255);
  delay(100);
  analogWrite(led,0);
  delay(100); 
}


