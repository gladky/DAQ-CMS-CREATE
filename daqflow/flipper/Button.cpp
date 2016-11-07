// Generated from /cms.flipper/src/main/java/Button.java
#include <Button.hpp>

#include <Sound.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Button::Button(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Button::Button(::java::lang::String* name, SoundPlayer* soundPlayer) 
    : Button(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,soundPlayer);
}

void Button::ctor(::java::lang::String* name, SoundPlayer* soundPlayer)
{
    super::ctor(name);
    this->enabled = false;
    this->pressed = false;
    this->disableRequest = false;
    this->soundPlayer = soundPlayer;
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
        npc(soundPlayer)->register_(Sound::ButtonPressedWhenEnabled);
        return true;
    } else {
        npc(soundPlayer)->register_(Sound::ButtonPressedWhenDisabled);
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

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Button::class_()
{
    static ::java::lang::Class* c = ::class_(u"Button", 6);
    return c;
}

java::lang::Class* Button::getClass0()
{
    return class_();
}

