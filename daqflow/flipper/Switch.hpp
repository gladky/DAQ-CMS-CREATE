// Generated from /cms.flipper/src/main/java/Switch.java

#pragma once

#include "SinglePogressObject.hpp"
#include "SoundPlayer.hpp"


class Switch
    : public SinglePogressObject
{


public: /* protected */
    SimpleFifoQueue* outputQueue;

public:
    bool canAccept() override;
    int stepImplementation(Data* data) override;

public: /* protected */
    bool canSend() override;
    void sendData() override;
    void finished() override;

public:
    virtual SimpleFifoQueue* getOutputQueue();

    // Generated
    Switch(string name, SoundPlayer* soundPlayer);


};
