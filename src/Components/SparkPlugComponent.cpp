/* 
 * File:   SparkPlug.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 8:18 PM
 */

// Spark plugs usually require voltage of 12,000–25,000 volts or more
// to "fire" properly, although it can go up to 45,000 volts
// Let's use: 20000 V
// 3 A
// 1 second

#include "SparkplugComponent.h"

SparkplugComponent::SparkplugComponent(const SparkplugComponent& orig) {
}

SparkplugComponent::~SparkplugComponent() {
}

void SparkplugComponent::update(float dt) {
    float el_needed = (3.0f * 1.0f) / 12.0f; // [F]
    float el_have = this->getElectricCapacity();
    float el_left_to_get = el_needed - el_have;
    
    for(list<Component*>::iterator i = inputs.begin(); i != inputs.end(); ++i) {
        el_left_to_get = el_needed - el_have;
        if (el_left_to_get <= 0) {
            this->triggerSpark();
            break;
        }
        
        ElectricityStorable* electricity_source = (dynamic_cast<ElectricityStorable*>(*i));
        if (electricity_source != 0) {
            float el = electricity_source->takeElectricity(12, 3, dt);
            this->giveElectricity(12, 3, dt);
            
            std::cout << this->getElectricCapacity() << std::endl;
        }
    }
    
    
}

void SparkplugComponent::triggerSpark() {
    if (this->getElectricCapacityFraction() < 0.9f) {
        return;
    }
    
    //for(list<Component*>::iterator i = outputs.begin(); i != outputs.end(); ++i) {
    //    ElectricityStorable* electricity_source = (dynamic_cast<ElectricityStorable*>(*i));
    //    if (electricity_source != 0) {
        this->drainElectricity();
    //    }
   // }
}