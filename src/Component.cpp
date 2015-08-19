/* 
 * File:   Component.cpp
 * Author: tsynique
 * 
 * Created on August 19, 2015, 12:18 AM
 */

#include "Component.h"

Component::Component() {
}

Component::~Component() {
    for(list<Component*>::iterator i = outputs.begin(); i != outputs.end(); ++i) {
        (*i)->~Component();
    }
    this->outputs.clear();
    
    for(list<Component*>::iterator i = inputs.begin(); i != inputs.end(); ++i) {
        (*i)->~Component();
    }
    this->inputs.clear();
    
    for(list<Resource*>::iterator i = resources.begin(); i != resources.end(); ++i) {
        (*i)->~Resource();
    }
    this->resources.clear();
}

void Component::Update(float dt) {
    float add = 1.0f * dt;
    advanceCycle(add);
}

void Component::advanceCycle(float advance) {
    float d = addCyclePosition(advance);

    for(list<Component*>::iterator i = outputs.begin(); i != outputs.end(); ++i) {
        (*i)->advanceCycle(-d);
    }
}
