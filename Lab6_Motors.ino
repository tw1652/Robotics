#include <mbed.h>

using namespace::mbed;
//Serial.begin(9600);

PwmOut MotorAPWM(P0_27);
DigitalOut MotorADir(P0_4);
PwmOut MotorBPWM(P1_2);
DigitalOut MotorBDir(P0_5);

void setup(){
}

class Motor {
  public:
    int moveMotor(int motor, int direction, float speed);
};

int Motor::moveMotor(int motor, int direction, float speed) {

  if (motor = 0) {
    if (direction = 0) {
      Serial.println("Motor A selected");
      MotorAPWM.period(0.0001f); // Sets frequency to 100kHz
      //set direction forward
      MotorAPWM.write(speed); 
    }
    if (direction  = 1) {
      Serial.println("Motor A selected");
      MotorAPWM.period(0.0001f); // Sets frequency to 100kHz
      //set direction backward
      MotorAPWM.write(speed);   
    }

  }
  if (motor = 1) {
    if (direction = 0) {
      Serial.println("Motor B selected");
      MotorBPWM.period(0.0001f); // Sets frequency to 100kHz
      //set direction forward
      MotorBPWM.write(speed);
    } 
    if (direction = 1) {
      Serial.println("Motor B selected");
      MotorBPWM.period(0.0001f); // Sets frequency to 100kHz
      //set direction backward
      MotorBPWM.write(speed);
    }
  }
  else {
    Serial.println("re-enter motor number");
  }
}

void loop() {
  Motor motor;
  motor.moveMotor(0, 0, 0.5f);
}
