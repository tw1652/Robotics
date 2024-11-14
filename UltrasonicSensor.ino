#include <mbed.h>

using namespace mbed;

DigitalInOut trig(P1_14);//puts it on sensor 2 position on the board
DigitalInOut echo(P1_14);
Timer timer;
int distance = 0;
int correction = 0;

void setup() {
}

//I've put setup stuff here, this is for the correction, might not be needed methinks!
//This  will give how much delay there is in just turning on and off the timer
//if it turns out that sensor is innaccurate, put this in
//if not leave it out, more efficient code without it
/*timer.reset();
timer.start();
timer.stop();
correction = timer.read_us();
Serial.print("Approx software overhead timer delay is %d uS\n\r",correction);*/

void loop() {
  // trigger the ultrasonic sensor to send a pulse for 10uS
  trig.output();// sets pin to output
  trig = 1;
  timer.reset();
  wait_us(10);
  trig = 0;

  // wait for a rising edge
  trig.input();// sets pin to input
  echo.input();// sets echo to input
  while (echo==0) {};
  //echo high, starting timer to measure time till we get a reading
  timer.start();
  while (echo==1) {};
  timer.stop();
  distance = (timer.read_us()/58.0);  //divide by 58 as per datasheet for conversion to cm
  Serial.println(); // print blank line
  Serial.print("Distance in cm: ");
  Serial.print(distance, DEC);//print distance in decimal
  Serial.println(); 
  delay(100); //wait so any echoes return before sending another pulse as per datasheet reccomendation
}
