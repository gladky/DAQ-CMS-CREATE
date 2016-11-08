// Generated from /cms.flipper/src/main/java/SinglePogressObject.java

#pragma once

#include <FlipperObject.hpp>

struct default_init_tag;

class SinglePogressObject
    : public FlipperObject
{

public:
    typedef FlipperObject super;

private:
    int32_t progress {  };
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);

public: /* protected */
    void performInsert(Data* data) override;

public:
    void doStep() override;
    bool canAccept() override;
    ::int32_tArray* getProgress() override;

public: /* protected */
    int32_t stepImplementation(Data* data) override;

    // Generated

public:
    SinglePogressObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer);
protected:
    SinglePogressObject(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
