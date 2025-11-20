#ifndef MOTORLIB_H
#define MOTORLIB_H

#include "settings.h"
#include "Mangle.h"


// 1.8 градуса это на пару хай-лоу или только на один сигнал? 

class Motor{
  public:

    Motor();
    ~Motor();

    void Setup(int step_pin, int dir_pin, int en_pin, int ms1_pin, int ms2_pin); //
    void Setup_motor_test(); //
    void Set_dir( bool dir );

    void Change_dir();//

    void ON_motor();
    void OFF_motor();

    void Run_N_steps(int N);
    void Run();
    void Run( int step );
    void Run( int step, int step_time ); /// реализовать 

    // ДОРАБОТАТЬ
    void Run_angle(float angle);
    void Run_to_angle( float angle );
    void Run_to_angle_of_circle(float angle);

    void Run_time(unsigned long time_to_run_ms);//

    void Run_revolutions_per_minute( int rev_p_m, int step );

    void Set_step(int step);//
    void Set_step_time(int step_time);// ДОРАБОТАТЬ
    int Get_Step_Pin();
    int Get_Dir_Pin();
    int Get_En_Pin();
    int Get_Ms1_Pin();
    int Get_Ms2_Pin();

    float Get_Angle();
    bool Get_Dir();


  private:
    int STEP_PIN, DIR_PIN, EN_PIN, MS1_PIN, MS2_PIN;
    MOTOR_STEP_SIZE MOTOR_STEP = STEP_64; // выбираем первоначальный шаг
    int MOTOR_STEP_TIME_MKS = 100; // выбираем задержку между микрошагами в мк_с
    float MOTOR_FULL_STEP_DEGREES = 1.8; // полный шаг в градусах 
    float MOTOR_ANGLE;
    int MOTOR_DIR = 1;

    int MOTOR_SIGNAL = 0b0; // сигнал, выполняющийся мотором в данный момент возможно стоит сделать стек, для последовательного выполнения нескольких команд. например для проведения теста. хорошая идея 
    int SERIAL_SIGNAL = 0b0; // настоящий сигнал с порта 

    void runONEstep();
    void runNsteps(int N);
    void runAngle(float angle, MOTOR_STEP_SIZE step, bool is run);
    float checkAngleSetDir(float angle);
    void writeONEstep();

    void setStepPin(int steppin);
    void setDirPin(int dirpin);
    void setEnPin(int enpin);
    void setMS1Pin(int ms1pin);
    void setMS2Pin(int ms2pin);

    void setStep(MOTOR_STEP_SIZE step);
    void chuseStep();
    void writeMS1MS2(int MS1, int MS2);

    // void Chusestep_time();
    
    // функция проверки изменения сигнала для прерывания выполнения функций движения
    bool signalHasChanged();  

};

#endif // MOTORLIB_H



