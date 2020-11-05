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

class UltraSonicSensor
{
  private:
    int echoPin, trigPin;

  public:
    UltraSonicSensor(/* args */);
    UltraSonicSensor();
  }
};
 UltraSonicSensor: UltraSonicSensor(/* args */)
{
 UltraSonicSensor:: UltraSonicSensor()
{
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

void SpeakerWarning(int repitition, int duration){
  for(int i; i <= repitition; i++){
    tone(speakerPin, 2000, duration);
    noTone(speakerPin);
  }
}


void setup() {
  pinMode(reUnTrig, OUTPUT);
  pinMode(reUnEch, INPUT); 

  pinMode(liUnTrig, OUTPUT);
  pinMode(liUnEch, INPUT); 

  pinMode(reObTrig, OUTPUT);
  pinMode(reObEch, INPUT); 

  pinMode(liObTrig, OUTPUT);
  pinMode(liObEch, INPUT); 

  pinMode(speakerPin, OUTPUT);

  Serial.begin(115200); 

  SpeakerWarning(speakerPin, 50);
}

void loop(){
 UsMessung(reObTrig, reUnEch, reObName);
 UsMessung(liObTrig, liObEch, liObName);
 UsMessung(reUnTrig, reUnEch, reUnName);
 UsMessung(liUnTrig, liUnEch, liUnName);
}