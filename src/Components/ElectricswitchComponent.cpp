/* 
 * File:   ElectricswitchComponent.cpp
 * Author: tsynique
 * 
 * Created on August 29, 2015, 1:50 AM
 */

#include <list>

#include "ElectricswitchComponent.h"

ElectricswitchComponent::ElectricswitchComponent(const ElectricswitchComponent& orig) {
}

ElectricswitchComponent::~ElectricswitchComponent() {
}

void ElectricswitchComponent::setSwitchedOn(bool on) {
    if (this->switchedOn == on || (this->input == 0 && this->output == 0)) {
        return;
    }
    
    this->switchedOn = on;
    
    if (this->switchedOn) {
        this->input->outputs.push_back(this->output);
        //this->output->inputs.push_back(this->input);
    } else {
        this->input->outputs.remove(this->output);
        //this->output->inputs.remove(this->input);
    }
}

