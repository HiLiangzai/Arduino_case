/*
 * Serial_Recesive_02 程序
 * 使LED闪烁的速度正比于所接受到的数字值
 * 本例 【串口接受的是多位的数字字符】
 */
#include <Arduino.h>
void blink();
const int ledPin = 13; // 连接到LED引脚
int blinkRate = 0;     // 闪烁
int value;             // 在Arduino语言开发中，如果你声明一个int类型的变量并没有显式地给它赋初值，系统会默认将该变量初始化为0。

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (Serial.available()) // 检查是否至少有一个可用字符
  {
    char ch = Serial.read();

    /*if (isDigit(ch))语句是将每个数字字符转换成数字值后逐步构建最终的整数值。
    输入以字符123为例，转换为数字值123：
    value = 0，ch = 1， value = 1；
    value = 1，ch = 2，value = 12；
    value = 12， ch =3，value =123；*/

    if (isDigit(ch)) // 这是一个介于0和9之间的ASII数字吗？
    {
      value = (value * 10) + (ch - '0');
    }
    else if (ch == 10) // 这个是换行符吗
    {
      blinkRate = value;
      Serial.print("blinkRate:");
      Serial.println(blinkRate);
      value = 0;
    }
  }
  //Serial.print("blinkRate:");
  //Serial.println(blinkRate);
  blink();
}
void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(blinkRate);
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}