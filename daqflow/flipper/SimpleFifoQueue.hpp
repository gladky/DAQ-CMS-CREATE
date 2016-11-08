// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java

#pragma once

struct default_init_tag;

class SimpleFifoQueue
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::java::util::List* queue {  };

private:
    int32_t tailIndex {  };
    int32_t capacity {  };
protected:
    void ctor(int32_t capacity);

public:
    virtual Data* peek();
    virtual Data* poll();
    virtual bool add(Data* data);
    virtual int32_t size();
    ::java::lang::String* toString() override;
    virtual bool isEmpty();
    virtual Data* get(int32_t index);
    virtual void clear();
    virtual ::int32_tArray* getProgress();

    // Generated
    SimpleFifoQueue(int32_t capacity);
protected:
    SimpleFifoQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
