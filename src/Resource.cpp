/* 
 * File:   Resource.cpp
 * Author: tsynique
 * 
 * Created on August 19, 2015, 12:27 AM
 */

#include "Resource.h"

Resource::~Resource() {
}

float Resource::getCurrentAmount() {
    return this->units;
}

float Resource::getMaxAmount() {
    return this->units_max;
}

float Resource::addAmount(float amount) {
    // amount that can be added without overflowing
    float capacity = this->units_max - this->units;
    
    // if all amount can be added, 
    // add and return zero remainder
    if (capacity >= amount) {
        this->units += amount;
        amount = 0.0f;
    // otherwise, add max possible
    // and return remainder
    } else {
        amount -= capacity;
        this->units = this->units_max;
    }
    
    return amount;
}

float Resource::takeAmount(float amount) {
    // Not enough or nothing will be left
    if (amount >= this->units) {
        amount = this->units;
        this->units = 0.0f;
    // enough to satisfy the request
    } else {
        this->units -= amount;
    }
    
    return amount;
}

void Resource::setMaxAmount(float amount, bool force) {
    this->units_max = amount;
    if (force && this->units > this->units_max) {
        this->units = this->units_max;
    }
}

void Resource::setAmount(float amount, bool force) {
    this->units = amount;
    if (force && this->units > this->units_max) {
        this->units = this->units_max;
    }
}
