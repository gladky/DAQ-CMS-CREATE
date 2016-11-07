// Generated from /cms.flipper/src/main/java/IndividualPogressObject.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <FlipperObject.hpp>

struct default_init_tag;

class IndividualPogressObject
    : public FlipperObject
{

public:
    typedef FlipperObject super;

private:
    bool acceptedThisCycle {  };
    static constexpr int32_t fakeInf { int32_t(100000) };
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);

public: /* protected */
    void performInsert(Data* data) override;

public:
    bool canAccept() override;
    ::int32_tArray* getProgress() override;
    int32_t stepImplementation(Data* current) override;
    void doStep() override;

public: /* protected */
    void finished() override;

    // Generated

public:
    IndividualPogressObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);
protected:
    IndividualPogressObject(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
