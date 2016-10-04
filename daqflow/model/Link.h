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

    Link(int length, int step, int offset);
};

#endif //_LINK_H
