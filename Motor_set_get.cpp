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