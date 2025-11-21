#include "Arduino.h"
#include "Motor.h"

Motor::Motor(){ 
}

Motor::~Motor(){
}

void Motor::Setup_StepDir(int step_pin, int dir_pin, int en_pin, int ms1_pin, int ms2_pin){

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

// все настройки базовые, для тонких нужно настраивать мотор отдельно 
void Motor::Setup_UART( int step_pin, int dir_pin, int en_pin, int Arduino_serial_number){

  this->STEP_PIN = step_pin;
  this->DIR_PIN = dir_pin;
  this->EN_PIN = en_pin;

  HardwareSerial& SerialPort; 
  TMC2209Stepper driver;


  pinMode( this->STEP_PIN, OUTPUT );
  pinMode( this->DIR_PIN, OUTPUT );
  pinMode( this->EN_PIN, OUTPUT );

  digitalWrite( STEP_PIN, LOW );
  digitalWrite( DIR_PIN, HIGH );
  digitalWrite( EN_PIN, HIGH );



  switch (Arduino_serial_number)
  {
  case 0:
    SerialPort = Serial;
    break;
  case 1:
    SerialPort = Serial1;
    break;
  case 2:
    SerialPort = Serial2;
    break;
  case 3:
    SerialPort = Serial3;
    break;
  
  default:
    break;
  }

  driver(&SerialPort, R_SENSE, DRIVER_ADDRESS);

  SerialPort.begin(115200);      
  driver.begin();

  driver.toff(5);                  
  driver.rms_current(MOTOR_CURRENT); // Установка тока
  driver.pwm_autoscale(true);      
  driver.en_spreadCycle(false);    // StealthChop режим работы 


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

void Motor::Set_step( MOTOR_STEP_SIZE step ){

  int Step = 1<<int(step);

  this->chuseStep(int( Step ));
}

void Motor::Change_dir(){
  digitalWrite( this->DIR_PIN, !( digitalRead( this->DIR_PIN ) ) );
  this->Set_dir(! digitalRead( this->DIR_PIN ));
}

void Motor::Set_half_step_time(int step_time){
  step_time = constrain(step_time, 1, 1000);

  // this->Chusestep_time();
  MOTOR_HALF_STEP_TIME = step_time;


}
