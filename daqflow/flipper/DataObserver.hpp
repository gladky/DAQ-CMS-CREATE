// Generated from /cms.flipper/src/main/java/DataObserver.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <FlowObserver.hpp>

struct default_init_tag;

class DataObserver
    : public FlowObserver
{

public:
    typedef FlowObserver super;
protected:
    void ctor(FlipperGame* flipperGame);

public: /* protected */
    ::java::lang::String* getState(Link* link) override;
    ::java::lang::String* getState(BUFU* bufu) override;
    ::java::lang::String* getState(Buffer* buffer) override;
    ::java::lang::String* getState(Storage* storage) override;

    // Generated

public:
    DataObserver(FlipperGame* flipperGame);
protected:
    DataObserver(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual ::java::lang::String* getState(Switch* switch_);

private:
    virtual ::java::lang::Class* getClass0();
};
