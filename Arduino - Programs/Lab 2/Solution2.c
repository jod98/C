//16371101
//Jordan O Donnell
//Lab 2 (EE108R)
//Part 2 Tutorial Starter
//02/10/2017

#include <ee108.h>


const int SUPERLOOP_MS = 1000;
const int LED_ON_MS = 50;
const int NUM_LEDS = 5;
const int WRAP_VALUE = 4;

void setup() {
  // initialize 5 bar LEDs
  pinMode(BAR_LED_1_PIN, OUTPUT);
  pinMode(BAR_LED_2_PIN, OUTPUT);
  pinMode(BAR_LED_3_PIN, OUTPUT);
  pinMode(BAR_LED_4_PIN, OUTPUT);
  pinMode(BAR_LED_5_PIN, OUTPUT);
}

void loop() {
  // this variable tracks which Bar LED we want to light
  static int ledNum = 0;

  // flash the LED on briefly and then switch it off again
  digitalWrite(BAR_LED_1_PIN + ledNum, HIGH);
  delay(LED_ON_MS);
  digitalWrite(BAR_LED_1_PIN + ledNum, LOW);

  // TODO - increment the counter and wrap if necessary
  /* ++ledNum;
  if(ledNum >= WRAP_VALUE)
    ledNum = 0; */

  ledNum = (ledNum + 1) % WRAP_VALUE; //Using mod operator to perform same tas
  // pause between LED flashes
  delay(SUPERLOOP_MS);
}

