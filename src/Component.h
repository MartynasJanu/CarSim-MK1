/* 
 * File:   Component.h
 * Author: tsynique
 *
 * Created on August 19, 2015, 12:18 AM
 */

#ifndef COMPONENT_H
#define	COMPONENT_H

#include "Resource.h"
#include "Base/CyclableLoop.h"
#include <list>
using namespace std;

class Component : public CyclableLoop {
public:
    Component();
    virtual ~Component();
    
    /**
     * Tells the Component to aquire a certain amount of resource
     * 
     * @param resource
     * @param amount measured in internal units of measurement for particular resource
     * @return (float) amount actually taken
     */
    float giveResource(const Resource *resource, float amount);
    
    void Update(float dt);
    void UpdateEnergy();
    void UpdateAcceleration();
    void UpdateSpeed();
    void UpdatePosition();
    
    void advanceCycle(float advance);
public:
    list<Component*> outputs;
    list<Component*> inputs;
    list<Resource*> resources;
};

#endif	/* COMPONENT_H */

