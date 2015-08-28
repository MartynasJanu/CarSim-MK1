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

class SparkplugComponent : public Component, public ElectricityStorable {
public:
    SparkplugComponent();
    SparkplugComponent(const SparkplugComponent& orig);
    virtual ~SparkplugComponent();
private:

};

#endif	/* SPARKPLUG_H */

