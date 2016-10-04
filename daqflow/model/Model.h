/**
 * Project Untitled
 */


#ifndef _MODEL_H
#define _MODEL_H


#include "Link.h"

class Model {

public: 
    Link *top1;
    Link *top2;
    Link *top3;
    Link *top4;

    /** example value 0xFF0000*/
    uint32_t leds [60];

    Model();

};



#endif //_MODEL_H
