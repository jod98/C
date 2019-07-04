//16371101
//Jordan O Donnell
//Lab 4 (EE108R)
//Part 2 Blink Functions
//17/10/2017


#include <ee108.h>

// constants
void setupBarLeds(); //Function Declaration
int ledNum;
int onTime;
int offTime;
int repeatBlink;
void blinkBarLed(int ledNum, int onTime, int offTime, int repeatBlink);
const int SHORT_ON_MS = 100;
const int SHORT_OFF_MS = 500;
const int MED_ON_MS = 500;
const int MED_OFF_MS = 700;
const int LONG_ON_MS = 1200;
const int LONG_OFF_MS = 600;
int ledIndex;

void setup() {
  // set up the LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // set up the Bar LEDs (Function Call)
  setupBarLeds();
  
  // serial output
  Serial.begin(9600);

  Serial.println("====== Lab4_BlinkNoFunctions starting ========");
}

void loop() 
{
  static int loopNum = 0;
  int i;

  Serial.print("Loop ");
  Serial.println(loopNum);

  // BarLED1
  Serial.println("  Blink BarLED1 on/off long pattern x 1");
  blinkBarLed(1, LONG_ON_MS, LONG_OFF_MS, 1); //Function Call to blinkBarLed

  // BarLED8
  Serial.println("  Blink BarLED8 on/off short pattern x 3 times");
  blinkBarLed(8, SHORT_ON_MS, SHORT_OFF_MS, 3); //Function Call to blinkBarLed
  
  // BarLED4
  Serial.println("  Blink BarLED4 on/off short pattern x 2 times");
  blinkBarLed(4, MED_ON_MS, MED_OFF_MS, 2); //Function Call to blinkBarLed

  loopNum++;
}
  //Function Definition
  void setupBarLeds()
  {
    for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++) // Defining the setupBarLed function.
    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  }

  //Function Definition
  void blinkBarLed(int ledNum, int onTime, int offTime, int repeatBlink) 
  {
    for(int i=0; i<repeatBlink; i++)
    {
      digitalWrite(BAR_LED_1_PIN + ledNum - 1, HIGH); //We -1 from ledNum as bar leds will begin at 1
      delay(onTime);
      digitalWrite(BAR_LED_1_PIN + ledNum - 1, LOW);
      delay(offTime);
    }
  }

  // there are plenty of delays in the blinking code so we don't
  // need to add any extra delay at the end of the loop function
