// Generated from /cms.flipper/src/main/java/Event.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <Data.hpp>

struct default_init_tag;

class Event
    : public Data
{

public:
    typedef Data super;
protected:
    void ctor(Data* f1, Data* f2, Data* f3, Data* f4);
    void ctor(::java::lang::String* name, bool interesting);
    void ctor(::java::lang::String* name);

private:
    static ::java::lang::String* generateSimpleName(Data* d);
    static bool isInteresting(Data* fragment1, Data* fragment2, Data* fragment3, Data* fragment4);

    // Generated

public:
    Event(Data* f1, Data* f2, Data* f3, Data* f4);
    Event(::java::lang::String* name, bool interesting);
    Event(::java::lang::String* name);
protected:
    Event(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool isInteresting();

private:
    virtual ::java::lang::Class* getClass0();
};
