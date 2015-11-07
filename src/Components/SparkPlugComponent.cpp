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
    if (this->getElectricCapacityFraction() >= 0.99f) {
        triggerSpark();
    }
}

void SparkplugComponent::triggerSpark() {
    if (this->getElectricCapacityFraction() < 0.9f) {
        return;
    }
    
    //this->getElectricPower()->setAmount(0, true);
   // std::cout << "SPARK!\n";
    
    //for(list<Component*>::iterator i = outputs.begin(); i != outputs.end(); ++i) {
    //    ElectricityStorable* electricity_source = (dynamic_cast<ElectricityStorable*>(*i));
    //    if (electricity_source != 0) {
        
    //    }
    //}
}