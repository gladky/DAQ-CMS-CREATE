// Generated from /cms.flipper/src/main/java/Clickable.java

#pragma once

#include "IndividualPogressObject.hpp"

struct default_init_tag;

class Clickable
    : public IndividualPogressObject
{

public:
    typedef IndividualPogressObject super;

private:
    int32_t timeoutStep {  };
    Button* button {  };
    bool accepted {  };
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer);

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
    Clickable(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer);
protected:
    Clickable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
