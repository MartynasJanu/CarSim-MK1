/* 
 * File:   CyclableLoop.h
 * Author: tsynique
 *
 * Created on August 19, 2015, 12:56 AM
 */

#ifndef CYCLABLELOOP_H
#define	CYCLABLELOOP_H

#include "BaseCyclable.h"


class CyclableLoop : public BaseCyclable {
public:
    CyclableLoop(float pos = 0.0f, float min = 0.0f, float max = 10.0f)
        :BaseCyclable(pos, max, min, min, max) {}
    virtual ~CyclableLoop();
    
    //float getCyclePosition();
private:

};

#endif	/* CYCLABLELOOP_H */

