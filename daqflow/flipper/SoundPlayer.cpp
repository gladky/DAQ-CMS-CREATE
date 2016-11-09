// Generated from /cms.flipper/src/main/java/SoundPlayer.java
#include "SoundPlayer.hpp"

#include "Sound.hpp"




SoundPlayer::SoundPlayer(string name): NamedObject(name)
{
    vector<int> sounds;
}

void SoundPlayer::register_(int soundId)
{
    sounds.push_back(soundId);
}

vector<int> SoundPlayer::getSounds()
{
    return sounds;
}

void SoundPlayer::flush()
{
    Serial.print("SoundPlayer: ");
    sounds.clear();
}


