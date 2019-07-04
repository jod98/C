//16371101
//Jordan O Donnell
//Lab 4 (EE108R)
//Part 1 Pure Functions
//17/10/2017

#include <ee108.h>

//Global Variables
int absoluteDifference(int a, int b); //Function Declaration 
int p;
int q;
int r;
int s;
int result = 0;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
 p = random(100); //Random numbers being generated for values of p, q, r and s
 q = random(100);
 r = random(100);
 s = random(100);
 Serial.print("p is ");
 Serial.print(p);
 
 Serial.print(", q is ");
 Serial.print(q);
 Serial.print(", r is ");
 Serial.print(r);
 Serial.print(", s is ");
 Serial.println(s);

 //Function Call 1 (Calculating the absoluteDifference between q and r)                                               
 result = absoluteDifference(q, r);
 Serial.print("abs diff q and r is ");
 Serial.println(result);

 //Function Call 2 (Calculating absoluteDifference betweeen p and r and testing whether the value is greater than q)                      
 if(absoluteDifference(p, r) >  q)
 {
   Serial.println("abs diff p and r > q is true");
 }
 if(absoluteDifference(p, r) <= q)
 {
   Serial.println("abs diff p and r > q is false");
 }

  //Function Call 3 (Calculating absoluteDifference between absoluteDifference of p and q & r and s)
  Serial.print("abs diff of abs diff p and q and abs diff r and s is ");
  Serial.println(absoluteDifference(absoluteDifference(p, q), absoluteDifference(r, s)));
  delay(3000);
}

//Function Defintion 1 (Calculating absoluteDifference between 
int absoluteDifference(int a, int b)
{
  if(a > b)
  {
    return a - b;
  }
  else
  {
    return b - a;
  }
}


