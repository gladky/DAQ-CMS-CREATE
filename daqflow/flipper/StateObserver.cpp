// Generated from /cms.flipper/src/main/java/StateObserver.java
#include <StateObserver.hpp>

#include <BUFU.hpp>
#include <Buffer.hpp>
#include <Link.hpp>
#include <Storage.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

StateObserver::StateObserver(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

StateObserver::StateObserver(FlipperGame* flipperGame) 
    : StateObserver(*static_cast< ::default_init_tag* >(0))
{
    ctor(flipperGame);
}

void StateObserver::ctor(FlipperGame* flipperGame)
{
    super::ctor(flipperGame, int32_t(3), int32_t(3), int32_t(3), int32_t(3), int32_t(3), int32_t(8));
}

java::lang::String* StateObserver::getState(Link* link)
{
    return spaceSafePrintList(npc(link)->getProgress());
}

java::lang::String* StateObserver::getState(BUFU* bufu)
{
    return spaceSafePrintList(npc(bufu)->getProgress());
}

java::lang::String* StateObserver::getState(Buffer* buffer)
{
    return spaceSafePrintList(npc(buffer)->getProgress());
}

java::lang::String* StateObserver::getState(Storage* storage)
{
    return spaceSafePrintList(npc(storage)->getProgress());
}

java::lang::String* StateObserver::spaceSafePrintList(::int32_tArray* list)
{
    auto result = u""_j;
    for (auto i = int32_t(0); i < npc(list)->length; i++) {
        if(i != 0) {
            result = ::java::lang::StringBuilder(result).append(u","_j)->toString();
        }
        result = ::java::lang::StringBuilder(result).append((*list)[i])->toString();
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* StateObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"StateObserver", 13);
    return c;
}

java::lang::String* StateObserver::getState(Switch* switch_)
{
    return super::getState(switch_);
}

java::lang::Class* StateObserver::getClass0()
{
    return class_();
}

