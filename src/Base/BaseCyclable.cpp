/* 
 * File:   BaseCyclable.cpp
 * Author: tsynique
 * 
 * Created on August 19, 2015, 12:44 AM
 */

#include "BaseCyclable.h"

BaseCyclable::BaseCyclable(float pos,
            float max,
            float min,
            float once_max,
            float once_min) {
    this->cycle_position = pos;
    this->cycle_max = max;
    this->cycle_min = min;
    this->cycle_once_max = once_max;
    this->cycle_once_min = once_min;
}

BaseCyclable::~BaseCyclable() {
}

float BaseCyclable::getCyclePosition() {
    return this->cycle_position;
}
float BaseCyclable::setCyclePosition(float val, bool force) {
    this->cycle_position = val;
    
    if (!force) {
        this->constrainCyclePosition();
    }
    
    return this->cycle_position;
}
float BaseCyclable::addCyclePosition(float val, bool force) {
    float pos = this->cycle_position;
    
    this->cycle_position += val;
    
    if (!force) {
        this->constrainCyclePosition();
    }
    
    float d = this->cycle_position - pos;
    
    return d;
}

void BaseCyclable::constrainCyclePosition() {
    while (this->cycle_position >= this->cycle_max) {
        this->cycle_position -= this->cycle_max;
    }
    while (this->cycle_position <= this->cycle_min) {
        this->cycle_position += this->cycle_max;
    }
}