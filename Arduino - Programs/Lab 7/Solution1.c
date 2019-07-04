/* Jordan O Donnell
 * 163711101
 * Lab_7 Basic Array Pointers
 *
 * Using pointers to the array to manipulate the value of the array elements to print out array elements and array slice
 */

#include <ee108.h>

//------------------------------------------------------------
// constants
//------------------------------------------------------------
#define ARRAY_SLICE_PARAM 3
#define DATA_LEN  6

const int SUPERLOOP_DELAY_MS = 50;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

void randomizeArray(int array[], int len, int minVal, int maxVal);
void printArray(const int array[], int len);


//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab7_BasicArraySubscripting starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() {
  // note: we don;t need to remember the element values in this
  // array from one execution of the loop function to the next
  int data[DATA_LEN] = { 0 }; // initialize array to all zeros
  long result;
  int index;

  
  if (readSwitchEvent(sw1Object) == SW_RELEASE_CLICK) { // was there a click?
  
    randomizeArray(data, DATA_LEN, 0, 99);
  
    Serial.println("  Array has been filled with random values");
    printArray(data, DATA_LEN);
    Serial.println("  Array slice 1..3");
    printArray(data+1, ARRAY_SLICE_PARAM);

    Serial.println("\nClick SW1 to restart\n");
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

/**
 * fill the array with random values
 *
 * @param array   the array to fill (an input/output parameter)
 * @param len     the lenght of the array
 * @param minVal  the minimum random value to fill with (inclusive)
 * @param maxVal  the maximum random value to fill with (inclusive)
 */
void randomizeArray(int *a, int len, int minVal, int maxVal) {
  int *p;
  
  for (p = a; p < a+len; p++)
  *p = random(minVal, maxVal + 1);
}

/**
 * pretty-print the contents of an array surrounded by braces
 *
 * @param array   the array to print (read only, so const)
 * @param len     the length of the array
 */
void printArray(int *a, int len) {
  int *p;
  
  Serial.print("  printArray { ");
  
  Serial.print(*a);

  for (p = a+1; p < a+len; p++) {
    Serial.print(", ");
    Serial.print(*p);
  }
  Serial.println(" }");
}

