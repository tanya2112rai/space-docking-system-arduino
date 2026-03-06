#include <Servo.h>

Servo myServo;

int trig = 9;
int echo = 10;
int buzzer = 6;
int led = 7;

long duration;
int distance;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  myServo.attach(5);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if(distance < 20)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    myServo.write(90);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    myServo.write(0);
  }

  delay(500);
}
