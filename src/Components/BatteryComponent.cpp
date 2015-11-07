/* 
 * File:   BatteryComponent.cpp
 * Author: tsynique
 * 
 * Created on August 28, 2015, 8:30 PM
 */

#include "BatteryComponent.h"

BatteryComponent::BatteryComponent(const BatteryComponent& orig) {
}

BatteryComponent::~BatteryComponent() {
}

void BatteryComponent::update(float dt) {
    if (this->getElectricCapacity() == 0.0f) return;
    
    for(list<Component*>::iterator i = outputs.begin(); i != outputs.end(); ++i) {
        ElectricityStorable* el_store = (dynamic_cast<ElectricityStorable*>(*i));
        if (el_store != 0) {
            this->transferElectricity(*el_store, dt);
        }
    }
}
