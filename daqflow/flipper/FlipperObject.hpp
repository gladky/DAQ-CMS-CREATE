// Generated from /cms.flipper/src/main/java/FlipperObject.java

#pragma once

#include "NamedObject.hpp"

struct default_init_tag;

class FlipperObject
    : public NamedObject
{

public:
    typedef NamedObject super;

public: /* protected */
    int32_t progressStep {  };

private:
    ::java::util::List* successors {  };

public: /* protected */
    SimpleFifoQueue* queue {  };
    int32_t capacity {  };

private:
    bool reserved {  };

public: /* protected */
    SoundPlayer* soundPlayer {  };
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);

public: /* protected */
    virtual void performInsert(Data* data) = 0;
    virtual int32_t stepImplementation(Data* data) = 0;

public:
    virtual void doStep() = 0;
    virtual ::int32_tArray* getProgress() = 0;

public: /* protected */
    virtual void finished() = 0;

public:
    virtual bool insert(Data* data);
    virtual bool canAccept();

public: /* protected */
    virtual bool canSend();
    virtual void sendData();

public:
    virtual ::java::util::List* getSuccessors();
    virtual bool isBusy();
    virtual void setBusy(bool busy);
    virtual SimpleFifoQueue* getQueue();

    // Generated
    FlipperObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);
protected:
    FlipperObject(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
