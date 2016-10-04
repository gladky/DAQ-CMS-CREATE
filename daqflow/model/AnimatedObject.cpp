/**
 * Project Untitled
 */


#include "AnimatedObject.h"
#include <vector>

/**
 * AnimatedObject implementation
 */



AnimatedObject::AnimatedObject(int offset, std::vector<uint32_t> &_leds):
  leds(_leds)
{
    offset=offset;
    // thisleds = leds;
    counter = 0;
    state = 0;
}


void AnimatedObject::animate(){


    Serial.print("Animate with state ");
    Serial.println(state);

    bool finished = false;
    if(state == 1){
        finished = animateInsert();
    } else if(state ==2){
        finished = animateProcess();
    } else if(state == 3){
        finished =animateExit();   
    }
   
    if(finished){
        state = (state +1)%4;
    }
}
