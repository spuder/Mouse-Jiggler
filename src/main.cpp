// Digispark Mouse Jiggler
// Written by James Franklin for Air-Gap in 2019
// www.air-gap.com.au

// Modified by Kody Kinzie of Null Byte
// https://github.com/skickar/USBAttackWorkshop/blob/master/MouseJigglerBIG.ino

#include <Arduino.h>
#include <DigiMouse.h>

#define LED_PIN 1

// 24000 = 4 minutes
// 54000 = 9 mimutes
unsigned int LowerCycleTime = 24000; //Minimum Time in milli-seconds between each mouse action  Default: 10000 (10 Seconds), Max 65535ms
unsigned int UpperCycleTime = 54000; //Maximum Time in milli-seconds between each mouse action  Default: 30000 (30 Seconds), Max 65535ms
//Random Function will randomly execute a mouse move between these two values
void setup() {
  randomSeed(analogRead(0));  //Random Seed off background noise on analog pin
  pinMode(LED_PIN, OUTPUT); // LED (Note on some older digispark devices, the LED is on pin 0)
  DigiMouse.begin();
}
void loop() {
  digitalWrite(1, HIGH);
  DigiMouse.moveX(2); // Move 2 pixel right
  DigiMouse.moveX(-2); // Move 2 pixel left
  DigiMouse.delay(50);
  digitalWrite(LED_PIN, LOW);
  DigiMouse.delay(random(LowerCycleTime, UpperCycleTime));
}