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

bool Link::animateInsert(){

    counter = 0;
    return true;
}

bool Link::animateProcess(){
    
    leds[counter] = &color1; 
    leds[counter - length] = &colorOff;
    state++;
    if(state > 5){
       return true;
    }

    counter++;
    return false;
    
}

bool Link::animateExit(){
    
    counter = 0;
    return true;
    
}
