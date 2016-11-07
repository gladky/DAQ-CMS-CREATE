// Generated from /cms.flipper/src/main/java/NamedObject.java
#include <NamedObject.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

NamedObject::NamedObject(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

NamedObject::NamedObject(::java::lang::String* name) 
    : NamedObject(*static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void NamedObject::ctor(::java::lang::String* name)
{
    super::ctor();
    this->name = name;
}

java::lang::String* NamedObject::getName()
{
    return name;
}

java::lang::String* NamedObject::toString()
{
    return ::java::lang::StringBuilder().append(u"NamedObject [name="_j)->append(name)
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* NamedObject::class_()
{
    static ::java::lang::Class* c = ::class_(u"NamedObject", 11);
    return c;
}

java::lang::Class* NamedObject::getClass0()
{
    return class_();
}

