#include "Motor.h"


// void Run_angle(float angle); // 
// void Run_to_angle( float angle );
// void Run_to_angle_of_circle(float angle);

void Motor::Run_angle( float angle ){
  // повернутся на угол 

  angle = this->checkAngleSetDir(angle);

  this->ON_motor();
  this->runAngle(angle);
  this->OFF_motor();
}

void Motor::Run_to_angle( float angle ){


  
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