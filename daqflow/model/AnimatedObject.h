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
    
    uint32_t *leds[];

    AnimatedObject(int offset, uint32_t *leds);

    bool animateInsert();
    
    bool animateExit();
    
    bool animateProcess();


    void animate();

};

#endif //_ANIMATEDOBJECT_H
