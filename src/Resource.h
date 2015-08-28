/* 
 * File:   Resource.h
 * Author: tsynique
 *
 * Created on August 19, 2015, 12:27 AM
 */

#ifndef RESOURCE_H
#define	RESOURCE_H

class Resource {
public:
    Resource():
        units(1.0f),
        units_max(1.0f)
    {}
    Resource(float amount):
        units(amount),
        units_max(amount)
    {}
    Resource(float amount, float amount_max):
        units(amount),
        units_max(amount_max)
    {}
    Resource(const Resource& orig);
    virtual ~Resource();
    
    void setMaxAmount(float amount, bool force = false);
    void setAmount(float amount, bool force = false);
    
    float getCurrentAmount();
    float getMaxAmount();
    
    float addAmount(float amount);
    float takeAmount(float amount);
private:
    float units;
    float units_max;
};

#endif	/* RESOURCE_H */

