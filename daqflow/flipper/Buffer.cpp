// Generated from /cms.flipper/src/main/java/Buffer.java
#include <Buffer.hpp>

#include <Data.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
#include <SimpleFifoQueue.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>




void Buffer::Buffer(string name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked)
{
    this->name = name;
    this->capacity = capacity;
    this->progressStep = progressStep;
    this->timeoutStep = timeoutStep;
    this->button = button;
    this->soundPlayer = soundPlayer;
    this->soundMasked = soundMasked;
}

bool Buffer::backpressure()
{
    bool backpressure = dispatcher->isBackpressure();
    return backpressure;
}

void Buffer::dispatch()
{
    if(!npc(npc(queue)->peek())->isDispatched()) {
        auto choosenIndex = npc(dispatcher)->findAvailableTarget();
        if(!npc(dispatcher)->isBackpressure()) {
            npc(npc(queue)->peek())->setDispatched(true);
            npc(npc(queue)->peek())->setTargetIndex(choosenIndex);
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
            npc(soundPlayer)->register_(Sound::AcceptedInterestingFragments);
        } else {
            npc(soundPlayer)->register_(Sound::AcceptedNonInterestingFragments);
        }
    }
}

void Buffer::registerMissedSound(bool interesting)
{
    if(!soundMasked) {
        if(interesting) {
            npc(soundPlayer)->register_(Sound::MissedInterestingFragments);
        } else {
            npc(soundPlayer)->register_(Sound::MissedNotInterestingFragments);
        }
    }
}

void Buffer::reserve()
{
    auto data = npc(queue)->peek();
    auto reservedIndex = npc(data)->getTargetIndex();
    auto target = npc(dispatcher)->getTarget(reservedIndex);
    auto link = npc(dispatcher)->getLink(reservedIndex);
    npc(target)->setBusy(true);
    npc(data)->setTarget(link);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Buffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"Buffer", 6);
    return c;
}

java::lang::Class* Buffer::getClass0()
{
    return class_();
}

