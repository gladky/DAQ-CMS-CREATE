// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java

#pragma once

#include "Data.hpp"
#include <vector>

using namespace std;

class SimpleFifoQueue
{

public:
    vector<Data> queue;

private:
    int tailIndex;
    int capacity;

public:
    virtual Data* peek();
    virtual Data* poll();
    virtual bool add(Data* data);
    virtual int size();
    virtual bool isEmpty();
    virtual Data* get(int index);
    virtual void clear();
    virtual vector<int> getProgress();

    // Generated
    SimpleFifoQueue(int capacity);

};
