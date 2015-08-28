/* 
 * File:   main.cpp
 * Created on August 19, 2015, 12:13 AM
 */

#include <iostream>
#include <ctime>
#include "Component.h"
#include "Components/SparkplugComponent.h"
#include "Components/BatteryComponent.h"
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SparkplugComponent *sp = new SparkplugComponent();
    BatteryComponent *bat = new BatteryComponent();
    
    struct timespec start, finish;
    float elapsed;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (true) {
        usleep(1000 * 1000);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += ((float)finish.tv_nsec - (float)start.tv_nsec) / (float)1000000000.0f;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        
    }
    
    return 0;
}
