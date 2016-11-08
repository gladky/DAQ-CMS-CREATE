// Generated from /cms.flipper/src/main/java/SoundPlayer.java

#pragma once

#include "NamedObject.hpp"

class SoundPlayer
    : public NamedObject
{


private:
    vector<int> sounds;

public:
    virtual void register_(int soundId);
    virtual vector<int> getSounds();
    virtual void flush();

    // Generated
    SoundPlayer(string name);

};
