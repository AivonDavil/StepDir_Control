#ifndef MOTORLIB_H
#define MOTORLIB_H

#include "settings.h"
/*

учет остатка угла!

*/

class Motor{
  public:
    Motor(int step_pin, int dir_pin, int en_pin, int Arduino_serial_number);
    ~Motor();
  
  public:
    void Setup_UART(); // протестить, в частности создание экземпляра драйвера
      void Init_Driver( int Serial_Port_Number, int Serial_Port_Speed = DEFAULT_SERIAL_BAUD_RATE, int DRIVER_ADRES = DEFAULT_MOTOR_DRIVER_ADRES ); // готово
      void Setup_Driver( int current = DEFAULT_MOTOR_CURRENT, MOTOR_STEP_SIZE step = DEFAULT_MOTOR_STEP, bool noisy_but_powerful = false); // готово
    void Setup_motor_test_one_revolution_on_any_step(); // готово 
    void Motor_test_one_revolution_on_all_steps(); // готово

  public:
    void Set_dir( bool dir ); // готово
    void Change_dir();// готово
    void ON_motor();  // готово
    void OFF_motor(); // готово
    void Set_step(MOTOR_STEP_SIZE step); // готово
    void Set_half_step_time(int step_time);// готово
    void Set_motor_operating_frequency_per_second( int frequency ); // готово 
  
  public:
    void Run_N_steps(int N); // готово
    void Run(); // готово 
    void Run( int step ); // готово
    void Run( int step, int step_time ); /// РЕАЛИЗОВАТЬ
  
    void Run_angle(float angle); // готово
    void Run_to_angle( float angle ); // готово
    void Run_to_angle_of_circle(float angle); // готово

    void Run_time(unsigned long time_to_run_ms); // готово
    void Run_revolutions_per_minute( int rev_p_m, int step ); // РЕАЛИЗОВАТЬ

  public:
    int Get_Step_Pin(); // ДОРАБОТАТЬ
    int Get_Dir_Pin(); // ДОРАБОТАТЬ
    int Get_En_Pin(); // ДОРАБОТАТЬ
    float Get_Angle(); // РЕАЛИЗОВАТЬ
    bool Get_Dir(); // готово


  private:
    int STEP_PIN, DIR_PIN, EN_PIN;
    MOTOR_STEP_SIZE MOTOR_STEP = STEP_64; // выбираем первоначальный шаг
    int MOTOR_HALF_STEP_TIME = 100; // выбираем задержку между микрошагами в мк_с
    float MOTOR_FULL_STEP_DEGREES = 1.8; // полный шаг в градусах 
    float MOTOR_ANGLE;
    int MOTOR_DIR = 1;

    int MOTOR_SIGNAL = 0b0; // сигнал, выполняющийся мотором в данный момент возможно стоит сделать стек, для последовательного выполнения нескольких команд. например для проведения теста. хорошая идея 
    int SERIAL_SIGNAL = 0b0; // настоящий сигнал с порта 

    TMC2209Stepper MOTOR_DRIVER; // готово
    HardwareSerial* MOTOR_SERIAL_PORT; // готово

    void runONEstep(); // готово 
    void runNsteps(int N); // готово
    void runAngle(float angle, MOTOR_STEP_SIZE step, bool is_run); // ДОРАБОТАТЬ протестировать. необходимо добавить сохранение ошибки  
    float checkAngleSetDir(float angle);  // готово
    float getAngleToCirclePosition( float angle );  // готово
    void writeONEstep();  // готово

    void setStepPin(int steppin);  //  РЕАЛИЗОВАТЬ
    void setDirPin(int dirpin);  //  РЕАЛИЗОВАТЬ
    void setEnPin(int enpin);  //  РЕАЛИЗОВАТЬ

    void chooseStep(int step); // готово

    // функция проверки изменения сигнала для прерывания выполнения функций движения
    bool signalHasChanged();  // ПЕРЕДЕЛАТЬ ПОД НОВУЮ АРХИТЕКТУРУ! 

    void chooseSerialPort( int Serial_Port_Number );

    void setHalfStepTime(int time); // готово
    

};

#endif // MOTORLIB_H



