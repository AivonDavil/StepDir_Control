#include "Motor.h"



Motor m1;


void setup() {
  Serial.begin(9600);


  m1.Setup(41, 43, 31, 35, 37);
  
}

void loop() {

  m1.Run_angle(90);
// в соответствии с протоколом связи пройтись по всем возможным вариантам и запустить нужный 

}