// Generated from /cms.flipper/src/main/java/Data.java

#pragma once

#include "FlipperObject.hpp"

#include <string>

using namespace std;

class FlipperObject;

class Data
{


private:
    int progress;
    int timeOutProgress;
    bool dispatched;
    int targetIndex;
    string name;
    FlipperObject* target;
    bool isFragment_ ;
    bool isInteresting_ ;

public:
    virtual string getName();
    virtual FlipperObject* getTarget();
    virtual void setTarget(FlipperObject* target);
    virtual bool isDispatched();
    virtual void setDispatched(bool dispatched);
    virtual int getProgress();
    virtual void setProgress(int progress);
    virtual bool isInteresting();
    virtual bool isFragment();
    virtual int getTimeOutProgress();
    virtual void setTimeOutProgress(int timeOutProgress);
    virtual int getTargetIndex();
    virtual void setTargetIndex(int targetIndex);

    // Generated
    Data(string name, bool isFragment, bool isInteresting);


};
