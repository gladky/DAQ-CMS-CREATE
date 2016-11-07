// Generated from /cms.flipper/src/main/java/Dispatcher.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/util/fwd-cms.flipper.hpp>
#include <NamedObject.hpp>

struct default_init_tag;

class Dispatcher
    : public NamedObject
{

public:
    typedef NamedObject super;

private:
    ::java::util::List* linksToTarget {  };
    ::java::util::List* targets {  };
    int32_t result {  };
    bool valid {  };
    bool backpressure {  };
    SoundPlayer* soundPlayer {  };
protected:
    void ctor(::java::util::List* targets, ::java::util::List* linksToTargets, SoundPlayer* soundPlayer);

public:
    virtual FlipperObject* getTarget(int32_t id);
    virtual FlipperObject* getLink(int32_t id);
    virtual int32_t findAvailableTarget();
    virtual void invalidate();
    virtual bool isBackpressure();
    virtual int32_t getResult();

    // Generated
    Dispatcher(::java::util::List* targets, ::java::util::List* linksToTargets, SoundPlayer* soundPlayer);
protected:
    Dispatcher(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
