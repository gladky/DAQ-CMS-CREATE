// Generated from /cms.flipper/src/main/java/BUFU.java

#pragma once

#include <Clickable.hpp>

struct default_init_tag;

class BUFU
    : public Clickable
{

public:
    typedef Clickable super;
protected:
    void ctor(::java::lang::String* name, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer);

public: /* protected */
    bool canSend() override;
    void sendData() override;

private:
    bool checkLinksReserved(FlipperObject* successor);
    void reserveLinks(FlipperObject* successor);

public: /* protected */
    void registerAcceptedSound(bool interesting) override;
    void registerMissedSound(bool interesting) override;

public:
    bool insert(Data* data) override;

    // Generated
    BUFU(::java::lang::String* name, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer);
protected:
    BUFU(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
