/**
 * 16371101
 * Jordan O Donnell
 * Lab 8 Struct Line Slope
 * Calculating Slope Of Line Using Structures
 */

#include <ee108.h>

//------------------------------------------------------------
// types
//------------------------------------------------------------

// a structure to represent a 2d point in cartesian coordinates
struct Point2d {
  int x;
  int y;
};

typedef struct Point2d Point2d; //Typedef (name Pointed2d is an alias for struct Point2d)

//------------------------------------------------------------
// constants
//------------------------------------------------------------

const int SUPERLOOP_DELAY_MS = 50;
const float DENOMINATOR_0_VALUE = 99999.99;

//------------------------------------------------------------
// function declarations/prototypes
//------------------------------------------------------------

void printPoint2d(Point2d *pPoint);
float slopePoint2d(Point2d *pPoint1, Point2d *pPoint2);

//------------------------------------------------------------
// top level functions
//------------------------------------------------------------

void setup() {
  // set up serial
  Serial.begin(9600);
  Serial.println("\n\nLab8_StructLineSlope Starter starting...\n");
  Serial.println("\nClick SW1 to start\n");    
}

void loop() 
{
  int sw1Event;
  static Point2d p1 = {1500, 500}; //Declaring two new point p1 using alias Point2d
  static Point2d p2 = {0, 0}; //Declaring two new point p2 using alias Point2d
  
  sw1Event = readSwitchEvent(sw1Object);

  if (sw1Event == SW_RELEASE_CLICK) // wait for click
  { 
    Serial.print("[SW1 Click] ");

    Serial.print("point 1");
    printPoint2d(&p1);
    
    Serial.print("point 2");
    printPoint2d(&p2);

    //Cacluating slope
    Serial.print("slope=");
    Serial.print(slopePoint2d(&p1,&p2));
    
    Serial.println();
  } 
  
  else if (sw1Event == SW_LONG_CLICK) 
  {
    Serial.print("[SW1 Long Click] ");
    
    //Replace p2's x and y members with random values
    
    p2.x = random(-9999, 9999);
    p2.y = random(-9999, 9999);

    //Printing out p2's contents
    Serial.print("new point 2 {x = ");
    Serial.print(p2.x);
    Serial.print(", y=");
    Serial.print(p2.y);
    Serial.print("}");
    
    Serial.println();
  }
  
  delay(SUPERLOOP_DELAY_MS);
}

//------------------------------------------------------------
// helper functions
//------------------------------------------------------------

void printPoint2d(Point2d *pPoint)
{
  Serial.print(" {x =");
  Serial.print(pPoint ->x);
  Serial.print(", y =");
  Serial.print(pPoint ->y);
  Serial.print("}, ");
 }

float slopePoint2d(Point2d *pPoint1, Point2d *pPoint2)
{
  float slope;
  float numerator = ((pPoint2->y)-(pPoint1->y)); 
  float denominator = ((pPoint2->x)-(pPoint1->x));

  if(denominator == 0.0)
  {
    return DENOMINATOR_0_VALUE;
  }
  else
  {
    slope = numerator/denominator;
  }
  return slope;
}


