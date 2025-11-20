#include "Motor.h"



bool Motor::Get_Dir(){
  return digitalRead( this->DIR_PIN );
}