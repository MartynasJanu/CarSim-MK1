/* 
 * File:   ElectricityStorable.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 8:33 PM
 */

// http://hypertextbook.com/facts/1999/DeniseLai.shtml

// [F] = ([A] * [s]) / [V]

#ifndef ELECTRICITYSTORABLE_H
#define	ELECTRICITYSTORABLE_H

#include "../Resources/ElectricityResource.h"

class ElectricityStorable {
public:
    ElectricityStorable();
    ElectricityStorable(float amount, float capacity) {
        electric_capacity.setMaxAmount(capacity, true);
        electric_capacity.setAmount(amount, true);
    }
    ElectricityStorable(float capacity) {
        electric_capacity.setMaxAmount(capacity, true);
        electric_capacity.setAmount(capacity, true);
    }
    ElectricityStorable(const ElectricityStorable& orig);
    virtual ~ElectricityStorable();
    
    float getElectricCapacity();
    float getElectricCapacityFraction();
    float takeElectricity(float volts, float ampers, float seconds);
    float giveElectricity(float volts, float ampers, float seconds);
    
    void drainElectricity();
    void drainElectricity(float amount);
private:
    ElectricityResource electric_capacity;
};

#endif	/* ELECTRICITYSTORABLE_H */
