// Generated from /cms.flipper/src/main/java/NamedObject.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class NamedObject
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::String* name {  };
protected:
    void ctor(::java::lang::String* name);

public:
    virtual ::java::lang::String* getName();
    ::java::lang::String* toString() override;

    // Generated
    NamedObject(::java::lang::String* name);
protected:
    NamedObject(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
