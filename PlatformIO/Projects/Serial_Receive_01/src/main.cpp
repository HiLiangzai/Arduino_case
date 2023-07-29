/*
  * Serial_Receive 程序
  * 使LED闪烁的速度正比于所接受的数字值
*/
#include <Arduino.h>

// put function declarations here:
void blink();

const int ledPin = 13; // 连接LED的引脚
int blinkRate = 0;  // 闪烁速率存在这个变量

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // 初始化端口以9600波特发送和接受
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) // 检查是否至少有一个可用字符
  {
    char ch = Serial.read();
    if(isdigit(ch)) // 这是一个介于0和9之间的ASII数字吗
    {
      blinkRate = (ch - '0'); //ASII值转换为数字值
      blinkRate *= 100; // 实际速率为100ms乘以接受的数字值
    }
    Serial.println("Success!");
  }
  blink();
}

// put function definitions here:
//按BlinkRate确定的时间开启和关闭LED使之闪烁
void blink(){
  digitalWrite(ledPin, HIGH);
  delay(blinkRate); // 延迟取决于BlinkRate值
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}
