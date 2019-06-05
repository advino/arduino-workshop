import ddf.minim.*;
import ddf.minim.ugens.*;
import processing.serial.*;


Minim minim;
AudioOutput out;
Serial myPort;
String myString;
int[] sensorValues;


String[] notes = {"C4","D4","E4","F4","G4","A4","B4","C5"};
int[] keys = {0,0,0};
int count;


void setup() {
  size(600,100);
  minim = new Minim(this);
  out = minim.getLineOut();
    
  out.setTempo(150);
  count = 0;
  
  setupSerial();
}

void draw() {
 background(0);
 updateSerial();
 
 keys[0] = sensorValues[0];
 keys[1] = sensorValues[1];
 keys[2] = sensorValues[2];
 
 int currentNote = keys[count];
 
 out.playNote(2.0,1.0,notes[currentNote]);
 
 if(count < 2) {
  count++; 
 } else {
  count = 0; 
 }
 
 delay(300);
}


void setupSerial() {
 myPort = new Serial(this,Serial.list()[1],9600);
 myPort.clear();
 myString = myPort.readStringUntil(10);
 myString = null;
 
 sensorValues = new int[3];
}

void updateSerial() {
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(10);
    if (myString != null) {
      String[] serialInArray = split(trim(myString), ",");
      if (serialInArray.length == 3) {
        for (int i=0; i<serialInArray.length; i++) {
          sensorValues[i] = int(map(int(serialInArray[i]),0,1023,0,7));
        }
      }
    }
  }
}
