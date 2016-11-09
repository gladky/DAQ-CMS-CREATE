// Generated from /cms.flipper/src/main/java/FlipperObject.java
#include "FlipperObject.hpp"

#include "Data.hpp"
#include "Link.hpp"
#include "SimpleFifoQueue.hpp"
#include "SoundPlayer.hpp"




FlipperObject::FlipperObject(string name_, int32_t capacity_, int progressStep_, SoundPlayer* soundPlayer_) 
    : NamedObject(name_)
{
    progressStep = progressStep_;
    //successors = vector; // they sey should be initialized by default constructor
    successors.reserve(capacity_);
    capacity = capacity_;
    queue = new SimpleFifoQueue(capacity_);
    reserved = false;
    soundPlayer = soundPlayer_;
}


bool FlipperObject::insert(Data* data)
{
    if(!canAccept()) {
        Serial.println("FlipperObject: Inserting data disallowed");
        return false;
    } else {
        Serial.println("FlipperObject: Inserting data allowed");
        performInsert(data);
        reserved = false;
        return true;
    }
}

bool FlipperObject::canAccept()
{

    bool iAmAbleToAccept;
    if(queue->size() == capacity) {
        iAmAbleToAccept = false;
        Serial.println("FlipperObject:canAccept? false, full");
        return false;
    } else {
        iAmAbleToAccept = true;
    }
    bool existsNonLinkSuccessorsCanAccept = false;
    if(Link* link = dynamic_cast<Link*>(this)) {
        Serial.print("FlipperObject:I am link, I have to ask others, number of my successors: ");
        Serial.println(successors.size());
        for (int i = 0; i< successors.size(); i++ ) {
            FlipperObject* successor = successors[i];
            {
                Serial.print("FlipperObject:Asking successor ");
                Serial.println(successor->getName().c_str());
                bool canAccept = successor->canAccept();
                if(canAccept == true) {
                    existsNonLinkSuccessorsCanAccept = true;
                }
            }
        }
    } else {
        existsNonLinkSuccessorsCanAccept = true;
    }
    if(iAmAbleToAccept == false || existsNonLinkSuccessorsCanAccept == false) {
        Serial.println("FlipperObject:canAccept? false, one of 2 condition");
        return false;
    } else {
        Serial.println("FlipperObject:canAccept? true");
        return true;
    }
}

bool FlipperObject::canSend()
{
    bool allDirectAccept = true;
    for (int i = 0; i< successors.size(); i++ ) {
	FlipperObject* successor = successors[i];
        {
            bool accept = successor->canAccept();
            if(!accept) {
                allDirectAccept = false;
            }
        }
    }
    if(allDirectAccept) {
        return true;
    } else {
        return false;
    }
}

void FlipperObject::sendData()
{
    Data* data = queue->poll();
    
    for (int i = 0; i< successors.size(); i++ ) {
        FlipperObject* successor = successors[i];
            successor->insert(data);
    }
}

vector<FlipperObject*>& FlipperObject::getSuccessors()
{
    return successors;
}

bool FlipperObject::isBusy()
{
    return reserved;
}

void FlipperObject::setBusy(bool busy)
{
    this->reserved = busy;
}

SimpleFifoQueue* FlipperObject::getQueue()
{
    return queue;
}

