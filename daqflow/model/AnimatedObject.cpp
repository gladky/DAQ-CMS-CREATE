/**
 * Project Untitled
 */


#include "AnimatedObject.h"

/**
 * AnimatedObject implementation
 */



AnimatedObject::AnimatedObject(int offset, uint32_t *leds){
    offset=offset;
    leds = leds;
    counter = 0;
}


void AnimatedObject::animate(){
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
