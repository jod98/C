#include <ee108.h>

int counter = 1; //Counter begins at value A
int ledIndex; //Variable Used to Initialise Bar Leds

const int T_DELAY = 200; //Unit T Time Delay
const int T_DELAY_TIMES_3 = 600; //Unit 3T Time Delay

void setupBarLeds(); //Function Declaration for Setting up Bar Leds
void ledOneTwo(); //Function Declaration for Flashing Leds 1 and 2 together
void ledSixTen(); //Function Declaration for Flashing Leds 6 - 10 together
void wrapValue(); //Wraps Value to allow E to return to A after incrementation
void wrapValueReverse(); //Wraps Value of A back to E after decrementation
void printingCounterAndLedSequence(); //Prints Value of Counter

const int WRAP_VALUE = 6;

void setup() 
{
  pinMode(SW1_PIN, INPUT);
  pinMode(SW2_PIN, INPUT);

  setupBarLeds();
  
  Serial.begin(9600);
}

void loop() 
{
  int sw1Event; //Checking SW1
  sw1Event = readSwitchEvent(sw1Object);

  int sw2Event; //Checking SW2
  sw2Event = readSwitchEvent(sw2Object);
  
  //Switch 1 normally clicked
  if(sw1Event == SW_RELEASE_CLICK)
  {
    //sw1Event = readSwitchEvent(sw1Object);
    Serial.print("Normal Click SW1 Value: ");
    Serial.println(sw1Event);
    printingCounterAndLedSequence();
  }

  //Switch 2 normally clicked
  if(sw2Event == SW_RELEASE_CLICK)
  {
    //sw2Event = readSwitchEvent(sw2Object);
    Serial.print("Normal Click SW2 Value: ");
    Serial.println(sw2Event);
    wrapValue();
    printingCounterAndLedSequence();
  }

  //Switch 2 long clicked || very long clicked
  if((sw2Event == SW_LONG_CLICK) || (sw2Event == SW_VERY_LONG_CLICK))
  {
    //sw2Event = readSwitchEvent(sw2Object);
    if(sw2Event == 24)
    {
      Serial.print("Long Click Value: ");
      Serial.println(sw2Event);
    }
    else
    {
      Serial.print("Very Long Click Value: ");
      Serial.println(sw2Event);
    }
    wrapValueReverse();
    printingCounterAndLedSequence();
  }
}

//Setting Up Bar Leds Function
void setupBarLeds()
{
  for(ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++)
  pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
}

//Flashing LED 1 AND 2 Together
void ledOneTwo()
{
  digitalWrite(BAR_LED_1_PIN, HIGH);
  digitalWrite(BAR_LED_2_PIN, HIGH);
  delay(T_DELAY);
  digitalWrite(BAR_LED_1_PIN, LOW);
  digitalWrite(BAR_LED_2_PIN, LOW);
}
//Flashing LED 6 - 10 TOGETHER
void ledSixTen()
{
  digitalWrite(BAR_LED_6_PIN, HIGH);
  digitalWrite(BAR_LED_7_PIN, HIGH);
  digitalWrite(BAR_LED_8_PIN, HIGH);
  digitalWrite(BAR_LED_9_PIN, HIGH);
  digitalWrite(BAR_LED_10_PIN, HIGH);
  delay(T_DELAY_TIMES_3);
  digitalWrite(BAR_LED_6_PIN, LOW);
  digitalWrite(BAR_LED_7_PIN, LOW);
  digitalWrite(BAR_LED_8_PIN, LOW);
  digitalWrite(BAR_LED_9_PIN, LOW);
  digitalWrite(BAR_LED_10_PIN, LOW);

}
void wrapValue() //Wraping Value as explained above in function declaration
{
  ++counter;
  if(counter>= WRAP_VALUE)
  counter = 1;
}

void wrapValueReverse()//Wraping Value as explained above in function declaration
{
  --counter;
  if(counter <= 0)
  counter = 5;
}

void printingCounterAndLedSequence() //Printing Counter Value and Setting Sequence
{
  if(counter == 1)
  {
    Serial.println("Sequence: A");
    ledOneTwo();
    delay(T_DELAY);
    ledSixTen();
  }
  else if(counter == 2)
  {
    Serial.println("Sequence: B");
    ledSixTen();
    delay(T_DELAY);
    ledOneTwo();
    delay(T_DELAY);
    ledOneTwo();
    delay(T_DELAY);
    ledOneTwo();
  }
  else if(counter == 3)
  {
    Serial.println("Sequence: C");
    ledSixTen();
    delay(T_DELAY);
    ledOneTwo();
    ledSixTen();
    delay(T_DELAY);
    ledOneTwo();
  }
  else if(counter == 4)
  {
    Serial.println("Sequence: D");
    ledSixTen();
    delay(T_DELAY);
    ledOneTwo();
    delay(T_DELAY);
    ledOneTwo();
  }
  else
  {
    Serial.println("Sequence: E");
    ledOneTwo();
  }
}
