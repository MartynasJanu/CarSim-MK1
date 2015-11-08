/* 
 * File:   DistributorComponent.h
 *
 * Created on November 8, 2015, 2:54 AM
 */

#ifndef DISTRIBUTORCOMPONENT_H
#define	DISTRIBUTORCOMPONENT_H

#include "../Component.h"
#include "../Stateful.h"

class DistributorComponent : public Component, public Stateful {
public:
    DistributorComponent() :
        input(0)
    {
        this->setIsLooping(true);
        //this->active = 0;
    }
        
    DistributorComponent(const DistributorComponent& orig);
    virtual ~DistributorComponent();
    
    void addOutput(Component* component);
    
    void update(float dt);
    
public:
    Component* input;
            
private: 
    list<Component*>::iterator active;
    list<Component*> outputs;
    
};

#endif	/* DISTRIBUTORCOMPONENT_H */

