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
#include "Components/ElectricswitchComponent.h"
#include "Components/DistributorComponent.h"
#include <list>
#include <unistd.h>

const float TIMESTEP = 1.0/10.0;

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
    BatteryComponent battery;
    DistributorComponent distributor;
    // firing sequence 1-3-4-2
    SparkplugComponent sparkplug1(1);
    SparkplugComponent sparkplug3(3);
    SparkplugComponent sparkplug4(4);
    SparkplugComponent sparkplug2(2);
    
    // connect components
    distributor.input = &battery;
    
    // init components
    distributor.addOutput(&sparkplug1);
    distributor.addOutput(&sparkplug3);
    distributor.addOutput(&sparkplug4);
    distributor.addOutput(&sparkplug2);
    
    // add components to update list
    list<Component*> components;
    components.push_back(&battery);
    components.push_back(&sparkplug1);
    components.push_back(&sparkplug3);
    components.push_back(&sparkplug4);
    components.push_back(&sparkplug2);
    components.push_back(&distributor);
    
    timespec time1, time2;
    float dt = 0.0f;
    
    float time = 0.0f;
    float TOD = 0.0f;
    while (true) {
        clock_gettime(CLOCK_REALTIME, &time1);

        for (int i = 0; i < 11111; i++) {

        }

        //usleep(1000 * 1500);
        
        clock_gettime(CLOCK_REALTIME, &time2);
        dt += diff(time1,time2);
        
        
        if (dt > TIMESTEP) {
            /// *** STEP
            time += dt;

            cout << "bat: " <<  battery.getElectricCapacityFraction()*100.0f << "%\n";
            
            if (sparkplug1.sparking) {
                cout << "[*] " << " ";
            } else {
                cout << "[ ] " << " ";
            }
            
            if (sparkplug2.sparking) {
                cout << "[*] " << " ";
            } else {
                cout << "[ ] " << " ";
            }
            
            if (sparkplug3.sparking) {
                cout << "[*] " << " ";
            } else {
                cout << "[ ] " << " ";
            }
            
            if (sparkplug4.sparking) {
                cout << "[*] " << "\n" << flush;
            } else {
                cout << "[ ] " << "\n" << flush;
            }
            
            for(list<Component*>::iterator i = components.begin(); i != components.end(); ++i) {
                (*i)->update(dt);
            }
            
            //cout << "\n";
            dt = 0;
        }
    }
    
    return 0;
}

