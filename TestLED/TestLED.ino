const int nickBurger = 11;
int brightness = 1;
int count = 1;


void setup() {
  pinMode(nickBurger,OUTPUT);
    
}


void loop() {

  if(brightness >= 255 || brightness <= 0) {
    count = -count;
  }

  brightness = brightness + count;

  analogWrite(nickBurger,brightness);

  delay(1);
  
}

