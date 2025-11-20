// фукнции к измененеию 
// структура 
//   Motor_private
// angleToMangle //

//   Motor_set_get
// Get_Angle
// and functions in run sistem

 // создать тип данных для хранения шага 

struct MotorAngleStruct{
  int number_of_full_steps = 0;
  unsigned short storage_digit = 0x0;
};

MotorAngleStruct Motor::angleToMangle( float angle ){

    // MotorAngleStruct motor_angle;

    // for( int i = 0; i<9; i++ ){
    //     int steps = floor( (pow(2,i)*angle)/MOTOR_FULL_STEP_DEGREES );
    //     motor_angle.angle[i] = steps;
    //     angle -= steps * pow(2,i);
    // }
    // return motor_angle;

  MotorAngleStruct motor_angle;

  int steps = floor( angle/(this->MOTOR_FULL_STEP_DEGREES) );
  motor_angle.number_of_full_steps = steps;
  angle-= steps*(this->MOTOR_FULL_STEP_DEGREES);

  for( int i = 1; i<9; i++ ){
    steps = floor( (pow(2,i)*angle)/MOTOR_FULL_STEP_DEGREES );
    motor_angle.storage_digit+= steps * step_bits[i];
    angle -= steps*(this->MOTOR_FULL_STEP_DEGREES)/pow(2,i);
  }
  return motor_angle;
}



 