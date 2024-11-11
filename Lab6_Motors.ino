#include <mbed.h>

using namespace::mbed;
//Serial.begin(9600);

PwmOut MotorAPWM(P0_27);
DigitalOut MotorADir(P0_4);
PwmOut MotorBPWM(P1_2);
DigitalOut MotorBDir(P0_5);

void setup() {
}


void loop() {
  MotorAPWM.period(0.0001f); // 100kHz frequency
  MotorBPWM.period(0.0001f); // 100kHz frequency
  //Motor A on and off
  MotorAPWM.write(0.50f); // 50% duty cycle 
  //Motor B on and off
  MotorBPWM.write(0.25f); // 25% duty cycle 
  
}
