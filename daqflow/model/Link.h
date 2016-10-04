/**
 * Project Untitled
 */


#ifndef _LINK_H
#define _LINK_H

#include  <Arduino.h>
#include "AnimatedObject.h"
#include <vector>


class Link: public AnimatedObject {
public: 
    int length;
    int step;
    int i;

    Link(int length, int step, int offset, std::vector<uint32_t> &leds);

    
    bool animateProcess();
    bool animateExit();
    bool animateInsert();
};

#endif //_LINK_H
