/**
 * Project Untitled
 */


#include "Link.h"
#include <vector>

/**
 * Link implementation
 */

Link::Link(int length, int step, int offset, std::vector<uint32_t> &leds):AnimatedObject(offset,leds){

    length = length;
    step = step;
    i = 0;
    state = 1;
}

bool Link::animateInsert(){

    counter = 0;
    leds[0] = colorOff;
    leds[1] = colorOff;
    return true;
}

bool Link::animateProcess(){


    Serial.print("Before animation first element ");
    Serial.println(leds[0]);
    leds[0] = color1;
    leds[1] = color1;

    Serial.print("Processing in link with counter: ");
    Serial.println(counter);

    leds[counter] = color1; 
    if(counter - length >=0){
        leds[counter - length] = colorOff;
    }
    if(state > 5){
        return true;
    }


    Serial.print("After animation first element ");
    Serial.println((unsigned int)leds[0]);


    counter++;
    return false;
    
}

bool Link::animateExit(){
    
    counter = 0;
    return true;
    
}
