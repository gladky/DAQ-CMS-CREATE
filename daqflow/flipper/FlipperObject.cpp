// Generated from /cms.flipper/src/main/java/FlipperObject.java
#include <FlipperObject.hpp>

#include <Data.hpp>
#include <Link.hpp>
#include <SimpleFifoQueue.hpp>
#include <SoundPlayer.hpp>




FlipperObject::FlipperObject(string name_, int32_t capacity_, int progressStep_, SoundPlayer* soundPlayer_) 
    : NamedObject(name_)
{
    progressStep = progressStep_;
    //successors = vector; // they sey should be initialized by default constructor
    capacity = capacity_;
    queue = new SimpleFifoQueue(capacity_);
    reserved = false;
    soundPlayer = soundPlayer_;
}


bool FlipperObject::insert(Data* data)
{
    if(!canAccept()) {
        return false;
    } else {
        performInsert(data);
        reserved = false;
        return true;
    }
}

bool FlipperObject::canAccept()
{
    bool iAmAbleToAccept;
    if(npc(queue)->size() == capacity) {
        iAmAbleToAccept = false;
        return false;
    } else {
        iAmAbleToAccept = true;
    }
    bool existsNonLinkSuccessorsCanAccept = false;
    if(dynamic_cast< Link* >(this) != nullptr) {
        for (bool _i = successors->iterator(); _i->hasNext(); ) {
            FlipperObject* successor = _i->next();
            {
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
        return false;
    } else {
        return true;
    }
}

bool FlipperObject::canSend()
{
    bool allDirectAccept = true;
    for(auto const& successor: successors) {
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
    Data data = queue->poll();
    
    for(auto const& successor: successors) {
        {
            successor->insert(data);
        }
    }
}

vector<FlipperObject*> FlipperObject::getSuccessors()
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

