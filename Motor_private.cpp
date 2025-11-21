#include "Motor.h"

// функции из части private, отвечающие за систему движения, перенесены в соответствующие файлы 

void Motor::writeMS1MS2(int MS1, int MS2){
  digitalWrite(MS1_PIN, MS1);
  digitalWrite(MS2_PIN, MS2);
}

void Motor::chuseStep(int step){
    this->MOTOR_STEP = step;
    this->driver.microsteps( step );
}





