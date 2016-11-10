// Generated from /cms.flipper/src/main/java/BUFU.java
#include "BUFU.hpp"

#include "Data.hpp"
#include "FlipperObject.hpp"
#include "Link.hpp"
#include "Sound.hpp"
#include "SoundPlayer.hpp"


BUFU::BUFU(string name, int progressStep, int timeoutStep, Button* button, SoundPlayer* soundPlayer)
: Clickable(name, 1, progressStep, timeoutStep, button, soundPlayer)
{
    ;
}

bool BUFU::canSend()
{
    bool basicCheck = Clickable::canSend();
    bool allLinksFree = true;
    for(int i=0; i<getSuccessors().size(); i++){
        FlipperObject* successor = getSuccessors()[i];
        {
            bool linksReserved = checkLinksReserved(successor);
            if(linksReserved) {
                allLinksFree = false;
            }
        }
    }
    if(basicCheck && allLinksFree) {
        return true;
    } else {
        return false;
    }
}

void BUFU::sendData()
{

    for(int i=0; i<getSuccessors().size(); i++){
        FlipperObject* successor = getSuccessors()[i];
        {
            reserveLinks(successor);
        }
    }
    Clickable::sendData();
}

bool BUFU::checkLinksReserved(FlipperObject* successor)
{
    if(Link* v = dynamic_cast< Link* >(successor)) {
        bool reserved = successor->isBusy();
        if(reserved) {
            return true;
        } else {
            for( int i = 0; i < successor->getSuccessors().size(); i++){
                FlipperObject* next = successor->getSuccessors()[i];
                {
                    return checkLinksReserved(next);
                }
            }
        }
    }
    return false;
}

void BUFU::reserveLinks(FlipperObject* successor)
{
    if(Link* v = dynamic_cast< Link* >(successor)) {
        successor->setBusy(true);

        for( int i = 0; i < successor->getSuccessors().size(); i++){
            FlipperObject* next = successor->getSuccessors()[i];
            {
                reserveLinks(next);
            }
        }
    }
}

void BUFU::registerAcceptedSound(bool interesting)
{
    if(interesting) {
        soundPlayer->register_(AcceptedInterestingEvent);
    } else {
        soundPlayer->register_(AcceptedNotInteresingEvent);
    }
}

void BUFU::registerMissedSound(bool interesting)
{
    if(interesting) {
        soundPlayer->register_(MissedInterestedEvent);
    } else {
        soundPlayer->register_(MissedNotInterestingEvent);
    }
}

bool BUFU::insert(Data* data)
{
    data->setDispatched(false);
    return Clickable::insert(data);
}

