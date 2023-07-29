#include <Arduino.h>
#include <Stepper.h>
int val;
int ledpin = 12;
Stepper mystepp(100, 8, 9, 10, 11);

void setup()
{
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
  mystepp.setSpeed(100);
}

void loop()
{
  // put your main code here, to run repeatedly:

  val = Serial.read();
  if (val == 'R')
  {
    for (int i = 1; i <= 3; i++)
    {
      digitalWrite(ledpin, HIGH);
      delay(500);
      digitalWrite(ledpin, LOW);
      delay(500);
    }

    mystepp.step(1000);

    Serial.println("hello");
  }
}
