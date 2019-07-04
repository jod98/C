/*
 * 16371101
 * Jordan O Donnell
 * Part 2: AnalogInoutAndFifo
 */

#include <ee108.h>
#include <limits.h>

const int SAMPLE_MS = 250;
const int ANALOG_PIN = LDR_PIN;
const int SUPERLOOP_MS = 8000;
const int NUM_SAMPLES = 8;
const int FIFO_LEN = 4;
static int arr[FIFO_LEN];

int sampleAnalogIn(int pin, int *pMinV, int *pMaxV);
int addToFifoAndAverage(int value, int arr[], int FIFO_LEN);
void printArray(int arr[], int FIFO_LEN);


void setup() {
  Serial.begin(9600);
  Serial.println("========= Lab6_OptionalInOut starting ===========");
}

void loop() 
{
 int i;
 static int maxValue = INT_MIN;
 static int minValue = INT_MAX;

  Serial.println("-----------");
  
  Serial.println("sample with no optional params...");
  
  for (i = 0; i < NUM_SAMPLES; i++) {
    int value = sampleAnalogIn(ANALOG_PIN, NULL, NULL);
    
    Serial.print("Sample ");
    Serial.print(i+1);
    Serial.print(", value=");
    Serial.println(value);

    delay(SAMPLE_MS);
  }

  Serial.println("sample with optional params...");
  for (i = 0; i < NUM_SAMPLES; i++) 
  {
    int value = sampleAnalogIn(ANALOG_PIN, &minValue, &maxValue); 
    int average = addToFifoAndAverage(value, arr, FIFO_LEN);
    
    Serial.print("Sample ");
    Serial.print(i+1);
    Serial.print(", value=");
    Serial.print(value);
    Serial.print(", min=");
    Serial.print(minValue);
    Serial.print(", max=");
    Serial.print(maxValue);
    Serial.print(", Fifo= {");
    printArray(arr, FIFO_LEN);
    Serial.print("}, average = ");
    Serial.println(average);
    
    delay(SAMPLE_MS);  
  }
  
  delay(SUPERLOOP_MS);
}

int sampleAnalogIn(int pin, int *pMinV, int *pMaxV) 
{
  int value = analogRead(pin);

  if((pMinV != NULL) && (pMaxV != NULL))
  {
    if(value > *pMaxV)
    {
      *pMaxV = value;
    }
    if(value < *pMinV)
    {
      *pMinV = value;
    }
  } 
  return value;
}

int addToFifoAndAverage(int value, int arr[], int FIFO_LEN)
{
  int i;
  int avg;

  for(i = FIFO_LEN-1; i>0; i--)
  {
    arr[i] = arr[i-1];
  }
  arr[0] = value;

  for(i = 0; i<FIFO_LEN; i++)
  {
    avg += arr[i];
  }
 
  return avg/FIFO_LEN;
}

void printArray(int arr[], int FIFO_LEN)
{
  int i;
  
  for(i = 0; i<FIFO_LEN; i++)
  {
    Serial.print(arr[i]);
    if(i==FIFO_LEN-1)
    {
      break;
    }
    Serial.print(", ");
  }
}


