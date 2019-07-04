//16371101
//Jordan O Donnell
//Lab 2 (EE108R)
//Part 3 Cascaded If Statements
//02/10/2017

#include <ee108.h>

const int SUPERLOOP_DELAY_MS = 1000;
const int WRAP_VALUE = 10;

void setup() 
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  static int loopCounter = 0;

  Serial.print("counter = ");
  Serial.print(loopCounter);

  if((loopCounter < 2) || (loopCounter > 7))
  {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    Serial.println(", Both LEDs off");
  }
  else if((loopCounter == 2) || (loopCounter == 7))
  {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    Serial.println(", LED1 only");
  }
  else if((loopCounter == 3) || (loopCounter == 6))
  {
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    Serial.println(", LED2 only");
  }
  else if((loopCounter == 4) || (loopCounter == 5))
  {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    Serial.println(", Both LEDs on");
  }
else
  {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    Serial.println(", Both LEDs off");
 }
  loopCounter = (loopCounter+ 1) % WRAP_VALUE;

  delay(SUPERLOOP_DELAY_MS);
}
