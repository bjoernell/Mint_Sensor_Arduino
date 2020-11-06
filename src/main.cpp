#include <Arduino.h>
#include <UsSen.h>

#define reUnTrig    13
#define reUnEch     12

#define liUnTrig    11
#define liUnEch     10

#define reObTrig    9
#define reObEch     8

#define liObTrig    6
#define liObEch     7

#define speakerPin  5

String reUnName = "ReUn";
String liUnName = "LiUn";
String reObName = "ReOb";
String liObName = "LiOb";

long duration;
int distance; 



void SpeakerWarning(int repitition, int duration){
  for(int i; i <= repitition; i++){
    tone(speakerPin, 2000, duration);
    noTone(speakerPin);
  }
}

UltrasonicSensor UsLiOb(liObTrig, liObEch, liObName);
UltrasonicSensor UsReOb(reObTrig, reObEch, reObName);
UltrasonicSensor UsLiUn(liUnTrig, liUnEch, liUnName);
UltrasonicSensor UsReUn(reUnTrig, reUnEch, reUnName);

void setup() {
  Serial.begin(115200); 
  
  SpeakerWarning(2, 50);
}

void loop(){
  UsReOb.distance();
  UsLiOb.distance();
  UsReUn.distance();
  UsLiUn.distance();
}