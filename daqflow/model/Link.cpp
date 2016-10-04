/**
 * Project Untitled
 */


#include "Link.h"

/**
 * Link implementation
 */

Link::Link(int length, int step, int offset,uint32_t *leds):AnimatedObject(offset,leds){

    length = length;
    step = step;
    i = 0;
    state = 0;
}

bool AnimatedObject::animateInsert(){
    uint32_t v = 0xFF0000;
    leds[++counter] = &v; 
    return false;
}

bool AnimatedObject::animateProcess(){
    
    return false;
    
}

bool AnimatedObject::animateExit(){
    
    return false;
    
}
