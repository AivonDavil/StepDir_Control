#include "Arduino.h"
#include "Motor.h"

Motor::Motor(){ 
}

Motor::~Motor(){
}

void Motor::Setup(int step_pin, int dir_pin, int en_pin, int ms1_pin, int ms2_pin){

  this->STEP_PIN = step_pin;
  this->DIR_PIN = dir_pin;
  this->EN_PIN = en_pin;
  this->MS1_PIN = ms1_pin;
  this->MS2_PIN = ms2_pin;

  // настраиваем режимы работы пинов
  pinMode( this->STEP_PIN, OUTPUT );
  pinMode( this->DIR_PIN, OUTPUT );
  pinMode( this->EN_PIN, OUTPUT );
  pinMode( this->MS1_PIN, OUTPUT );
  pinMode( this->MS2_PIN, OUTPUT );

  // задаем начальное направление и отключаем мотор, дабы мотор и драйвер не грелись просто так
  digitalWrite( STEP_PIN, LOW );
  digitalWrite( DIR_PIN, HIGH );
  digitalWrite( EN_PIN, HIGH );

}

void Motor::ON_motor(){
  digitalWrite(this->EN_PIN, LOW);
}

void Motor::OFF_motor(){
  digitalWrite(this->EN_PIN, HIGH);
}

void Motor::Setup_motor_test(){
  // для роверки работоспособности делаем один полный оборот в начале программы 
  digitalWrite( EN_PIN, LOW ); // включаем мотор 

  int N = 100* (1<<MOTOR_STEP); //считаем сколько шагов нужно для полного оборота 
  for( int i = 0; i<N; i++ ){
    this->runONEstep();
  }
  digitalWrite( EN_PIN, HIGH );
}

void Motor::Set_step( int step ){
  
  for( int i = 0; i<9; i++ ){
    if( step == 1<<i ){
      MOTOR_STEP = i;
      break;
    }
  }
  this->chuseStep();
}

void Motor::Change_dir(){
  digitalWrite( this->DIR_PIN, !( digitalRead( this->DIR_PIN ) ) );
  this->Set_dir(! digitalRead( this->DIR_PIN ));
}

void Motor::Set_step_time(int step_time){
  step_time = constrain(step_time, 1, 1000);

  // this->Chusestep_time();
  MOTOR_STEP_TIME_MKS = step_time;


}
