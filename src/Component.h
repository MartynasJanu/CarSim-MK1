/* 
 * File:   Component.h
 * Author: tsynique
 *
 * Created on August 19, 2015, 12:18 AM
 */

#ifndef COMPONENT_H
#define	COMPONENT_H

#include "Resource.h"
#include <list>
using namespace std;

class Component {
public:
    Component();
    virtual ~Component();
    
    void update(float dt);
public:
    list<Component*> outputs;
    list<Component*> inputs;
    list<Resource*> resources;
};

#endif	/* COMPONENT_H */

