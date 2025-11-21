#include "Motor.h"

void Motor::writeONEstep(){
  float angle = this->MOTOR_FULL_STEP_DEGREES / (1<<MOTOR_STEP);
  this->MOTOR_ANGLE += angle * MOTOR_DIR;
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
  delayMicroseconds(MOTOR_HALF_STEP_TIME);
  digitalWrite( STEP_PIN, LOW );
  delayMicroseconds(MOTOR_HALF_STEP_TIME);
  this->writeONEstep();
}

void Motor::runAngle(float angle, MOTOR_STEP_SIZE step, bool is_run){

  int N = 0;
  float step_angle = this->MOTOR_FULL_STEP_DEGREES / (1<<step); 
  this->setStep( step );

  N = floor( angle/step_angle );
  angle -= step_angle * N;

  this->runNsteps(N);  

  if( !is_run || angle == 0 || step==8 ){
    return;
  }

  this->runAngle( angle, step+1, true );
}


float Motor::checkAngleSetDir(float angle){

  if( angle<0 ){
    this-> Set_dir( false );
    angle *= -1;
  }
  else{
    this->Set_dir( true );
  }

  return angle;

}

float Motor::getAngleToCirclePosition( float angle ){

  float motor_angle = this->MOTOR_ANGLE;
  int N = floor(motor_angle / 360);
  motor_angle = motor_angle - 360*N;

  angle = angle - motor_angle;
  return angle;

}

