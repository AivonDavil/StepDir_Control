#include "Motor.h"

bool Motor::Get_Dir(){
  digitalRead( this->DIR_PIN );
  
}

void Motor::Set_dir(bool dir){
  digitalWrite( this->DIR_PIN, dir );
  if(dir){
    this->MOTOR_DIR = 1;
  }
  else{
    this->MOTOR_DIR = -1;
  }

}


void Motor::Set_motor_operating_frequency_per_second( int frequency ){

  float T = 1/frequency;
  T = constrain(T, 1000000,2000000 );
  this->MOTOR_HALF_STEP_TIME = T;

}