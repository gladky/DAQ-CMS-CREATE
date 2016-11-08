// Generated from /cms.flipper/src/main/java/Buffer.java
#include <Buffer.hpp>

#include <Data.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
#include <SimpleFifoQueue.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>




void Buffer::Buffer(string name, int capacity, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked_):
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
    if(!queue->peek()->isDispatched()) {
        int choosenIndex = dispatcher->findAvailableTarget();
        if(!dispatcher->isBackpressure()) {
            queue->peek()->setDispatched(true);
            queue->peek()->setTargetIndex(choosenIndex);
        }
    }
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
            soundPlayer->register_(Sound::AcceptedInterestingFragments);
        } else {
            soundPlayer->register_(Sound::AcceptedNonInterestingFragments);
        }
    }
}

void Buffer::registerMissedSound(bool interesting)
{
    if(!soundMasked) {
        if(interesting) {
            soundPlayer->register_(Sound::MissedInterestingFragments);
        } else {
            soundPlayer->register_(Sound::MissedNotInterestingFragments);
        }
    }
}

void Buffer::reserve()
{
    Data data = queue->peek();
    int reservedIndex = npc(data)->getTargetIndex();
    FlipperObject target = dispatcher->getTarget(reservedIndex);
    FlipperObject link = dispatcher->getLink(reservedIndex);
    target->setBusy(true);
    data->setTarget(link);
}
