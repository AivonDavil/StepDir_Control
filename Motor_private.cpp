#include "Motor.h"

// функции из части private, отвечающие за систему движения, перенесены в соответствующие файлы 

void Motor::writeMS1MS2(int MS1, int MS2){
  digitalWrite(MS1_PIN, MS1);
  digitalWrite(MS2_PIN, MS2);
}

void Motor::chuseStep(){

  switch (MOTOR_STEP) {
    case 0: // 8 - 0,0
        writeMS1MS2(0, 0);
        break;
    case 1: // 8 - 0,0
        writeMS1MS2(0, 0);
        break;
    case 2: // 8 - 0,0
        writeMS1MS2(0, 0);
        break;
                case 3: // 8 - 0,0
                    writeMS1MS2(0, 0);
                    break;
                case 4: // 16 - 1,1
                    writeMS1MS2(1, 1);
                    break;
                case 5: // 32 - 1,0
                    writeMS1MS2(1, 0);
                    break;
                case 6: // 64 - 0,1
                    writeMS1MS2(0, 1);
                    break;
    case 7: // 8 - 0,0
        writeMS1MS2(0, 0);
        break;
    case 8: // 8 - 0,0
        writeMS1MS2(0, 0);
        break;


    default:
      writeMS1MS2(0, 0);
  }
}



