//16371101
//Jordan O Donnell
//Lab 5 (EE108R)
//Part 2 Basic Arrays
//13/11/2017

#include <ee108.h>

//Global Variables
#define ARRAY_SIZE 8 //Declaring Array Size as 8
const int ARRAY_PARAMETER_SIZE = 8; //Variable passed in as a parameter to the functions to aid in the printing out of array elements
const int ZER0_ELEMENT_ARRAY = 0; //Variable used to declare array of '0' elements
const int SUPERLOOP_MS = 20;
int i; //Variable used in for loop to output array of '0' elements
int j; //Variable used in for loop to output array of random elements
int randomLowValueRange = 0; //Variable used as random number low range
int randomHighValueRange = 99; //Variable used as random number high range

//Function Declarations
void printArray(int i, int arr[], int ARRAY_PARAMETER_SIZE);
void randomizeArrayValues(int j, int arr[], int ARRAY_PARAMETER_SIZE);

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
    printArray(i, arr, ARRAY_SIZE);
    Serial.print(arr[ARRAY_SIZE-1]);
    Serial.print(" }");
  }
  
  //if current condition of sw1 is a long click or very long click do the following...
  else if((sw1Event == SW_LONG_CLICK) || (sw1Event == SW_VERY_LONG_CLICK)) 
  {
    Serial.println("");
    Serial.print("[LongClick] modified array { ");
    randomizeArrayValues(j, arr, ARRAY_PARAMETER_SIZE, randomLowValueRange, randomHighValueRange);
    arr[ARRAY_SIZE-1] = random(randomLowValueRange, randomHighValueRange); 
    Serial.print(arr[ARRAY_SIZE-1]);
    Serial.print(" }");
  }
}

void printArray(int i, int arr[], int ARRAY_PARAMETER_SIZE)
{
    for(i = 0; i<ARRAY_PARAMETER_SIZE-1; i++)
    {
      Serial.print(arr[i]);
      Serial.print(", ");
    }
 }

 void randomizeArrayValues(int j, int arr[], int ARRAY_PARAMETER_SIZE, int randomLowRange, int randomHighRange)
 {
  for(j = 0; j<ARRAY_PARAMETER_SIZE-1; j++)
    {
      arr[j] = random(randomLowValueRange, randomHighValueRange); //Assigning value of array elements to a random number between 0-99 inclusive
      Serial.print(arr[j]);
      Serial.print(", ");
    }
   delay(SUPERLOOP_MS);
 }

