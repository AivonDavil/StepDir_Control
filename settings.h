#ifndef SETTINGS_H
#define SETTINGS_H

#include "Arduino.h"
#include "math.h"
#include "TMCStepper.h"

#define R_SENSE 0.11f        // Сопротивление токового шунта для BTT v1.3
#define DEFAULT_MOTOR_CURRENT 1200 

enum MOTOR_STEP_SIZE { STEP_1, STEP_2, STEP_4, STEP_8, STEP_16, STEP_32, STEP_64, STEP_128, STEP_256 }; //без UART работают только 8 16 32 64
enum MOTOR_DRIVER_ADRES { DRIVER_1, DRIVER_2, DRIVER_3, DRIVER_4 };

MOTOR_STEP_SIZE DEFAULT_MOTOR_STEP = STEP_1;
MOTOR_DRIVER_ADRES DEFAULT_MOTOR_DRIVER_ADDRESS = DRIVER_1;  // Адрес драйвера

#endif // MOTORLIB_H