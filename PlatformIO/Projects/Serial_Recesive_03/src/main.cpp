/*
 * Serial_Recesive_02 程序
 * 使LED闪烁的速度正比于所接受到的数字值
 * 本例 【串口接受的是多位的正数字符和负数字字符】
 */

// 串口监视器中需把line ending ： LF

#include <Arduino.h>
void blink();

// put function declarations here:
const int ledPin = 13;
int blinkRate = 0;
int value = 0;
int sign = 1;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();

    if (isdigit(ch))
      value = (value * 10) + (ch - '0');
    else if (ch == '-')
      sign = -1;

    else // 假定任何不是数字和减号的字符来结束数值
    {
      value = sign * value;
      blinkRate = value;
      Serial.println(blinkRate);
      value = 0;
      sign = 1;
    }
  }
  // put your main code here, to run repeatedly:
}

// put function definitions here:
void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(blinkRate);
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}