/* 
 * File:   SparkPlug.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 8:17 PM
 */

#ifndef SPARKPLUG_H
#define	SPARKPLUG_H

#include "../Component.h"
#include "../Storables/ElectricityStorable.h"
#include <iostream>

class SparkplugComponent : public Component, public ElectricityStorable {
public:
    SparkplugComponent(float capacity = 3.0f/12.0f):
        ElectricityStorable(0.0f, capacity)
    {}
    SparkplugComponent(const SparkplugComponent& orig);
    virtual ~SparkplugComponent();
    
    void update(float dt);
private:
    void triggerSpark();
};

#endif	/* SPARKPLUG_H */

