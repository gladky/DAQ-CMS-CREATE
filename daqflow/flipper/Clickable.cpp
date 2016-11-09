// Generated from /cms.flipper/src/main/java/Clickable.java
#include "Clickable.hpp"

#include "Button.hpp"
#include "Data.hpp"
#include "SimpleFifoQueue.hpp"




Clickable::Clickable(string name, int capacity, int progressStep, int timeoutStep_, Button* button_, SoundPlayer* soundPlayer):IndividualPogressObject(name, capacity, progressStep, soundPlayer) 
{
    timeoutStep = timeoutStep_;
    button = button_;
    accepted = false;
}

bool Clickable::canSend()
{
    dispatch();
    if(!button->isEnabled() && !backpressure() && !accepted) {
        button->enable();
    }
    bool pressed = button->isPressed();
    if(pressed || accepted) {
        Data* data = this->queue->peek();
        if(!accepted) {
            accepted = true;
            registerAcceptedSound(data->isInteresting());
            this->button->disable();
        }
        bool canSend = IndividualPogressObject::canSend();
        return canSend;
    } else {
        Data* data = this->queue->peek();
        int timeoutProgress = data->getTimeOutProgress() + timeoutStep;
        data->setTimeOutProgress(timeoutProgress);
        if(timeoutProgress > 99) {
            this->queue->poll();
            button->disable();
            registerMissedSound(data->isInteresting());
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
    IndividualPogressObject::sendData();
    this->accepted = false;
}

void Clickable::reserve()
{
}

