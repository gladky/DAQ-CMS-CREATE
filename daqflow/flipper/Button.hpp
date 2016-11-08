// Generated from /cms.flipper/src/main/java/Button.java

#pragma once

#include "NamedObject.hpp"


class Button
    : public NamedObject
{


private:
    bool enabled;
    bool pressed;
    bool disableRequest;
    SoundPlayer* soundPlayer;

public:
    virtual void enable();
    virtual bool press();
    virtual bool isPressed();
    virtual void disable();
    virtual bool isEnabled();
    virtual void doStep();

    // Generated
    Button(string name, SoundPlayer* soundPlayer);

};
