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

const float voltage = 12.0f;
const float amperage = 3.0f;
const float time_seconds = 0.003f;
const float Ws = voltage * amperage * time_seconds;
    
class SparkplugComponent : public Component, public ElectricityStorable {
public:
    SparkplugComponent(int number, float capacity = Ws):
        ElectricityStorable(0.0f, capacity)
    {
        this->number = number;
        this->sparking = false;
    }
    SparkplugComponent(const SparkplugComponent& orig);
    virtual ~SparkplugComponent();
    
    void update(float dt);
    void triggerSpark();
    
    bool sparking;
private:
    int number;
};

#endif	/* SPARKPLUG_H */

