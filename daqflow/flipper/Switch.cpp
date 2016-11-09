// Generated from /cms.flipper/src/main/java/Switch.java
#include "Switch.hpp"

#include "Data.hpp"
#include "Event.hpp"
#include "FlipperObject.hpp"
#include "SimpleFifoQueue.hpp"
#include "SinglePogressObject.hpp"


Switch::Switch(string name, SoundPlayer* soundPlayer) 
:SinglePogressObject(name, 4, 50, soundPlayer){
    this->outputQueue = new SimpleFifoQueue(1);
}

bool Switch::canAccept()
{
    boolean basicAccept = SinglePogressObject::canAccept();
    if(basicAccept) {
        return true;
    } else {
        return false;
    }
}

int Switch::stepImplementation(Data* data)
{
    if(queue->size() == 4) {
        Data* fragment1 = queue->get(0);
        Data* fragment2 = queue->get(1);
        Data* fragment3 = queue->get(2);
        Data* fragment4 = queue->get(3);
        Data* event = new Event(fragment1, fragment2, fragment3, fragment4);
        outputQueue->add(event);
        queue->clear();
        return 100;
    } else if(queue->size() == 3) {
        return 75;
    } else if(queue->size() == 2) {
        return 50;
    } else if(queue->size() == 1) {
        return 25;
    } else {
        return 0;
    }
}

bool Switch::canSend()
{
    return true;
}

void Switch::sendData()
{
    Data* data = outputQueue->poll();
    FlipperObject* bufuSuccessor = data->getTarget();
    if(bufuSuccessor->canAccept()) {
        bufuSuccessor->setBusy(true);
        bufuSuccessor->insert(data);
        return;
    }
}

void Switch::finished()
{
    return;
}

SimpleFifoQueue* Switch::getOutputQueue()
{
    return outputQueue;
}


