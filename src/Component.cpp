/* 
 * File:   Component.cpp
 * Author: tsynique
 * 
 * Created on August 19, 2015, 12:18 AM
 */

#include "Component.h"
#include "Storables/ElectricityStorable.h"

#include <iostream>
#include <type_traits>

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
}

void Component::update(float dt) {

}