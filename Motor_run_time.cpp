#include "Motor.h"


void Motor::Run_time(unsigned long time_to_run_ms){

    unsigned long start_time = millis();
    unsigned long end_time = start_time + time_to_run_ms;
    
    this->ON_motor();
    while( millis() < end_time && !this->signalHasChanged() ){

        this->runONEstep();

    }
    this->OFF_motor();
}

void Motor::Run_revolutions_per_minute( int rev_p_m, int step ){

    

}
