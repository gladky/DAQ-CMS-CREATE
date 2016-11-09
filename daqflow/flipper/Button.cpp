// Generated from /cms.flipper/src/main/java/Button.java
#include "Button.hpp"

#include "Sound.hpp"
#include "SoundPlayer.hpp"


Button::Button(string name, SoundPlayer* soundPlayer_):NamedObject(name)
{
    enabled = false;
    pressed = false;
    disableRequest = false;
    soundPlayer = soundPlayer_;
}

void Button::enable()
{
    enabled = true;
    pressed = false;
    disableRequest = false;
}

bool Button::press()
{
    if(enabled) {
        pressed = true;
        soundPlayer->register_(ButtonPressedWhenEnabled);
        return true;
    } else {
        soundPlayer->register_(ButtonPressedWhenDisabled);
        return false;
    }
}

bool Button::isPressed()
{
    return this->pressed;
}

void Button::disable()
{
    disableRequest = true;
}

bool Button::isEnabled()
{
    return enabled;
}

void Button::doStep()
{
    if(disableRequest) {
        enabled = false;
        pressed = false;
        disableRequest = false;
    }
}

