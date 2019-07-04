//16371101
//Jordan O Donnell
//Lab 3 (EE108R)
//Part 1 Bar Led Scan 1
//09/10/2017

#include <ee108.h>

const int BUTTON_POLL_MS = 50;

const int NUM_REPS = 10;
const int BETWEEN_REPS_MS = 500;

const int LED_ON_MS = 100;
const int LED_OFF_MS = 50;


void setup() {
  int ledNum;
  
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
  int ledNum = 0;
  Serial.println("\nloop function starting -- click SW1 to begin");
  
  do 
  {
    delay(BUTTON_POLL_MS);
    sw1Event = readSwitchEvent(sw1Object);
  } 
  while (sw1Event != SW_RELEASE_CLICK);
  Serial.println("SW1 PIN has been clicked!");
  

  for (ledNum = 0; ledNum < NUM_BAR_LEDS; ledNum++)
  {
    digitalWrite(BAR_LED_1_PIN, HIGH);
    delay(100);
    digitalWrite(BAR_LED_1_PIN, LOW);
    Serial.print("Repetition: ");
    Serial.println(ledNum);
    Serial.println("Placeholder - bar LED scan would go here");
    delay(BETWEEN_REPS_MS);
 
  Serial.println("loop function complete");  
}
}




	
