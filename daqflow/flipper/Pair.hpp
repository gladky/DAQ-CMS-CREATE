// Generated from /cms.flipper/src/main/java/Pair.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class Pair
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* left {  };
    ::java::lang::String* right {  };
protected:
    void ctor(::java::lang::String* left, ::java::lang::String* right);

public:
    static Pair* of(::java::lang::String* left, ::java::lang::String* right);
    virtual ::java::lang::String* getLeft();
    virtual ::java::lang::String* getRight();

    // Generated
    Pair(::java::lang::String* left, ::java::lang::String* right);
protected:
    Pair(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
