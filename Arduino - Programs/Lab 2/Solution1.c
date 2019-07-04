//16371101
//Jordan O Donnell
//Lab 2 (EE108R)
//Part 1 NestedIfStatements
//02/10/2017

#include <ee108.h>

const int SUPERLOOP_DELAY_MS = 100;
const int REPETITION_VALUE = 15;

void setup() 
{
  pinMode(SW1_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() 
{
  static int localLoopNumber = 0;
  
  if(digitalRead(SW1_PIN) == SW_ACTIVE)
  {
    digitalWrite(LED1_PIN, HIGH);
    delay(SUPERLOOP_DELAY_MS); //This sets a delay of 100ms in the loop so it increments until it hits over 1500ms then LED2 is set to HIGH.
    localLoopNumber++; //Increments loop until it hits 1500ms
      if(localLoopNumber >= REPETITION_VALUE)// If loop repetitions reaches over 15 (reaches over 1500 ms) then sets LED2 to HIGH.
      {
        digitalWrite(LED2_PIN, HIGH);
      }
  }
  if(digitalRead(SW1_PIN) == SW_INACTIVE)
  {
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED1_PIN, LOW);
    localLoopNumber = 0;
  }
}