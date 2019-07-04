/* Jordan O Donnell
 * 16371101
 * Lab7_ Update Array Pointer Arithmetic
 *
 * Using pointers to maipulate an array element using a random generator to identify which index of the array to change
 */
#include <ee108.h>

//Constants
const int SUPERLOOP_DELAY_MS = 50;
const int LEN = 10;

//Function Declarations
void updateElement(int *p);
void printArray(int *a, int len);


void setup() 
{
  Serial.begin(9600);
  Serial.println("Lab7_UpdateArrayPointerArithmetic starting...");
  Serial.println("Click SW1 to start/restart\n");   
}

void loop() 
{
  static int arr[LEN] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};

  if (readSwitchEvent(sw1Object) == SW_RELEASE_CLICK) 
  {
    //Printing Array Contents before Manipulation
    Serial.print("Initial data array contents: { ");
    printArray(arr, LEN);

    //Randomised Array Index
    Serial.print("Chosen offset into array was ");
    int randElement = random(0, LEN-2);
    Serial.println(randElement);

    //Update Element and Printing Manipulated Array
    Serial.print("Modified data array contents: { ");
    updateElement(&arr[randElement]);
    printArray(arr, LEN);

    Serial.println("\nClick SW1 to restart\n");
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//Function
void updateElement(int *p)
{
  *p = *(p+1)+1;
}

void printArray(int *a, int len) 
{
  int *p;
  
  Serial.print(*a);

  for (p = a+1; p < a+LEN; p++) 
  {
    Serial.print(", ");
    Serial.print(*p);
  }
  Serial.println(" }");
}
