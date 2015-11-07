/* 
 * File:   ElectricityStorable.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 8:33 PM
 */

// http://hypertextbook.com/facts/1999/DeniseLai.shtml
// [F] = ([A] * [s]) / [V]

// resource: watt-hours Wh

#ifndef ELECTRICITYSTORABLE_H
#define	ELECTRICITYSTORABLE_H

#include "../Resources/ElectricityResource.h"

class ElectricityStorable {
public:
    ElectricityStorable();
    ElectricityStorable(float amount, float capacity) {
        electric_power.setMaxAmount(capacity, true);
        electric_power.setAmount(amount, true);
    }
    ElectricityStorable(float capacity) {
        electric_power.setMaxAmount(capacity, true);
        electric_power.setAmount(capacity, true);
    }
    ElectricityStorable(const ElectricityStorable& orig);
    virtual ~ElectricityStorable();
    
    float getElectricCapacity();
    float getElectricCapacityFraction();
    float getElectricCapacityUntilFull();
    
    float getMaxVoltage();
    float getMaxAmperage();
    
    void transferElectricity(ElectricityStorable& dest, float time);
    
    ElectricityResource* getElectricPower() {
        return &this->electric_power;
    }
private:
    ElectricityResource electric_power;
};

#endif	/* ELECTRICITYSTORABLE_H */
