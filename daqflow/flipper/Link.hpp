// Generated from /cms.flipper/src/main/java/Link.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <IndividualPogressObject.hpp>

struct default_init_tag;

class Link
    : public IndividualPogressObject
{

public:
    typedef IndividualPogressObject super;
protected:
    void ctor(::java::lang::String* name, int32_t capacity, int32_t step, SoundPlayer* soundPlayer);

    // Generated

public:
    Link(::java::lang::String* name, int32_t capacity, int32_t step, SoundPlayer* soundPlayer);
protected:
    Link(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
