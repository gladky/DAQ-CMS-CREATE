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

    static int id;
    static char numstr[6]; // tmp buffer for converting int to std:strings. Capable to int 999999

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
    virtual string toString(int i);

    // Generated
    Data(string name, bool isFragment, bool isInteresting);


};
