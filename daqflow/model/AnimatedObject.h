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

    int offset;
    
    uint32_t *leds[];

    AnimatedObject(int offset, uint32_t *leds);

    void animateInsert();
    
    void animateExit();
    
    void animateProcess();

};

#endif //_ANIMATEDOBJECT_H
