// Generated from /cms.flipper/src/main/java/Pair.java
#include <Pair.hpp>

#include <java/lang/String.hpp>

Pair::Pair(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Pair::Pair(::java::lang::String* left, ::java::lang::String* right) 
    : Pair(*static_cast< ::default_init_tag* >(0))
{
    ctor(left,right);
}

void Pair::ctor(::java::lang::String* left, ::java::lang::String* right)
{
    super::ctor();
    this->left = left;
    this->right = right;
}

Pair* Pair::of(::java::lang::String* left, ::java::lang::String* right)
{
    clinit();
    return new Pair(left, right);
}

java::lang::String* Pair::getLeft()
{
    return left;
}

java::lang::String* Pair::getRight()
{
    return right;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Pair::class_()
{
    static ::java::lang::Class* c = ::class_(u"Pair", 4);
    return c;
}

java::lang::Class* Pair::getClass0()
{
    return class_();
}

