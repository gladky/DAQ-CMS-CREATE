// Generated from /cms.flipper/src/main/java/Switch.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <SinglePogressObject.hpp>

struct default_init_tag;

class Switch
    : public SinglePogressObject
{

public:
    typedef SinglePogressObject super;

public: /* protected */
    SimpleFifoQueue* outputQueue {  };
protected:
    void ctor(::java::lang::String* name, SoundPlayer* soundPlayer);

public:
    bool canAccept() override;
    int32_t stepImplementation(Data* data) override;

public: /* protected */
    bool canSend() override;
    void sendData() override;
    void finished() override;

public:
    virtual SimpleFifoQueue* getOutputQueue();

    // Generated
    Switch(::java::lang::String* name, SoundPlayer* soundPlayer);
protected:
    Switch(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
