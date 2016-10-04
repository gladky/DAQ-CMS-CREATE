/**
 * Project Untitled
 */


#ifndef _MODEL_H
#define _MODEL_H

#include <Arduino.h>
#include "Link.h"
#include "Event.h"
#include <vector>

class Model {

public: 
    Link *top1 = NULL;
    Link *top2 = NULL;
    Link *top3 = NULL;
    Link *top4 = NULL;

    Model(std::vector<uint32_t> &leds);

    void animate();

    //void insert(Event event);

};



#endif //_MODEL_H
