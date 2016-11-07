// Generated from /cms.flipper/src/main/java/Fragment.java
#include <Fragment.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

Fragment::Fragment(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Fragment::Fragment(bool interesting) 
    : Fragment(*static_cast< ::default_init_tag* >(0))
{
    ctor(interesting);
}

Fragment::Fragment() 
    : Fragment(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& Fragment::id()
{
    clinit();
    return id_;
}
int32_t Fragment::id_;

void Fragment::ctor(bool interesting)
{
    super::ctor(::java::lang::StringBuilder().append(u""_j)->append(id_)->toString(), true, interesting);
    id_++;
}

void Fragment::ctor()
{
    ctor(false);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Fragment::class_()
{
    static ::java::lang::Class* c = ::class_(u"Fragment", 8);
    return c;
}

void Fragment::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        id_ = int32_t(0);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* Fragment::getClass0()
{
    return class_();
}

