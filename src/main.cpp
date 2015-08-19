/* 
 * File:   main.cpp
 * Created on August 19, 2015, 12:13 AM
 */

#include <iostream>
#include <ctime>
#include "Component.h"
#include <unistd.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Component* cog1 = new Component();
    Component* cog2 = new Component();
    cog2->setCyclePosition(5.0f, true);
    Component* cog3 = new Component();
    
    // 1 -> 2
    cog1->outputs.push_back(cog2);
    // 2 -> 3
    cog2->outputs.push_back(cog3);
    // 3 -> 2
    cog3->inputs.push_back(cog2);
    // 2 -> 1
    cog2->inputs.push_back(cog1);
    
    struct timespec start, finish;
    float elapsed;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (true) {
        usleep(1000 * 1000);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += ((float)finish.tv_nsec - (float)start.tv_nsec) / (float)1000000000.0f;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        cog1->Update(elapsed);
        
        cout << cog1->getCyclePosition() << ":";
        cout << cog2->getCyclePosition() << ":";
        cout << cog3->getCyclePosition() << " Error: ";
        float error = (cog1->getCyclePosition() - cog2->getCyclePosition() + cog3->getCyclePosition());
        cout << error << endl;
    }
    
    return 0;
}
