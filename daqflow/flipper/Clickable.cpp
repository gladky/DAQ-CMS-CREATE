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
    //Serial.println("Clickable: can send, next enabling");
    //Serial.print("is enabled: ");
    //Serial.println(button->isEnabled());
    dispatch();
    if(!button->isEnabled() && !backpressure() && !accepted) {
        //Serial.println("Clickable: enabling button");
        button->enable();
    }
    bool pressed = button->isPressed();
    if(pressed || accepted) {
        Data* data = this->queue->peek();
        if(!accepted) {
            accepted = true;
            registerAcceptedSound(data->isInteresting());

            /*Serial.print("Clickable::");
            Serial.print(getName().c_str());
            Serial.println(" accepted, disabling button");*/
            button->disable();
        }
        bool canSend = IndividualPogressObject::canSend();
        return canSend;
    } else {
        Data* data = this->queue->peek();
        int timeoutProgress = data->getTimeOutProgress() + timeoutStep;
        data->setTimeOutProgress(timeoutProgress);
        if(timeoutProgress > 99) {
            queue->poll();

            /*Serial.print("Clickable::");
            Serial.print(getName().c_str());
            Serial.println(" timeout over, disabling button");*/
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

