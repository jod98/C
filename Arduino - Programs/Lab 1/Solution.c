//16371101
//Jordan O Donnell
//Lab 1 (EE108R)
//Part 3 Blink Daughterboard Section
//25/09/2017

# include <ee108.h>

const int PIN_TO_USE = BAR_LED_5_PIN; // the pin to use
const int ON_TIME_IN_MS = 0; // the on-time in ms during each blink
const int OFF_TIME_IN_MS = 20; // the off-time in ms during each blink
const int MICROSECOND_ON_TIME_CONTROL = 70; // the on-time control

// the setup function runs once when you press reset or power the board

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(PIN_TO_USE, OUTPUT);
}

// the loop function runs over and over again forever

void loop() 
{
  digitalWrite(PIN_TO_USE, HIGH );   // turn the LED on (HIGH is the voltage level)
  delay(ON_TIME_IN_MS); // wait for a second
  delayMicroseconds (MICROSECOND_ON_TIME_CONTROL);
  digitalWrite(PIN_TO_USE, LOW);    // turn the LED off by making the voltage LOW
  delay(OFF_TIME_IN_MS);  // wait for a second
}

/**
* In this final portion of the lab, you’ll develop a programme to print the time in milliseconds (since
the Arduino board was last reset) and the value of a global, static, and local variable to serial
output, once every 2 seconds
*/

const unsigned long SUPERLOOP_MS = 2000;

int gLoopNumber = 0;

void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
 static int localLoopNumber = 0;
 int loopTracker = 0;
 int millisSeconds = millis();
 
 Serial.print(millisSeconds);
 Serial.print(" ms: gLoopNumber = ");
 Serial.print(gLoopNumber);
 Serial.print(", localLoopNumber = ");
 Serial.print(localLoopNumber);
 Serial.print(", loopTracker = ");
 Serial.println(loopTracker);
 
 gLoopNumber++;
 localLoopNumber++;
 loopTracker++;
 
 delay(SUPERLOOP_MS);
}