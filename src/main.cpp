#include <Arduino.h>

#define ReUnTrig  13
#define ReUnEch   12

#define LiUnTrig  11
#define LiUnEch   10

#define ReObTrig  9
#define ReObEch   8

#define LiObTrig  6
#define LiObEch   7

#define Speaker   5

String ReUnName = "ReUn";
String LiUnName = "LiUn";
String ReObName = "ReOb";
String LiObName = "LiOb";

long duration;
int distance; 

void UsMessung(int UsSenTrigVal, int UsSenEchVal, String UsSenName) {
  
  digitalWrite(UsSenTrigVal, LOW);
  delayMicroseconds(2);
  
  digitalWrite(UsSenTrigVal, HIGH);
  delayMicroseconds(10);
  digitalWrite(UsSenTrigVal, LOW);
  
  duration = pulseIn(UsSenEchVal, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print(UsSenName + distance + "cm");
}

void SpeakerWarning(int repitition){
  for(int i; i <= repitition; i++){
    digitalWrite(Speaker, HIGH);
    delay(50);
    digitalWrite(Speaker, LOW);
    delay(50);
  }
}


void setup() {
  pinMode(ReUnTrig, OUTPUT);
  pinMode(ReUnEch, INPUT); 

  pinMode(LiUnTrig, OUTPUT);
  pinMode(LiUnEch, INPUT); 

  pinMode(ReObTrig, OUTPUT);
  pinMode(ReObEch, INPUT); 

  pinMode(LiObTrig, OUTPUT);
  pinMode(LiObEch, INPUT); 

  pinMode(Speaker, OUTPUT);

  Serial.begin(115200); 

  SpeakerWarning(2);
}

void loop(){
 UsMessung(ReObTrig, ReUnEch, ReObName);
 UsMessung(LiObTrig, LiObEch, LiObName);
 UsMessung(ReUnTrig, ReUnEch, ReUnName);
 UsMessung(LiUnTrig, LiUnEch, LiUnName);
}