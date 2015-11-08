/* 
 * File:   ElectricityStorable.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 8:33 PM
 */

#include "ElectricityStorable.h"

#include <iostream>

ElectricityStorable::ElectricityStorable() {
}
ElectricityStorable::ElectricityStorable(const ElectricityStorable& orig) {
}

ElectricityStorable::~ElectricityStorable() {
}

float ElectricityStorable::getElectricCapacity() {
    return this->electric_power.getCurrentAmount();
}

float ElectricityStorable::getElectricCapacityUntilFull() {
    return this->electric_power.getMaxAmount() - this->electric_power.getCurrentAmount();
}

float ElectricityStorable::getElectricCapacityFraction() {
    return this->electric_power.getCurrentAmount() / this->electric_power.getMaxAmount();
}

/**
 * 
 * @return Maximum voltage in volts
 */
float ElectricityStorable::getMaxVoltage() {
    const float fr = this->getElectricCapacityFraction();
    
    return 12.0f * (fr);
}

/**
 * 
 * @return Maximum amperage in ampers
 */
float ElectricityStorable::getMaxAmperage() {
    return 3.0f;
}

/**
 * Transfers electricity to a destination ElectricityStorable
 * 
 * @param ElectricityStorable dest - destination electricity storage object
 * @param time - seconds
 */
void ElectricityStorable::transferElectricity(
        ElectricityStorable& dest,
        float time
    ) {
    const float can_accept = dest.getElectricCapacityUntilFull();
    if (can_accept <= 0) {
        return;
    }
    
    const float cost = can_accept / (this->getMaxVoltage() * this->getMaxAmperage() * time);
    const float can_give = can_accept * (this->electric_power.takeAmount(cost) / cost);
    
    this->getElectricPower()->takeAmount(cost);
    dest.getElectricPower()->addAmount(can_give);
}
