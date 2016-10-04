/**
 * Project Untitled
 */


#include "AnimatedObject.h"
#include <vector>

/**
 * AnimatedObject implementation
 */



AnimatedObject::AnimatedObject(int _offset, std::vector<uint32_t> &_leds):
  leds(_leds)
{
    offset=_offset;
    // thisleds = leds;
    counter = 0;
    state = 0;
    successor = NULL;
}


void AnimatedObject::animate(){


    Serial.print("Animate with state ");
    Serial.println(state);

    bool finished = false;
    bool passToSuccessor = false;
    if(state == 0){
        if(newEvent == true){
            Serial.print("Fire the object");
            state = 1;
            newEvent = false;
        }
    }
    if(state == 1){
        finished = animateInsert();
    } else if(state ==2){
        finished = animateProcess();
        if(finished){
            passToSuccessor = true;
        }
    } else if(state == 3){
        finished =animateExit();   
    }
   
    if(finished){
        state = (state +1)%4;
    }

    if(passToSuccessor){
        Serial.print("Fire the object");
        state = (state +1)%4;
        if(successor != NULL){
            successor->insert(event);
        } else{
            Serial.print("Object has no successor");
        }
    }
}

void AnimatedObject::insert(Event *event_){
    event = event_;
    newEvent = true;
}
