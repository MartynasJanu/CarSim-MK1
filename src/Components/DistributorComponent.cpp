/* 
 * File:   DistributorComponent.cpp
 * Author: tsynique
 * 
 * Created on November 8, 2015, 2:54 AM
 */

#include <list>
#include <type_traits>
#include "DistributorComponent.h"
#include "SparkplugComponent.h"
#include <iostream>

using namespace std;

DistributorComponent::~DistributorComponent() {
    outputs.clear();
}

void DistributorComponent::addOutput(Component* component) {
    this->outputs.push_back(component);
    this->setStateRatio((float)this->outputs.size());
    
    if (this->outputs.size() == 1 && this->input != 0) {
        this->active = this->outputs.begin();
        this->input->outputs.push_back((*this->active));
    }
}

void DistributorComponent::update(float dt) {
    int looped = (int)this->addState(dt);
    
    if (looped == 1) {
        this->input->outputs.remove((*this->active));
        // trigger spark plug
        SparkplugComponent *sparkplug = dynamic_cast<SparkplugComponent*>(*this->active);
        if (sparkplug != 0) {
            sparkplug->triggerSpark();
        }
        
        ++this->active;
        if (this->active == this->outputs.end()) {
            this->active = this->outputs.begin();
        }
        
        this->input->outputs.push_back((*this->active));
    }
}