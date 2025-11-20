#include "Motor.h"

///
MotorAngleStruct Motor::angleToMangle( float angle ){

  MotorAngleStruct motor_angle;

  int steps = floor( angle/(this->MOTOR_FULL_STEP_DEGREES) );
  motor_angle.number_of_full_steps = steps;
  angle-= steps*(this->MOTOR_FULL_STEP_DEGREES);

  for( int i = 1; i<9; i++ ){
    steps = floor( (pow(2,i)*angle)/MOTOR_FULL_STEP_DEGREES );
    motor_angle.storage_digit+= steps * step_bits[i];
    angle -= steps*(this->MOTOR_FULL_STEP_DEGREES)/pow(2,i);
  }
  return motor_angle;
}

///
MotorAngleStruct Motor::difMangle1MinusMangle2(MotorAngleStruct Mangle1, MotorAngleStruct Mangle2 ){

  for( int i = 0; i<9; i++ ){
    Mangle.angle[i] -= this->MOTOR_ANGLE.angle[i];
  }
  return Mangle;
}

///
MotorAngleStruct Motor::angleToPositionOnCircle(MotorAngleStruct Mangle){



}


float Motor::Get_Angle(){

  float angle = this->MOTOR_ANGLE.number_of_full_steps;


  for( int i = 1; i<9; i++){
    angle += (this->MOTOR_ANGLE.storage_digit & step_bits[i])/pow(2, i);
  }
  return angle*this->MOTOR_FULL_STEP_DEGREES;
}
