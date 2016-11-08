// Generated from /cms.flipper/src/main/java/Dispatcher.java
#include <Dispatcher.hpp>

#include <FlipperObject.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>


Dispatcher::Dispatcher(vector<FlipperObject*> targets_, vector<FlipperObject*> linksToTargets_, SoundPlayer* soundPlayer_) : NamedObject("Dispatcher")
{
    targets = targets_;
    linksToTarget = linksToTargets_;
    valid = false;
    backpressure = false;
    soundPlayer = soundPlayer_;
}

FlipperObject* Dispatcher::getTarget(int id)
{
    return targets->get(id);
}

FlipperObject* Dispatcher::getLink(int id)
{
    return linksToTarget->get(id);
}

int Dispatcher::findAvailableTarget()
{
    if(valid) {
    } else {
        result = -1;
        vector<int> ready = new vector<int>();
        for (int i = 0; i < targets->size(); i++) {
            FlipperObject bufu = targets->get(i);
            if(!bufu->isBusy() && bufu->canAccept()) {
                ready->add(i);
            }
        }
        if(ready->size() > 0) {
            if(backpressure == true) {
                soundPlayer->register_(Sound::BackpressureOver);
            }
            backpressure = false;
            int choosenRandom = ready->get(0); // except 0 put random 0:size
            int choosen = ready->get(0);
            result = choosenRandom;
            result = choosen;
            valid = true;
        } else {
            if(backpressure == false) {
                soundPlayer->register_(Sound::Backpressure);
            }
            backpressure = true;
        }
    }
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

int32_t Dispatcher::getResult()
{
    return result;
}


