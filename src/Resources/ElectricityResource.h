/* 
 * File:   ElectricityResource.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 9:00 PM
 */

#ifndef ELECTRICITYRESOURCE_H
#define	ELECTRICITYRESOURCE_H

#include "../Resource.h"

class ElectricityResource : public Resource {
public:
    ElectricityResource() {};
    ElectricityResource(float capacity): Resource(capacity) {};
    ElectricityResource(const ElectricityResource& orig);
    virtual ~ElectricityResource();
private:

};

#endif	/* ELECTRICITYRESOURCE_H */

