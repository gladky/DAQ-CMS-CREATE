// Generated from /cms.flipper/src/main/java/FlipperObject.java

#pragma once

#include "Data.hpp"
#include "NamedObject.hpp"

#include "SimpleFifoQueue.hpp"
#include "SoundPlayer.hpp"


#include <vector>

using namespace std;

class FlipperObject
    : public NamedObject
{


public: /* protected */
    int progressStep ;

private:
    vector<FlipperObject*> successors;

public: /* protected */
    SimpleFifoQueue* queue;
    int capacity;

private:
    bool reserved;

public: /* protected */
    SoundPlayer* soundPlayer;

public: /* protected */
    virtual void performInsert(Data* data) = 0;
    virtual int stepImplementation(Data* data) = 0;

public:
    virtual void doStep() = 0;
    virtual vector<int> getProgress() = 0;

public: /* protected */
    virtual void finished() = 0;

public:
    virtual bool insert(Data* data);
    virtual bool canAccept();

public: /* protected */
    virtual bool canSend();
    virtual void sendData();

public:
    virtual vector<FlipperObject*> getSuccessors();
    virtual bool isBusy();
    virtual void setBusy(bool busy);
    virtual SimpleFifoQueue* getQueue();

    // Generated
    FlipperObject(string name, int capacity, int progressStep, SoundPlayer* soundPlayer);


};

