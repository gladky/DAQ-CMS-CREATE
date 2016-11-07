// Generated from /cms.flipper/src/main/java/Fragment.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <Data.hpp>

struct default_init_tag;

class Fragment
    : public Data
{

public:
    typedef Data super;

private:
    static int32_t id_;
protected:
    void ctor(bool interesting);
    void ctor();

    // Generated

public:
    Fragment(bool interesting);
    Fragment();
protected:
    Fragment(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    static int32_t& id();
    virtual ::java::lang::Class* getClass0();
};
