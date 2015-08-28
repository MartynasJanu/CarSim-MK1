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
    ElectricityStorable(float capacity) {
        electric_capacity.setMaxAmount(capacity, true);
        electric_capacity.setAmount(capacity, true);
    }
    ElectricityStorable(const ElectricityStorable& orig);
    virtual ~ElectricityStorable();
    
    ElectricityResource electric_capacity;
private:

};

#endif	/* ELECTRICITYSTORABLE_H */
