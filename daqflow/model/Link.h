/**
 * Project Untitled
 */


#ifndef _LINK_H
#define _LINK_H

#include "AnimatedObject.h"


class Link: public AnimatedObject {
public: 
    int length;
    int step;
    int i;

    Link(int length, int step, int offset, uint32_t *leds);
};

#endif //_LINK_H
