// Generated from /cms.flipper/src/main/java/Clickable.java

#pragma once

#include "IndividualPogressObject.hpp"


class Clickable
    : public IndividualPogressObject
{


private:
    int timeoutStep;
    Button* button ;
    bool accepted;

public: /* protected */
    bool canSend() override;
    virtual void registerAcceptedSound(bool interesting) = 0;
    virtual void registerMissedSound(bool interesting) = 0;
    virtual bool backpressure();
    virtual void dispatch();
    void sendData() override;
    virtual void reserve();

    // Generated

public:
    Clickable(string name, int capacity, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer);


};
