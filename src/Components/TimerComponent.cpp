/* 
 * File:   TimerComponent.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 10:37 PM
 */

#include "TimerComponent.h"
#include <iostream>

TimerComponent::TimerComponent() {
    this->setIsLooping(true);
}

TimerComponent::TimerComponent(const TimerComponent& orig) {
}

TimerComponent::~TimerComponent() {
}

void TimerComponent::update(float dt) {
    int looped = (int)this->addState(dt);
    if (looped > 0) {
        std::cout << "TICK " << (1.0f/dt) << "FPS\n";
    }
}

