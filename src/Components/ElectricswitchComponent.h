/* 
 * File:   ElectricswitchComponent.h
 * Author: tsynique
 *
 * Created on August 29, 2015, 1:50 AM
 */
// Electric on directional switch between two components

#ifndef ELECTRICSWITCHCOMPONENT_H
#define	ELECTRICSWITCHCOMPONENT_H

#include "../Component.h"

class ElectricswitchComponent : public Component {
public:
    ElectricswitchComponent() :
        switchedOn(false),
        input(0),
        output(0)
    {}
    ElectricswitchComponent(const ElectricswitchComponent& orig);
    virtual ~ElectricswitchComponent();
    
    void setSwitchedOn(bool on);
    Component* input;
    Component* output;
private:
    bool switchedOn;
};

#endif	/* ELECTRICSWITCHCOMPONENT_H */

