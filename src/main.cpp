// Digispark Mouse Jiggler
// Written by James Franklin for Air-Gap in 2019
// www.air-gap.com.au

// Modified by Kody Kinzie of Null Byte
// https://github.com/skickar/USBAttackWorkshop/blob/master/MouseJigglerBIG.ino

#include <Arduino.h>
#include <DigiMouse.h>
             
#define LED_PIN 1
unsigned int LowerCycleTime = 10000; //Minimum Time in milli-seconds between each mouse action  Default: 10000 (10 Seconds), Max 65535ms
unsigned int UpperCycleTime = 30000; //Maximum Time in milli-seconds between each mouse action  Default: 30000 (30 Seconds), Max 65535ms
//Random Function will randomly execute a mouse move between these two values
void setup() {
  randomSeed(analogRead(0));  //Random Seed off background noise on analog pin
  pinMode(1, OUTPUT);
  DigiMouse.init();
}
void loop() {
//Moves mouse 1 pixel in a direction (up/down/left/right) in a square
  digitalWrite(1, HIGH);
  DigiMouse.moveY(2);
  DigiMouse.delay(50);

  DigiMouse.moveX(2); //s
  DigiMouse.delay(50);

  DigiMouse.moveY(-2);
  DigiMouse.delay(50);

  DigiMouse.moveX(-2);
  DigiMouse.delay(50);
  
  digitalWrite(1, LOW);
  DigiMouse.delay(1000);

}