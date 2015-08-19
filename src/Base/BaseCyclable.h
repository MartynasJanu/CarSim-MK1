/* 
 * File:   BaseCyclable.h
 * Author: tsynique
 *
 * Created on August 19, 2015, 12:44 AM
 */

#ifndef BASECYCLABLE_H
#define	BASECYCLABLE_H

class BaseCyclable {
public:
    BaseCyclable(
            float pos = 0.0f,
            float max = 1.0f,
            float min = 0.0f,
            float once_max = 1.0f,
            float once_min = 0.0f
        );
    virtual ~BaseCyclable();
    
    virtual float getCyclePosition();
    float setCyclePosition(float val, bool force = false);
    float addCyclePosition(float val, bool force = false);
private:
    // current position in the cycle stored
    float cycle_position;
    // upper value of the cycle progress
    float cycle_max;
    // lower value of the cycle progress
    float cycle_min;
    // cycle_position once the upper value has been reached
    float cycle_once_max;
    // cycle_position once the lower value has been reached
    float cycle_once_min;
    
    void constrainCyclePosition();
};

#endif	/* BASECYCLABLE_H */

