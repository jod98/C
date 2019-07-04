/*
 * 16371101
 * Jordan O Donnell
 * Part 1: RectOutputParams
 */

#include <ee108.h>
#include <ee108_switches.h>

//Global Variables:
const int SUPERLOOP_MS = 20;

//Function Declarations
void rectangle(int length, int width, int *pArea, int *pPerimeter); // TODO - will need to be modified

void setup() 
{
  Serial.begin(9600);
  Serial.println("========= Lab6_RectOutputParams starting ===========");
  Serial.println("Press SW2 to start...");
}

void loop() 
{
  int sw2Event;
  int length;
  int width;
  int area;
  int perimeter;

  //Detects whether SW2 has been clicked
  sw2Event = readSwitchEvent(sw2Object);

  if (sw2Event == SW_RELEASE_CLICK) 
  {
    //Setting random values for length and width between the range of 0-99 inclusive
    length = random(0,100); 
    width = random(0,100);

    //Function Call
    rectangle(length, width, &area, &perimeter);
    
    Serial.print("Rectange: length ");
    Serial.print(length);
    Serial.print(", width ");
    Serial.print(width);

    Serial.print(" => area ");
    Serial.print(area);
    Serial.print(", perimeter ");
    Serial.print(perimeter);
    
    Serial.println(""); // newline on its own

    Serial.println("\nPress SW1 to do it again...");
  }
  
  delay(SUPERLOOP_MS);
}

//Function Defintion
void rectangle(int length, int width, int *pArea, int *pPerimeter) 
{
  *pArea = length*width;
  *pPerimeter = (length * 2) + (width * 2);
}

