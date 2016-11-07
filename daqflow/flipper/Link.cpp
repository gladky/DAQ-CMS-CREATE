// Generated from /cms.flipper/src/main/java/Link.java
#include <Link.hpp>

Link::Link(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Link::Link(::java::lang::String* name, int32_t capacity, int32_t step, SoundPlayer* soundPlayer) 
    : Link(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,step,soundPlayer);
}

void Link::ctor(::java::lang::String* name, int32_t capacity, int32_t step, SoundPlayer* soundPlayer)
{
    super::ctor(name, capacity, step, soundPlayer);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Link::class_()
{
    static ::java::lang::Class* c = ::class_(u"Link", 4);
    return c;
}

java::lang::Class* Link::getClass0()
{
    return class_();
}

