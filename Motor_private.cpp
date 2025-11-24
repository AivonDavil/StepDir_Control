#include "Motor.h"

// функции из части private, отвечающие за систему движения, перенесены в соответствующие файлы 

void Motor::writeMS1MS2(int MS1, int MS2){
  digitalWrite(MS1_PIN, MS1);
  digitalWrite(MS2_PIN, MS2);
} // ! функционал вырезан!

void Motor::chooseStep(int step){
    this->driver.microsteps( step );
}

void Motor::chooseSerialPort(int Serial_Port_Number)
{
  switch (Serial_Port_Number)
  {
  case 0:
    this->MOTOR_SERIAL_PORT = Serial;
    break;
  case 1:
    this->MOTOR_SERIAL_PORT = Serial1;
    break;
  case 2:
    this->MOTOR_SERIAL_PORT = Serial2;
    break;
  case 3:
    this->MOTOR_SERIAL_PORT = Serial3;
    break;

  default:
    break;
  }

}

void Motor::setHalfStepTime(int T){
  if( T < 70 ){
    T=70;
  }
  this->MOTOR_HALF_STEP_TIME = T;
}
