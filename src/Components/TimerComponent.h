/* 
 * File:   TimerComponent.h
 * Author: tsynique
 *
 * Created on August 28, 2015, 10:37 PM
 */

#ifndef TIMERCOMPONENT_H
#define	TIMERCOMPONENT_H

#include "../Component.h"
#include "../Stateful.h"

class TimerComponent: public Component, public Stateful {
public:
    TimerComponent();
    TimerComponent(const TimerComponent& orig);
    virtual ~TimerComponent();
    
    void update(float dt);
private:

};

#endif	/* TIMERCOMPONENT_H */

