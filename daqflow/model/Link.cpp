/**
 * Project Untitled
 */


#include "Link.h"
#include <vector>

/**
 * Link implementation
 */

Link::Link(int _length, int _step, int _offset, std::vector<uint32_t> &leds):AnimatedObject(_offset,leds){

    length = _length;
    //offset = _offset;
    step = _step;
    i = 0;
    state = 0;
}

bool Link::animateInsert(){

    counter = 0;
    //leds[0] = colorOff;
    //leds[1] = colorOff;
    return true;
}

bool Link::animateProcess(){

    int eventLen = 4;


    //Serial.print("Before animation first element ");
    //Serial.println(leds[0]);
    //leds[0] = color1;
    //leds[1] = colorOff;

    Serial.print("Processing in link with counter: ");
    Serial.print(counter);
    Serial.print(", length: ");
    Serial.print(length);

    if(counter < length){
        leds[counter + offset] = color1; 
    }
    if(counter - eventLen >=0){
        leds[counter - eventLen + offset] = colorOff;
    }
    if(counter > length+eventLen){
        Serial.println("");
        Serial.println("Finished here");
        return true;
    }



    counter++;
    return false;
    
}

bool Link::animateExit(){
    
    counter = 0;
    return true;
    
}
