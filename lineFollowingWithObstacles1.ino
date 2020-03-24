
/*******************************************
 Sparki Line-following example
 
 Threshold is the value that helps you 
 determine what's black and white. Sparki's 
 infrared reflectance sensors indicate white 
 as close to 900, and black as around 200.
 This example uses a threshold of 700 for 
 the example, but if you have a narrow line, 
 or perhaps a lighter black, you may need to 
 adjust.
********************************************/

#include <Sparki.h> // include the sparki library
#define NO_ACCEL // disables the Accelerometer, frees up 598 Bytes Flash Memory
#define NO_MAG // disables the Magnetometer, frees up 2500 Bytes Flash Memory
 
  
 
void setup() 
{

}

void loop() {

  int threshold = 650;
  int lineLeft   = sparki.lineLeft();   // measure the left IR sensor
  int lineCenter = sparki.lineCenter(); // measure the center IR sensor
  int lineRight  = sparki.lineRight();  // measure the right IR sensor
  int cm = sparki.ping();               // measures the distance with Sparki's eyes

   bool check;
 
  
  sparki.clearLCD();
    
  sparki.servo(4); // rotate the servo to straight forward position
  delay(0);
   
  while (cm > 6) // while the object is further than 6 cm the line following command will execute
    {
    lineFollowing:
       
  if ( lineCenter < threshold ) // if line is below left line sensor
  {  
    sparki.moveForward(); // move forward
  }
  else{
    if ( lineLeft < threshold ) // if line is below left line sensor
    {  
      sparki.moveLeft(); // turn left
    }
  
    if ( lineRight < threshold ) // if line is below right line sensor
    {  
      sparki.moveRight(); // turn right
    }
  }
 
 
  sparki.clearLCD(); // wipe the screen

    sparki.print("Distance: "); 
    sparki.print(cm); // tells the distance to the computer
    sparki.println(" cm"); 
  
  sparki.print("Line Left: "); // show left line sensor on screen
  sparki.println(lineLeft);
  
  sparki.print("Line Center: "); // show center line sensor on screen
  sparki.println(lineCenter);
  
  sparki.print("Line Right: "); // show right line sensor on screen
  sparki.println(lineRight);

  sparki.updateLCD(); // display all of the information written to the screen

  delay(100); // wait 0.1 seconds

  //check = object();
  
  if (check = false)
  {
    goto lineFollowing;  // send it back to the line following commands
  }
}  // end of (cm > 6) while loop
 
 sparki.moveLeft (30);
 delay (500);
 sparki.servo (45);
 delay(0500);

 while (sparki.lineLeft() > threshold && sparki.lineCenter() > threshold && sparki.lineRight() > threshold)
 {  
   if (cm > 6)
   {
   sparki.moveRight ();
   }

   if (cm <= 6) 
   {
   sparki.moveForward ();
   }
 
    sparki.clearLCD(); // wipe the screen

    sparki.print("Distance: "); 
    sparki.print(cm); // tells the distance to the computer
    sparki.println(" cm"); 
  
  sparki.print("Line Left: "); // show left line sensor on screen
  sparki.println(lineLeft);
  
  sparki.print("Line Center: "); // show center line sensor on screen
  sparki.println(lineCenter);
  
  sparki.print("Line Right: "); // show right line sensor on screen
  sparki.println(lineRight);

  sparki.updateLCD(); // display all of the information written to the screen

  delay(100); // wait 0.1 seconds
  
 }

   bool object();
   {
    // if the robot sees and object
    if (sparki.ping() <= 6)
    {
      return true;
    }
    else
    {
      return false;
    }
   }
}
  
   
   
