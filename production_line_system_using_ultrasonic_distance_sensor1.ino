#include <Servo.h>
Servo M1;

int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 12;
int echoPin2 = 13;

long x;
long y;

void setup()
{
  M1.attach(2);
  
  Serial.begin(9600);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  // Distance of each
  x= 0.01723 * readUltrasonicDistance(trigPin1, echoPin1);
  y= 0.01723 * readUltrasonicDistance(trigPin2, echoPin2);
  //Serial.println(x);
  
  // small size box is detected (100*100cm)
  if(x+y==500){M1.write(45);}
  // medium size box is detected (200*200cm)
  else if(x+y==400){M1.write(135);}
  // big size box is detected (300*300cm)
  else if(x+y==300){M1.write(90);}
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 1 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}