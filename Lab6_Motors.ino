#include <mbed.h>

using namespace::mbed;

PwmOut MotorAPWM(P0_27);
DigitalOut MotorADir(P0_4);
PwmOut MotorBPWM(P1_2);
DigitalOut MotorBDir(P0_5);

void setup(){
  Serial.begin(9600);
}

class Motor {
  public:
    int moveMotor(int motor, int direction, float speed);
    int brakeMotor(int motor);
};

int Motor::moveMotor(int motor, int direction, float speed) {

  if (motor == 0) {
      Serial.println("Motor A selected");
      MotorAPWM.period(0.0001f); // Sets frequency to 100kHz
      MotorADir.write(direction);//set direction forward
      MotorAPWM.write(speed); 
  }
  else if (motor == 1) {
      Serial.println("Motor B selected");
      MotorBPWM.period(0.0001f); // Sets frequency to 100kHz
      MotorBDir.write(direction);//set direction
      MotorBPWM.write(speed);
  }
  else {
    Serial.println("re-enter motor number");
  }
}

int Motor::brakeMotor(int motor){

  if (motor == 0) {
    Serial.println("Motor A braking");
    MotorAPWM.write(0);//pwm input set low
    //set high z as per datasheet
    MotorADir.write(0);
    MotorAPWM.write(0);
  }
  
  if (motor ==1 ) {
    Serial.println("Motor B braking");
    MotorBPWM.write(1);//pwm input set low
    //set high z
    MotorBDir.write(0);
    MotorBPWM.write(0);
  }
}

void loop() {
  Motor motor;
  motor.moveMotor(0, 0, 0.5f);
  delay(1000);
  motor.brakeMotor(0);
  delay(1000);
  motor.moveMotor(0, 1, 0.5f);
  delay(1000);
  motor.brakeMotor(0);
  delay(1000);
  motor.moveMotor(1, 0, 0.75f);
  delay(1000);
  motor.brakeMotor(1);
  delay(1000);
  motor.moveMotor(1, 1, 0.75f);
  delay(1000);
  motor.brakeMotor(1);
  delay(1000);
}
