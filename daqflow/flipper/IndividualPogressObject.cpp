// Generated from /cms.flipper/src/main/java/IndividualPogressObject.java
#include "IndividualPogressObject.hpp"

#include "Data.hpp"
#include "SimpleFifoQueue.hpp"


IndividualPogressObject::IndividualPogressObject(string name, int capacity, int progressStep, SoundPlayer* soundPlayer) 
    : FlipperObject(name,capacity,progressStep,soundPlayer)
{
    acceptedThisCycle = false;
}

int IndividualPogressObject::fakeInf =100000 ;


void IndividualPogressObject::performInsert(Data* data)
{
    Serial.println("IndividualPogressObject: performing insert");
    data->setProgress(0);
    data->setTimeOutProgress(0);
    queue->add(data);
    acceptedThisCycle = true;
}

bool IndividualPogressObject::canAccept()
{

    if(acceptedThisCycle) {
        Serial.println("IndividualPogressObject: can accept? NO, already accepted this cycle");
        return false;
    }
    Serial.println("IndividualPogressObject: can accept? will ask FlipperObject");
    return FlipperObject::canAccept();
}

vector<int> IndividualPogressObject::getProgress()
{
    return queue->getProgress();
}

int IndividualPogressObject::stepImplementation(Data* current)
{
    int newProgress = current->getProgress() + progressStep;
    current->setProgress(newProgress);
    return newProgress;
}

void IndividualPogressObject::doStep()
{
    Serial.println("IndividualProgressObject: doStep");
    if(!queue->isEmpty()) {
        int localProgressLimit = fakeInf;
        int initialSize = queue->size();
        int recentSize = initialSize;
        for (int i = 0; i < recentSize; i++) {
            Data* current = queue->get(i);
            if(current->getProgress() + progressStep < localProgressLimit) {
                int progress = stepImplementation(current);
                if(progress < localProgressLimit) {
                    localProgressLimit = progress;
                }
                if(progress > 99) {
                    finished();
                    if(canSend()) {
                        sendData();
                    }
                }
            } else {
                if(current->getProgress() < localProgressLimit) {
                    localProgressLimit = current->getProgress();
                }
            }
            if(localProgressLimit > 100) {
                localProgressLimit = 100;
            }
            if(recentSize != queue->size()) {
                recentSize = queue->size();
                i--;
            }
        }
    }
    acceptedThisCycle = false;
}

void IndividualPogressObject::finished()
{
    return;
}


