#include <mbed.h>

using namespace mbed;
//Serial.begin(9600);

DigitalInOut trig(P1_14);//puts it on sensor 2 position on the board
DigitalInOut echo(P1_14);
Timer timer;
int distance = 0;
int correction = 0;

void setup() {
}

//I've put setup stuff here
//This is for the correction, might not be needed methinks!
/*timer.reset();
timer.start();
timer.stop();
correction = timer.read_us();
Serial.print("Approx software overhead timer delay is %d uS\n\r",correction);*/

void loop() {
  // trigger the ultrasonic sensor to send a pulse
  // this will send a pulse for 10uS
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
  //divide by 58 as that's what it says on datasheet for cm
  distance = (timer.read_us()/58.0);
  Serial.print("Distance in cm: ");
  Serial.print(distance, DEC);//print distance in decimal (no it doesn't)
  Serial.println(); // print blank line
  wait_us(60000); //wait 60ms so any echoes return before sending another pulse
  //as per datasheet reccomendation

}