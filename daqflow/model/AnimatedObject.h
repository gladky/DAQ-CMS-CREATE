/**
 * Project Untitled
 */

class AnimatedObject;

#ifndef _ANIMATEDOBJECT_H
#define _ANIMATEDOBJECT_H

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

    uint32_t *leds[];

    AnimatedObject(int offset, uint32_t *leds);

    virtual bool animateInsert() {};
    virtual bool animateExit() {};
    virtual bool animateProcess() {};
    void animate();

};

#endif //_ANIMATEDOBJECT_H
