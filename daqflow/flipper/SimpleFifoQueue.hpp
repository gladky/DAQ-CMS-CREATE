// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java

#pragma once


class SimpleFifoQueue
{

public:
    vector<Data> queue;

private:
    int32_t tailIndex;
    int32_t capacity;

public:
    virtual Data* peek();
    virtual Data* poll();
    virtual bool add(Data* data);
    virtual int32_t size();
    virtual bool isEmpty();
    virtual Data* get(int32_t index);
    virtual void clear();
    virtual int[] getProgress();

    // Generated
    SimpleFifoQueue(int32_t capacity);
protected:
    SimpleFifoQueue(const ::default_init_tag&);


};
