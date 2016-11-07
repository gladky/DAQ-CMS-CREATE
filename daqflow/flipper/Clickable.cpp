// Generated from /cms.flipper/src/main/java/Clickable.java
#include <Clickable.hpp>

#include <Button.hpp>
#include <Data.hpp>
#include <SimpleFifoQueue.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Clickable::Clickable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Clickable::Clickable(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer) 
    : Clickable(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,progressStep,timeoutStep,button,soundPlayer);
}

void Clickable::ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer)
{
    super::ctor(name, capacity, progressStep, soundPlayer);
    this->timeoutStep = timeoutStep;
    this->button = button;
    this->accepted = false;
}

bool Clickable::canSend()
{
    dispatch();
    if(!npc(button)->isEnabled() && !backpressure() && !accepted) {
        npc(button)->enable();
    }
    auto pressed = npc(button)->isPressed();
    if(pressed || accepted) {
        auto data = npc(this->queue)->peek();
        if(!accepted) {
            accepted = true;
            registerAcceptedSound(npc(data)->isInteresting());
            npc(this->button)->disable();
        }
        auto canSend = super::canSend();
        return canSend;
    } else {
        auto data = npc(this->queue)->peek();
        auto timeoutProgress = npc(data)->getTimeOutProgress() + timeoutStep;
        npc(data)->setTimeOutProgress(timeoutProgress);
        if(timeoutProgress > 99) {
            npc(this->queue)->poll();
            npc(button)->disable();
            registerMissedSound(npc(data)->isInteresting());
        }
        return false;
    }
}

bool Clickable::backpressure()
{
    return false;
}

void Clickable::dispatch()
{
}

void Clickable::sendData()
{
    reserve();
    super::sendData();
    this->accepted = false;
}

void Clickable::reserve()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Clickable::class_()
{
    static ::java::lang::Class* c = ::class_(u"Clickable", 9);
    return c;
}

java::lang::Class* Clickable::getClass0()
{
    return class_();
}

