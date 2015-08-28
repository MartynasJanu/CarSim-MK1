/* 
 * File:   BatteryComponent.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 8:30 PM
 */

// http://cdn.instructables.com/F0R/VX9V/I77WP829/F0RVX9VI77WP829.LARGE.gif

#ifndef BATTERYCOMPONENT_H
#define	BATTERYCOMPONENT_H

#include "../Component.h"
#include "../Storables/ElectricityStorable.h"

class BatteryComponent : public Component, public ElectricityStorable {
public:
    BatteryComponent(float capacity = 15000.0f):
        ElectricityStorable(capacity)
    {}
    
    BatteryComponent(const BatteryComponent& orig);
    virtual ~BatteryComponent();
private:

};

#endif	/* BATTERYCOMPONENT_H */

