#ifndef MOTORLIB_H
#define MOTORLIB_H

#include "settings.h"


class Motor{
  public:
    Motor();
    ~Motor();
  
  public:
    void Setup_StepDir(int step_pin, int dir_pin, int en_pin, int ms1_pin, int ms2_pin); // готово
    void Setup_UART( int step_pin, int dir_pin, int en_pin, int Arduino_serial_number ); // протестить, в частности создание экземпляра драйвера
    void Setup_motor_test(); // ДОРАБОТАТЬ 
    void Set_dir( bool dir ); // готово

    void Change_dir();// готово

    void ON_motor();  // готово
    void OFF_motor(); // готово

    void Run_N_steps(int N); // готово
    void Run(); // готово 
    void Run( int step ); // готово
    void Run( int step, int step_time ); /// РЕАЛИЗОВАТЬ

    void Run_angle(float angle); // готово
    void Run_to_angle( float angle ); // готово
    void Run_to_angle_of_circle(float angle); // готово

    void Run_time(unsigned long time_to_run_ms); // готово
    void Run_revolutions_per_minute( int rev_p_m, int step ); // РЕАЛИЗОВАТЬ

    void Set_step(MOTOR_STEP_SIZE step); // готово
    void Set_half_step_time(int step_time);// ДОРАБОТАТЬ
    void Set_motor_operating_frequency_per_second( int frequency ); // ДОРАБОТАТЬ 

    int Get_Step_Pin(); // ДОРАБОТАТЬ
    int Get_Dir_Pin(); // ДОРАБОТАТЬ
    int Get_En_Pin(); // ДОРАБОТАТЬ
    int Get_Ms1_Pin(); // ДОРАБОТАТЬ
    int Get_Ms2_Pin(); // ДОРАБОТАТЬ

    float Get_Angle(); // РЕАЛИЗОВАТЬ
    bool Get_Dir(); // готово


  private:
    int STEP_PIN, DIR_PIN, EN_PIN, MS1_PIN, MS2_PIN;
    MOTOR_STEP_SIZE MOTOR_STEP = STEP_64; // выбираем первоначальный шаг
    int MOTOR_HALF_STEP_TIME = 100; // выбираем задержку между микрошагами в мк_с
    float MOTOR_FULL_STEP_DEGREES = 1.8; // полный шаг в градусах 
    float MOTOR_ANGLE;
    int MOTOR_DIR = 1;

    int MOTOR_SIGNAL = 0b0; // сигнал, выполняющийся мотором в данный момент возможно стоит сделать стек, для последовательного выполнения нескольких команд. например для проведения теста. хорошая идея 
    int SERIAL_SIGNAL = 0b0; // настоящий сигнал с порта 

    TMC2209Stepper* MOTOR_DRIVER; // РЕАЛИЗОВАТЬ  

    void runONEstep(); // готово 
    void runNsteps(int N); // готово
    void runAngle(float angle, MOTOR_STEP_SIZE step, bool is_run); // ДОРАБОТАТЬ протестировать. необходимо добавить сохранение ошибки  
    float checkAngleSetDir(float angle);  // готово
    float getAngleToCirclePosition( float angle );  // готово
    void writeONEstep();  // готово

    void setStepPin(int steppin);  //  РЕАЛИЗОВАТЬ
    void setDirPin(int dirpin);  //  РЕАЛИЗОВАТЬ
    void setEnPin(int enpin);  //  РЕАЛИЗОВАТЬ
    void setMS1Pin(int ms1pin);  //  РЕАЛИЗОВАТЬ
    void setMS2Pin(int ms2pin);  //  РЕАЛИЗОВАТЬ

    void chuseStep(int step); // готово
    void writeMS1MS2(int MS1, int MS2); // реализовать на случай подключения в режиме step/dir

    // функция проверки изменения сигнала для прерывания выполнения функций движения
    bool signalHasChanged();  // ПЕРЕДЕЛАТЬ ПОД НОВУЮ АРХИТЕКТУРУ! 

};

#endif // MOTORLIB_H



