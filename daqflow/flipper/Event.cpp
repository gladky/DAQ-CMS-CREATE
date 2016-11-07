// Generated from /cms.flipper/src/main/java/Event.java
#include <Event.hpp>

#include <Data.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Event::Event(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Event::Event(Data* f1, Data* f2, Data* f3, Data* f4) 
    : Event(*static_cast< ::default_init_tag* >(0))
{
    ctor(f1,f2,f3,f4);
}

Event::Event(::java::lang::String* name, bool interesting) 
    : Event(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,interesting);
}

Event::Event(::java::lang::String* name) 
    : Event(*static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void Event::ctor(Data* f1, Data* f2, Data* f3, Data* f4)
{
    super::ctor(generateSimpleName(f4), false, isInteresting(f1, f2, f3, f4));
    this->setTarget(npc(f4)->getTarget());
    this->setDispatched(npc(f4)->isDispatched());
}

void Event::ctor(::java::lang::String* name, bool interesting)
{
    super::ctor(name, false, interesting);
}

void Event::ctor(::java::lang::String* name)
{
    ctor(name, false);
}

java::lang::String* Event::generateSimpleName(Data* d)
{
    clinit();
    auto name = ::java::lang::StringBuilder().append(u"e"_j)->append(npc(d)->getName())->toString();
    return name;
}

bool Event::isInteresting(Data* fragment1, Data* fragment2, Data* fragment3, Data* fragment4)
{
    clinit();
    auto interesting = false;
    if(npc(fragment1)->isInteresting() && npc(fragment2)->isInteresting() && npc(fragment3)->isInteresting()&& npc(fragment4)->isInteresting()) {
        interesting = true;
    }
    return interesting;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Event::class_()
{
    static ::java::lang::Class* c = ::class_(u"Event", 5);
    return c;
}

bool Event::isInteresting()
{
    return super::isInteresting();
}

java::lang::Class* Event::getClass0()
{
    return class_();
}

