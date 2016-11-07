// Generated from /cms.flipper/src/main/java/FragmentGenerator.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class FragmentGenerator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    FlipperObject* link1 {  };
    FlipperObject* link2 {  };
    FlipperObject* link3 {  };
    FlipperObject* link4 {  };
    bool val {  };
protected:
    void ctor(FlipperObject* link1, FlipperObject* link2, FlipperObject* link3, FlipperObject* link4);

public:
    virtual void generateAndInsertFragments();

    // Generated
    FragmentGenerator(FlipperObject* link1, FlipperObject* link2, FlipperObject* link3, FlipperObject* link4);
protected:
    FragmentGenerator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
