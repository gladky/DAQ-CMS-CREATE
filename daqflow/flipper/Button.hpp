// Generated from /cms.flipper/src/main/java/Button.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <NamedObject.hpp>

struct default_init_tag;

class Button
    : public NamedObject
{

public:
    typedef NamedObject super;

private:
    bool enabled {  };
    bool pressed {  };
    bool disableRequest {  };
    SoundPlayer* soundPlayer {  };
protected:
    void ctor(::java::lang::String* name, SoundPlayer* soundPlayer);

public:
    virtual void enable();
    virtual bool press();
    virtual bool isPressed();
    virtual void disable();
    virtual bool isEnabled();
    virtual void doStep();

    // Generated
    Button(::java::lang::String* name, SoundPlayer* soundPlayer);
protected:
    Button(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
