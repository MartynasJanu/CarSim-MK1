/* 
 * File:   Stateful.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 10:40 PM
 */

#include "Stateful.h"

Stateful::Stateful(const Stateful& orig) {
}

Stateful::~Stateful() {
}

/**
 * @return float - amount the state changes (non-looping)
 *         float - times the state looped
*/
float Stateful::addState(float amount) {
    if (!this->loop) {
        const float init_state = this->state;
        this->state += amount * this->state_ratio;
        return this->state - init_state;
    } else {
        this->state += amount * this->state_ratio;
        return (float)this->constraintLoopState(amount);
    }
}

float Stateful::getState() {
    return this->state;
}

void Stateful::constraintState() {
    if (this->state > 1.0f) {
        this->state = 1.0f;
    } else if (this->state < 0.0f) {
        this->state = 0.0f;
    }
}

int Stateful::constraintLoopState(float sign) {
    int looped = 0;
    
    while (sign > 0 && this->state >= 1.0f) {
        this->state -= 1.0f;
        ++looped;
    }
    while (sign < 0 && this->state < 0.0f) {
        this->state += 1.0f;
        ++looped;
    }
    return looped;
}

void Stateful::setStateRatio(float ratio) {
    this->state_ratio = ratio;
}
float Stateful::getStateRatio() {
    return this->state_ratio;
}

void Stateful::setIsLooping(bool loop) {
    this->loop = loop;
    if (!loop) {
        this->constraintState();
    } else {
        this->constraintLoopState(1.0f);
    }
}

bool Stateful::getIsLooping() {
    return this->loop;
}

