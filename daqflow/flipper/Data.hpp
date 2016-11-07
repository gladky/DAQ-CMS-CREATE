// Generated from /cms.flipper/src/main/java/Data.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class Data
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t progress {  };
    int32_t timeOutProgress {  };
    bool dispatched {  };
    FlipperObject* target {  };
    int32_t targetIndex {  };
    ::java::lang::String* name {  };
    bool isFragment_ {  };
    bool isInteresting_ {  };
protected:
    void ctor(::java::lang::String* name, bool isFragment, bool isInteresting);

public:
    virtual ::java::lang::String* getName();
    ::java::lang::String* toString() override;
    virtual FlipperObject* getTarget();
    virtual void setTarget(FlipperObject* target);
    virtual bool isDispatched();
    virtual void setDispatched(bool dispatched);
    virtual int32_t getProgress();
    virtual void setProgress(int32_t progress);
    virtual bool isInteresting();
    virtual bool isFragment();
    virtual int32_t getTimeOutProgress();
    virtual void setTimeOutProgress(int32_t timeOutProgress);
    virtual int32_t getTargetIndex();
    virtual void setTargetIndex(int32_t targetIndex);

    // Generated
    Data(::java::lang::String* name, bool isFragment, bool isInteresting);
protected:
    Data(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
