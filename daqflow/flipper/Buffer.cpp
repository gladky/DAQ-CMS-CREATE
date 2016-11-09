// Generated from /cms.flipper/src/main/java/Buffer.java
#include "Buffer.hpp"

#include "Data.hpp"
#include "Dispatcher.hpp"
#include "FlipperObject.hpp"
#include "SimpleFifoQueue.hpp"
#include "Sound.hpp"
#include "SoundPlayer.hpp"
#include "Clickable.hpp"




Buffer::Buffer(string name, int capacity, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked_):
Clickable( name, capacity,  progressStep, timeoutStep, button, soundPlayer)
{
    soundMasked = soundMasked_;
}

bool Buffer::backpressure()
{
    bool backpressure = dispatcher->isBackpressure();
    return backpressure;
}

void Buffer::dispatch()
{
    //Serial.print("Buffer::dispatch: about to");
    if(!queue->peek()->isDispatched()) {
        int choosenIndex = dispatcher->findAvailableTarget();
        if(!dispatcher->isBackpressure()) {
            queue->peek()->setDispatched(true);
            queue->peek()->setTargetIndex(choosenIndex);
        }
    }
    //Serial.println("Buffer::dispatch: done");
}

Dispatcher* Buffer::getDispatcher()
{
    return dispatcher;
}

void Buffer::setDispatcher(Dispatcher* dispatcher)
{
    this->dispatcher = dispatcher;
}

void Buffer::registerAcceptedSound(bool interesting)
{
    if(!soundMasked) {
        if(interesting) {
            soundPlayer->register_(AcceptedInterestingFragments);
        } else {
            soundPlayer->register_(AcceptedNonInterestingFragments);
        }
    }
}

void Buffer::registerMissedSound(bool interesting)
{
    if(!soundMasked) {
        if(interesting) {
            soundPlayer->register_(MissedInterestingFragments);
        } else {
            soundPlayer->register_(MissedNotInterestingFragments);
        }
    }
}

void Buffer::reserve()
{
    //Serial.print("Buffer::reserve: about to");
    Data* data = queue->peek();
    int reservedIndex = data->getTargetIndex();
    FlipperObject* target = dispatcher->getTarget(reservedIndex);
    FlipperObject* link = dispatcher->getLink(reservedIndex);
    target->setBusy(true);
    data->setTarget(link);

    //Serial.println("Buffer::reserve: done");
}
