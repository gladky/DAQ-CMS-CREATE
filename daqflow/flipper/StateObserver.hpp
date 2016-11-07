// Generated from /cms.flipper/src/main/java/StateObserver.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <FlowObserver.hpp>

struct default_init_tag;

class StateObserver
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

private:
    ::java::lang::String* spaceSafePrintList(::int32_tArray* list);

    // Generated

public:
    StateObserver(FlipperGame* flipperGame);
protected:
    StateObserver(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual ::java::lang::String* getState(Switch* switch_);

private:
    virtual ::java::lang::Class* getClass0();
};
