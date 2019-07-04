//Part 4 Break Statement

#include <ee108.h>

const int BUTTON_POLL_MS = 50;

const int NUM_REPS = 10;
const int BETWEEN_REPS_MS = 500;

const int LED_ON_MS = 100;
const int LED_OFF_MS = 50;


void setup() {
  int ledNum;
  //Serial Monitor
  Serial.begin(9600); 
  Serial.println("============== starting Lab3_BarLedScan_Starter ============");  

  pinMode(SW1_PIN, INPUT);
  pinMode(LED1_PIN, INPUT);

  // iterate over all Bar LED pins, enabling each one as an OUTPUT
  for (ledNum = 0; ledNum < NUM_BAR_LEDS; ledNum++)
    pinMode(BAR_LED_1_PIN + ledNum, OUTPUT);
    
}

void loop() {
  int sw1Event; // used when checking SW1
  int sw2Event; // user when checking SW2
  int ledNum = 0; //Repetition Counter
  int ledNum1 = 0; //Random variable used in nested loop
  Serial.println("\nloop function starting -- click SW1 to begin");
  
  do 
  {
    delay(BUTTON_POLL_MS);
    sw1Event = readSwitchEvent(sw1Object);
  } 
  while (sw1Event != SW_RELEASE_CLICK);
  Serial.println("SW1 PIN has been clicked!");
  

  while(ledNum < NUM_REPS)
  {
    //Blink Led 1
    digitalWrite(BAR_LED_1_PIN, HIGH);
    delay(LED_ON_MS);
    digitalWrite(BAR_LED_1_PIN, LOW);
    delay(LED_OFF_MS);
    Serial.print("Repetition: ");
    Serial.println(ledNum);

    //If Switch 2 is pressed continue
    sw2Event = readSwitchEvent(sw2Object);
    if ((sw2Event == SW_PRESS) || (sw2Event == SW_KEEP_PRESSED)) 
    {
      continue;
    }

    //Loop through using nested loop swithing leds from 2-10 on and off
    for (ledNum1 = 0; ledNum1 < NUM_REPS; ledNum1++)
    {
      digitalWrite(BAR_LED_2_PIN + ledNum1, HIGH);
      delay(LED_ON_MS);
      digitalWrite(BAR_LED_2_PIN + ledNum1, LOW);
      delay(LED_OFF_MS);

      //If switch 1 is pressed break out of the loop 
      sw1Event = readSwitchEvent(sw1Object);
      if ((sw1Event == SW_PRESS) || (sw1Event == SW_KEEP_PRESSED)) 
      {
        break;
      }
      
    }
    //If the loop broke as a result of SW1 being pressed (value of ledNum will be less than NUM_REPS) then break out of loop
    if(ledNum1 < NUM_REPS)
    {
      break;
    }
    delay(BETWEEN_REPS_MS);
    ledNum++; //Increment Repetition counter every time the nested loop completes 
  }
    //If Switch 1 is pressed break out of the loop
    sw1Event = readSwitchEvent(sw1Object);
    if ((sw1Event == SW_PRESS) || (sw1Event == SW_KEEP_PRESSED)) 
    {
      Serial.println("release SW1");
    }
    //Wait until the button is released before printing loop function complete statement
    while (readSwitchEvent(sw1Object) != SW_OFF)
    {
      delay(BUTTON_POLL_MS);
    }
    Serial.println("loop function complete");  
}


