// Generated from /cms.flipper/src/main/java/Buffer.java

#pragma once

#include "Clickable.hpp"


class Buffer
    : public Clickable
{


private:
    bool soundMasked ;
    Dispatcher* dispatcher ;

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
    Buffer(string name, int capacity, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer, bool soundMasked);


};
