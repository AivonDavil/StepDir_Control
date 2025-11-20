#include "Motor.h"

void Motor::writeONEstep(){

  if( this->Get_Dir() ){
    this->MOTOR_ANGLE.angle[this->MOTOR_STEP] +=1;
  }
  else{
    this->MOTOR_ANGLE.angle[this->MOTOR_STEP] -=1;
  }  

  for( int i = this->MOTOR_STEP; i>0; i-- ){ // приводим наши данные с правильному виду, дабы в долях были числа 

    if( this->MOTOR_ANGLE.angle[i] == 2 )
    {
      this->MOTOR_ANGLE.angle[i] = 0;
      this->MOTOR_ANGLE.angle[i-1] += 1;
    }
  }

}

bool Motor::signalHasChanged(){
  if( this->MOTOR_SIGNAL != this->SERIAL_SIGNAL ){
    return true;
  }
  else{
    return false;
  }
}

void Motor::runNsteps(int N){
  int i = 0;
  while( i<N && !this->signalHasChanged() ){
    this->runONEstep();
    i+=1;
  }
  
}

void Motor::runONEstep(){
  // выплоняем два шага с записью
  digitalWrite( STEP_PIN, HIGH ); 
  delayMicroseconds(MOTOR_STEP_TIME_MKS);
  digitalWrite( STEP_PIN, LOW );
  delayMicroseconds(MOTOR_STEP_TIME_MKS);
  this->writeONEstep();
}


void runAngle(MotorAngleStruct Mangle){

  for( int i = 0; i<9; i++ ){
    int N = Mangle.angle[i];
    this->MOTOR_STEP = i;
    this->chuseStep();
    this->runNsteps(N);

  }
}

