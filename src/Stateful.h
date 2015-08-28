/* 
 * File:   Stateful.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 10:40 PM
 */

#ifndef STATEFUL_H
#define	STATEFUL_H

class Stateful {
public:
    Stateful():
        state(0.0f),
        loop(false),
        state_ratio(1.0f)
    {}
    Stateful(const Stateful& orig);
    virtual ~Stateful();
    
    void setIsLooping(bool loop = true);
    bool getIsLooping();
    
    float addState(float amount);
    float getState();
    
    void setStateRatio(float ratio);
    float getStateRatio();
private:
    float state_ratio;
    
    float state;
    
    bool loop;
    
    void constraintState();
    int constraintLoopState(float sign);
};

#endif	/* STATEFUL_H */

