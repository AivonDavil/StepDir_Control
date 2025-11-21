#ifndef SETTINGS_H
#define SETTINGS_H

#include "Arduino.h"
#include "math.h"
#include "TMCStepper.h"

#define DRIVER_ADDRESS 0b00  // Адрес драйвера
#define R_SENSE 0.11f        // Сопротивление токового шунта для BTT v1.3
#define MOTOR_CURRENT 1200 

enum MOTOR_STEP_SIZE { STEP_1, STEP_2, STEP_4, STEP_8, STEP_16, STEP_32, STEP_64, STEP_128, STEP_256 }; //без UART работают только 8 16 32 64




#endif // MOTORLIB_H