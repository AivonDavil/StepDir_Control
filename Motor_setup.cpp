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

  pinMode( this->STEP_PIN, OUTPUT );
  pinMode( this->DIR_PIN, OUTPUT );
  pinMode( this->EN_PIN, OUTPUT );

  digitalWrite( STEP_PIN, LOW );
  digitalWrite( DIR_PIN, HIGH );
  digitalWrite( EN_PIN, HIGH );

  this->Init_Driver( Arduino_serial_number );
  this->Setup_Driver();

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
  this->MOTOR_STEP = step;

  int Step = 1<<int(step);
  this->chooseStep(int( Step ));
}

void Motor::Change_dir(){
  bool dir = !( digitalRead( this->DIR_PIN ) )

  digitalWrite( this->DIR_PIN, dir );
  this->Set_dir(dir);
}

void Motor::Set_half_step_time(int half_step_time){

  setHalfStepTime(half_step_time);
}


void Motor::Init_Driver(int Serial_Port_Number, MOTOR_DRIVER_ADRES DRIVER_ADRES = DEFAULT_MOTOR_DRIVER_ADDRESS)
{
  this->chooseSerialPort( Serial_Port_Number );
  this->MOTOR_DRIVER( &(this->MOTOR_SERIAL_PORT), R_SENSE, DRIVER_ADRES );

}



void Motor::Setup_Driver(int current = DEFAULT_MOTOR_CURRENT, MOTOR_STEP_SIZE step = DEFAULT_MOTOR_STEP, bool noisy_but_powerful = false )
{
  this->MOTOR_DRIVER.toff(5);                  
  this->MOTOR_DRIVER.rms_current(current); // Установка тока
  // driver.microsteps(MICROSTEPS);   // Установка микрошага 1/2
  this->Set_step(step)
  this->MOTOR_DRIVER.pwm_autoscale(true); // поддерживает нужный уровень тока в катушках
  this->MOTOR_DRIVER.en_spreadCycle(noisy_but_powerful);    // StealthChop

  /*
  SpreadCycle — высокопроизводительный режим, который обеспечивает быстрый отклик и подходит для приложений,
  требующих высокого крутящего момента или быстрых движений. В этом режиме двигатель управляется более агрессивно,
  но при этом повышается уровень шума. SpreadCycle идеален для быстрых перемещений или тяжёлых механических нагрузок.
  StealthChop — режим бесшумной работы, который значительно снижает шум шагового двигателя. Он особенно полезен в 
  3D-принтерах, оборудовании для камер и других условиях, где нежелателен шум. StealthChop лучше всего работает на 
  низких и средних скоростях, обеспечивая плавное и тихое движение.
  Таким образом, SpreadCycle предпочтительнее для быстрых движений и высоких нагрузок, а StealthChop — для тихой и 
  плавной работы на низких скоростях
  */
}

