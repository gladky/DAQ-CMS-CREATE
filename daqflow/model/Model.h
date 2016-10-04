/**
 * Project Untitled
 */


#ifndef _MODEL_H
#define _MODEL_H

#include <Arduino.h>
#include "Link.h"
#include <vector>

class Model {

public: 
    Link *top1;
    Link *top2;
    Link *top3;
    Link *top4;

    Model(std::vector<uint32_t> &leds);

    void animate();

};



#endif //_MODEL_H
