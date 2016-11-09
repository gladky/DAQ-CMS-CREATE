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
	//Serial.println("Storage::canAccept? false, full");
        return false;
    } else {
	//Serial.println("Storage::canAccept? true");
        return true;
    }
}

void Storage::finished()
{
}

void Storage::performInsert(Data* data)
{
    SinglePogressObject::performInsert(data);

    /*Serial.print("Storage: inserted new data: ");
    Serial.print(data->getName().c_str());
    Serial.print(", is interesting: ");
    Serial.println(data->isInteresting());*/

    if(data->isInteresting()) {
        soundPlayer->register_(ArrivedInterestingToStorage);
    } else {
        soundPlayer->register_(ArrivedNotInterestingToStorage);
    }
}

