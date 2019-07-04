/**
 * 16371101
 * Jordan O Donnell
 * Genererating new passwords using String Pointers and Const
 */

#include <ee108.h>

//------------------------------------------------------------
// constants
//------------------------------------------------------------

const int SUPERLOOP_DELAY_MS = 50;
const int ARRAY_SIZE = 11;

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab8_PasswordGenStarter starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() 
{
  int sw1Event;
  //Delaring local character array with initial string "PASSWORD"
  static char arr[ARRAY_SIZE] = {"PASSWORD"};

  sw1Event = readSwitchEvent(sw1Object);

  if (sw1Event == SW_RELEASE_CLICK) // wait for click
  { 
    int i;
    Serial.print("[SW1 Click] current password is: ");
    //Print current value of array
    Serial.print(arr);

    Serial.println();
  } 
  else if (sw1Event == SW_LONG_CLICK) 
  {
    int i;
    //New password length
    int len = random(4, 10);
    
    Serial.print("[SW1 Long Click] new password (len = ");
    Serial.print(len);
    Serial.print("): ");

    //Creating new password using random letters 
    for(i = 0; i<len; i++)
    {
      arr[i] = random('A', 'A' + 26);
      arr[len] = '\0';
    }
    Serial.print(arr);
    
    Serial.println(); 
  }
  
  delay(SUPERLOOP_DELAY_MS);
}
