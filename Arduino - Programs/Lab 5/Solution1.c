//16371101
//Jordan O Donnell
//Lab 5 (EE108R)
//Part 1 Basic Arrays
//13/11/2017

#include <ee108.h>

//Global Variables
#define ARRAY_SIZE 8 //Declaring Array Size as 8
const int SUPERLOOP_MS = 20; //Delay 
const int RANDOM_VALUE = 100; //Variable used as random number betweem 0-99 inclusive
const int ZER0_ELEMENT_ARRAY = 0; //Variable used to declare array of '0' elements
int i; //Variable used in for loop to output array of '0' elements
int j; //Variable used in for loop to output array of random elements

void setup() 
{
  Serial.begin(9600);
  Serial.println("Lab5_BasicArray starting...");
}

void loop() 
{
  static int arr[ARRAY_SIZE] = {ZER0_ELEMENT_ARRAY}; //Array Elements are remembered during function calls

  int sw1Event; 
  sw1Event = readSwitchEvent(sw1Object); //Assigning variable sw1Event to current condition of sw1 i.e. clicked, pressed, not clicked

  //if current condition of sw1 is a release click do the following...
  if(sw1Event == SW_RELEASE_CLICK) 
  {
    Serial.println(""); 
    Serial.print("[Click] array is { ");
    for(i = 0; i<ARRAY_SIZE-1; i++)
    {
      Serial.print(arr[i]);
      Serial.print(", ");
    }
    Serial.print(arr[ARRAY_SIZE-1]);
    Serial.print(" }");
  }
  
  //if current condition of sw1 is a long click or very long click do the following...
  else if((sw1Event == SW_LONG_CLICK) 
    || (sw1Event == SW_VERY_LONG_CLICK)) 
  {
    Serial.println("");
    Serial.print("[LongClick] modified array { ");
    for(j = 0; j<ARRAY_SIZE-1; j++)
    {
      arr[j] = random(RANDOM_VALUE); //Assigning value of array elements to a random number between 0-99 inclusive
      Serial.print(arr[j]);
      Serial.print(", ");
    }
    arr[ARRAY_SIZE-1] = random(RANDOM_VALUE); 
    Serial.print(arr[ARRAY_SIZE-1]);
    Serial.print(" }");
  }
  delay(SUPERLOOP_MS);
}

