#include "Motor.h"


// void Run_angle(float angle); // 
// void Run_to_angle( float angle );
// void Run_to_angle_of_circle(float angle);

void Motor::Run_angle( float angle ){

  MotorAngleStruct Mangle;
  Mangle = this->angleToMangle(angle);

  // повернутся на угол 
  this->ON_motor();
  this->runAngle(Mangle);
  this->OFF_motor();
}

void Motor::Run_to_angle( float angle ){

  MotorAngleStruct Mangle;
  Mangle = this->angleToMangle(angle);

  Mangle = this->difMangle1MinusMangle2(Mangle);

  this->ON_motor();
  this->runAngle(Mangle);
  this->OFF_motor();

}

void Motor::Run_to_angle_of_circle(float angle){
  MotorAngleStruct Mangle;
  Mangle = this->angleToMangle(angle);

  // добавить определение угла для поворота 

  this->ON_motor();
  this->runAngle(Mangle);
  this->OFF_motor();
}