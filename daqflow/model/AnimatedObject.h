/**
 * Project Untitled
 */

class AnimatedObject;

#ifndef _ANIMATEDOBJECT_H
#define _ANIMATEDOBJECT_H


#include <Arduino.h>
#include <vector>
#include "Event.h"

class AnimatedObject {
public: 
    int exitDuration;
    int insertDuration;
    int processDuration;
    AnimatedObject *successor;
    AnimatedObject *predecessor;

    int state; // 0 - empty, 1- insert animation, 2 - process animation, 3 - exit animation, transitions: 0->1->2->3->0
    int offset;
    int counter;
    
    uint32_t color1 = 0xFF0000;
    uint32_t colorOff = 0;

    std::vector<uint32_t> &leds;

    Event *event;
    bool newEvent = false;

    AnimatedObject(int offset, std::vector<uint32_t> &leds);

    virtual bool animateInsert() {};
    virtual bool animateExit() {};
    virtual bool animateProcess() {};
    void insert(Event *event);
    void animate();

};

#endif //_ANIMATEDOBJECT_H
