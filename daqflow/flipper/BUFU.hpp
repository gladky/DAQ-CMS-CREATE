// Generated from /cms.flipper/src/main/java/BUFU.java

#pragma once

#include "Clickable.hpp"
#include "FlipperObject.hpp"
#include "Data.hpp"
#include "Button.hpp"
#include "SoundPlayer.hpp"


class BUFU
    : public Clickable
{


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
    BUFU(string name, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer);

};
