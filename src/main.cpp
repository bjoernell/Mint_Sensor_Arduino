#include <Arduino.h>

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

class UltrasonicSensor
{
private:
  
public:
  void SettingPinMode(int pinTrig, int pinEch){
    pinMode(pinTrig, OUTPUT);
    pinMode(pinEch, INPUT); 
  }
  
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

  UltrasonicSensor(/* args */);
  ~UltrasonicSensor();
};

void SpeakerWarning(int repitition, int duration){
  for(int i; i <= repitition; i++){
    tone(speakerPin, 2000, duration);
    noTone(speakerPin);
  }
}

UltrasonicSensor UsLiOb;
UltrasonicSensor UsReOb;
UltrasonicSensor UsLiUn;
UltrasonicSensor UsReUn;

void setup() {
  Serial.begin(115200); 
  
  SpeakerWarning(speakerPin, 50);
  
  UsLiOb.SettingPinMode(liObTrig, liObEch);
  UsReOb.SettingPinMode(reObTrig, reObEch);
  UsLiUn.SettingPinMode(liUnTrig, liUnEch);
  UsReUn.SettingPinMode(reUnTrig, reUnEch);
}

void loop(){
  UsReOb.UsMessung(reObTrig, reUnEch, reObName);
  UsLiOb.UsMessung(liObTrig, liObEch, liObName);
  UsReUn.UsMessung(reUnTrig, reUnEch, reUnName);
  UsLiUn.UsMessung(liUnTrig, liUnEch, liUnName);
}