// Generated from /cms.flipper/src/main/java/Dispatcher.java
#include "Dispatcher.hpp"

#include "FlipperObject.hpp"
#include "Sound.hpp"
#include "SoundPlayer.hpp"


Dispatcher::Dispatcher(vector<FlipperObject*> targets_, vector<FlipperObject*> linksToTargets_, SoundPlayer* soundPlayer_) : NamedObject("Dispatcher")
{
    targets = targets_;
    linksToTarget = linksToTargets_;
    valid = false;
    backpressure = false;
    soundPlayer = soundPlayer_;
    result = -1;
}

FlipperObject* Dispatcher::getTarget(int id)
{
    return targets[id];
}

FlipperObject* Dispatcher::getLink(int id)
{
    return linksToTarget[id];
}

int Dispatcher::findAvailableTarget()
{

    //Serial.print("Dispatcher::findAvailableTarget: about to ");
    if(valid) {
        //Serial.print("Dispatcher::findAvailableTarget: stil valid ");
    } else {
        result = -1;
        vector<int> ready;

        /*Serial.print(", Available targets: ");
        Serial.print(targets.size());
        Serial.print(", iterating, ");*/

        for (int i = 0; i < targets.size(); i++) {
	    
            //Serial.print(targets[i]->getName().c_str());
            FlipperObject* bufu = targets[i];
	    //Serial.print(bufu->getName().c_str());
            
            if(!bufu->isBusy() && bufu->canAccept()) {
                ready.push_back(i);
            }
        }
        if(ready.size() > 0) {
            if(backpressure == true) {
                soundPlayer->register_(BackpressureOver);
            }
            backpressure = false;
            int choosenRandom = ready[0]; // except 0 put random 0:size
            int choosen = ready[0];
            result = choosenRandom;
            result = choosen;
            valid = true;
        } else {
            //Serial.println("Beginning backpressure, ready = 0");
            if(backpressure == false) {
                soundPlayer->register_(Backpressure);
            }
            backpressure = true;
        }
    }

    /*Serial.print("Dispatcher::findAvailableTarget: result: ");
    Serial.println(result);*/
    return result;
}

void Dispatcher::invalidate()
{
    result = -1;
    valid = false;
}

bool Dispatcher::isBackpressure()
{
    return backpressure;
}

int Dispatcher::getResult()
{
    return result;
}


