// Generated from /cms.flipper/src/main/java/FragmentGenerator.java
#include <FragmentGenerator.hpp>

#include <FlipperObject.hpp>
#include <Fragment.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

FragmentGenerator::FragmentGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

FragmentGenerator::FragmentGenerator(FlipperObject* link1, FlipperObject* link2, FlipperObject* link3, FlipperObject* link4) 
    : FragmentGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(link1,link2,link3,link4);
}

void FragmentGenerator::ctor(FlipperObject* link1, FlipperObject* link2, FlipperObject* link3, FlipperObject* link4)
{
    super::ctor();
    this->link1 = link1;
    this->link2 = link2;
    this->link3 = link3;
    this->link4 = link4;
    this->val = false;
}

void FragmentGenerator::generateAndInsertFragments()
{
    Data* f1 = new Fragment(true);
    Data* f2 = new Fragment(true);
    Data* f3 = new Fragment(true);
    Data* f4 = new Fragment(val);
    val = !val;
    npc(link1)->insert(f1);
    npc(link2)->insert(f2);
    npc(link3)->insert(f3);
    npc(link4)->insert(f4);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* FragmentGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"FragmentGenerator", 17);
    return c;
}

java::lang::Class* FragmentGenerator::getClass0()
{
    return class_();
}

