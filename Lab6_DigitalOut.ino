#include <mbed.h>

using namespace::mbed;
//Serial.begin(9600);

DigitalOut MotorAPWM(P0_27);
DigitalOut MotorADir(P0_4);
DigitalOut MotorBPWM(P1_2);
DigitalOut MotorBDir(P0_5);

void setup() {
}


void loop() {
  MotorAPWM = 1;
  MotorADir = 1;
  //Motor A off
  wait_us(500000);// Wait for 0.5 seconds
  MotorAPWM = 0;
  MotorADir = 0;
  //Motor A off
  wait_us(500000);// wait for 0.5 seconds
  MotorBPWM = 1;
  MotorBDir = 1;
  wait_us(500000);
  MotorBPWM = 0;
  MotorBDir = 0;

}
