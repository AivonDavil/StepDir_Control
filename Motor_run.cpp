#include "Arduino.h"
#include "Motor.h"

void Motor::Run_N_steps(int N){
  this->ON_motor();

  this->runNsteps(N);

  this->OFF_motor();
}


void Motor::Run(){ // запуск мотора с прежней скоростью
  this->ON_motor();

  while( !this->signalHasChanged() ){
    this->runONEstep();
  }  
  this->OFF_motor();
}

void Motor::Run( int step ){

  this->Set_step(step); // задаем шаг

  this->ON_motor();

  while( !this->signalHasChanged() ){
    this->runONEstep();
  }  
  this->OFF_motor();
}