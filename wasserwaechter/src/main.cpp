#include <Arduino.h>
#define dirPin 2
#define stepPin 3
long timer = 0;
long step1 = 5000;
long step2 = 35000;

void setup()
{
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the spinning direction CW/CCW:
  digitalWrite(dirPin, LOW);

  timer = 0;
}

void loop()
{
  if (timer < step1)
  {
    timer++;
    delayMicroseconds(1000);
    ; // start delay
  }
  else if (timer < (step1 + step2))
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
    timer++;
  }
  else
  {
    delayMicroseconds(1000);
  }
}