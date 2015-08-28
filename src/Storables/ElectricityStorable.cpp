/* 
 * File:   ElectricityStorable.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 8:33 PM
 */

#include "ElectricityStorable.h"

ElectricityStorable::ElectricityStorable() {
}
ElectricityStorable::ElectricityStorable(const ElectricityStorable& orig) {
}

ElectricityStorable::~ElectricityStorable() {
}

float ElectricityStorable::getElectricCapacity() {
    return this->electric_capacity.getCurrentAmount();
}

float ElectricityStorable::getElectricCapacityFraction() {
    return this->electric_capacity.getCurrentAmount() / this->electric_capacity.getMaxAmount();
}

float ElectricityStorable::takeElectricity(float volts, float ampers, float seconds) {
    float capacity_cost = (ampers * seconds) / volts;
    return this->electric_capacity.takeAmount(capacity_cost);
}

/*
 @return fraction that was not added
 */
float ElectricityStorable::giveElectricity(float volts, float ampers, float seconds) {
    float capacity_to_add = (ampers * seconds) / volts;
    return this->electric_capacity.addAmount(capacity_to_add) / capacity_to_add;
}

void ElectricityStorable::drainElectricity() {
    this->electric_capacity.setAmount(0, true);
}
void ElectricityStorable::drainElectricity(float amount) {
    this->electric_capacity.takeAmount(amount);
}

