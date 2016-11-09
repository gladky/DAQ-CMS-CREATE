// Generated from /cms.flipper/src/main/java/Dispatcher.java

#pragma once

#include "NamedObject.hpp"


class Dispatcher
    : public NamedObject
{


private:
    vector<FlipperObject*> linksToTarget;
    vector<FlipperObject*> targets ;
    int result ;
    bool valid;
    bool backpressure;
    SoundPlayer* soundPlayer;

public:
    virtual FlipperObject* getTarget(int id);
    virtual FlipperObject* getLink(int id);
    virtual int findAvailableTarget();
    virtual void invalidate();
    virtual bool isBackpressure();
    virtual int getResult();

    // Generated
    Dispatcher(vector<FlipperObject*> targets, vector<FlipperObject*> linksToTargets, SoundPlayer* soundPlayer);


};
