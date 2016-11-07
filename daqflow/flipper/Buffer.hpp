// Generated from /cms.flipper/src/main/java/Buffer.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <Clickable.hpp>

struct default_init_tag;

class Buffer
    : public Clickable
{

public:
    typedef Clickable super;

private:
    bool soundMasked {  };
    Dispatcher* dispatcher {  };
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked);

public: /* protected */
    bool backpressure() override;
    void dispatch() override;

public:
    virtual Dispatcher* getDispatcher();
    virtual void setDispatcher(Dispatcher* dispatcher);

public: /* protected */
    void registerAcceptedSound(bool interesting) override;
    void registerMissedSound(bool interesting) override;
    void reserve() override;

    // Generated

public:
    Buffer(::java::lang::String* name, int32_t capacity, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked);
protected:
    Buffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
