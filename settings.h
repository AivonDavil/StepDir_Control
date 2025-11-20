#ifndef SETTINGS_H
#define SETTINGS_H

#include "Arduino.h"
#include "math.h"

int number_of_dif_microsteps = 9
enum STEP_SIZE { STEP_1, STEP_2, STEP_4, STEP_8, STEP_16, STEP_32, STEP_64, STEP_128, STEP_256 }; //без UART работают только 8 16 32 64

struct MotorAngleStruct{
  int number_of_full_steps = 0;
  unsigned short storage_digit = 0;
};

// биты для работы с MotorAngleStruct
unsigned short step_bits[9] = { 0b0100000000000000,
                                0b0010000000000000,
                                0b0001000000000000,
                                0b0000100000000000,
                                0b0000010000000000,
                                0b0000001000000000,
                                0b0000000100000000,
                                0b0000000010000000,
                                0b0000000001000000};

#endif // MOTORLIB_H