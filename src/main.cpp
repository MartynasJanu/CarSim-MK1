/* 
 * File:   main.cpp
 * Created on August 19, 2015, 12:13 AM
 */

#include <iostream>
#include <ctime>
#include "Component.h"
#include "Components/SparkplugComponent.h"
#include "Components/BatteryComponent.h"
#include "Components/TimerComponent.h"
#include "Stateful.h"
#include <unistd.h>

const float TIMESTEP = 1.0/60.0;

using namespace std;

float start_time, end_time, elapsed;

float diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
            temp.tv_sec = end.tv_sec-start.tv_sec-1;
            temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
            temp.tv_sec = end.tv_sec-start.tv_sec;
            temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return (float)temp.tv_sec + ((float)temp.tv_nsec / 1000000000.0f);
}


/*
 * 
 */
int main(int argc, char** argv) {
    // create components
    SparkplugComponent sp;
    BatteryComponent bat;
    TimerComponent timer;
    
    // connect components
    sp.inputs.push_back(&bat);
    bat.outputs.push_back(&sp);
    
    timer.setStateRatio(0.5f);
    
    timespec time1, time2;
    float dt = 0.0f;
    
    while (true) {
        clock_gettime(CLOCK_REALTIME, &time1);

        for (int i = 0; i < 11111; i++) {

        }

        //usleep(1000 * 1500);
        
        clock_gettime(CLOCK_REALTIME, &time2);
        dt += diff(time1,time2);
        if (dt > TIMESTEP) {
            /// *** STEP
            timer.update(dt);
            sp.update(dt);
            bat.update(dt);
            
            cout << "bat: " <<  bat.getElectricCapacity() << " | ";
            cout << "sp: " <<  sp.getElectricCapacity() << "\n";
            dt = 0;
        }
    }
    
    return 0;
}

