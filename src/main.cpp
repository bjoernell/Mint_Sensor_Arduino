#include <Arduino.h>
#include <UsSen.h>
#include <BuzzSpeaker.h>

#define reUnTrig 13
#define reUnEch 12

#define liUnTrig 11
#define liUnEch 10

#define reObTrig 9
#define reObEch 8

#define liObTrig 6
#define liObEch 7

#define speakerPin 5

String reUnName = "ReUn";
String liUnName = "LiUn";
String reObName = "ReOb";
String liObName = "LiOb";

UltrasonicSensor UsLiOb(liObTrig, liObEch, liObName);
UltrasonicSensor UsReOb(reObTrig, reObEch, reObName);
UltrasonicSensor UsLiUn(liUnTrig, liUnEch, liUnName);
UltrasonicSensor UsReUn(reUnTrig, reUnEch, reUnName);

BuzzSpeaker MainSpeaker(speakerPin);

long duration;
int distance;

void usSenCheck()
{
  if (distance != 0)
  {
    Serial.println(distance);
  }
  if (distance < 100 && distance > 0)
  {
    MainSpeaker.playSound(2000, distance, 1);
    Serial.println(distance);
  }
  if (distance == 0)
  {
    Serial.println("timeout");
  }
}

void setup()
{
  Serial.begin(115200);
  MainSpeaker.playSound(2000, 20, 1);
}

void loop()
{
  UsReOb.distance();
  usSenCheck();
  UsLiOb.distance();
  usSenCheck();
  UsReUn.distance();
  usSenCheck();
  UsLiUn.distance();
  usSenCheck();
}
