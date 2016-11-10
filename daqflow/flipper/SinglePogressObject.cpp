// Generated from /cms.flipper/src/main/java/SinglePogressObject.java
#include "SinglePogressObject.hpp"

#include "Data.hpp"
#include "SimpleFifoQueue.hpp"


SinglePogressObject::SinglePogressObject(string name, int capacity, int progressStep, SoundPlayer* soundPlayer) 
: FlipperObject(name, capacity, progressStep, soundPlayer){
}

void SinglePogressObject::performInsert(Data* data)
{

    
    /*Serial.print("SingleProgressObject::");
    Serial.print(getName().c_str());
    Serial.print("::performInsert, start-- ");*/
    
    queue->add(data);
    int size = queue->size();
    int result = size * 100 / capacity;
    progress = result;

    //Serial.println("-- end ::performInsert ");
}

void SinglePogressObject::doStep()
{
    int progress = stepImplementation(NULL);
    if(progress > 99) {
        if(canSend()) {
            sendData();
        }
    }
}

bool SinglePogressObject::canAccept()
{
    if(queue->size() == capacity) {
        /*Serial.print("SingleProgressObject::");
        Serial.print(getName().c_str());
	Serial.println("::canAccept? false, full");*/
        return false;
    } else {
        /*Serial.print("SingleProgressObject::");
        Serial.print(getName().c_str());
	Serial.println("::canAccept? true, not full");*/
        return true;
    }
}

vector<int> SinglePogressObject::getProgress()
{
    vector<int> progressArray;
    progressArray.push_back(progress);
    return progressArray;
}

int SinglePogressObject::stepImplementation(Data* data)
{
    return 0;
}



