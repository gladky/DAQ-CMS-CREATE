// Generated from /cms.flipper/src/main/java/Storage.java
#include "Storage.hpp"

#include "Data.hpp"
#include "SimpleFifoQueue.hpp"
#include "Sound.hpp"
#include "SoundPlayer.hpp"
#include "SinglePogressObject.hpp"


Storage::Storage(string name, int capacity, SoundPlayer* soundPlayer) 
: SinglePogressObject(name, capacity, 0, soundPlayer)
{
}

bool Storage::canAccept()
{
    if(queue->size() == capacity) {
        return false;
    } else {
        return true;
    }
}

void Storage::finished()
{
}

void Storage::performInsert(Data* data)
{
    SinglePogressObject::performInsert(data);
    if(data->isInteresting()) {
        soundPlayer->register_(ArrivedInterestingToStorage);
    } else {
        soundPlayer->register_(ArrivedNotInterestingToStorage);
    }
}

