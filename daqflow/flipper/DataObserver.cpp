// Generated from /cms.flipper/src/main/java/DataObserver.java
#include <DataObserver.hpp>

#include <BUFU.hpp>
#include <Buffer.hpp>
#include <Data.hpp>
#include <Link.hpp>
#include <SimpleFifoQueue.hpp>
#include <Storage.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

DataObserver::DataObserver(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

DataObserver::DataObserver(FlipperGame* flipperGame) 
    : DataObserver(*static_cast< ::default_init_tag* >(0))
{
    ctor(flipperGame);
}

void DataObserver::ctor(FlipperGame* flipperGame)
{
    super::ctor(flipperGame, int32_t(2), int32_t(4), int32_t(5), int32_t(14), int32_t(7), int32_t(4));
}

java::lang::String* DataObserver::getState(Link* link)
{
    if(npc(java_cast< ::java::util::List* >(npc(npc(link)->getQueue())->queue))->size() == 0) {
        return u""_j;
    } else {
        return npc(java_cast< Data* >(npc(java_cast< ::java::util::List* >(npc(npc(link)->getQueue())->queue))->get(0)))->getName();
    }
}

java::lang::String* DataObserver::getState(BUFU* bufu)
{
    if(npc(java_cast< ::java::util::List* >(npc(npc(bufu)->getQueue())->queue))->size() == 0) {
        return u""_j;
    } else {
        return npc(java_cast< Data* >(npc(java_cast< ::java::util::List* >(npc(npc(bufu)->getQueue())->queue))->get(0)))->getName();
    }
}

java::lang::String* DataObserver::getState(Buffer* buffer)
{
    auto data = u""_j;
    auto elements = npc(npc(buffer)->getQueue())->size();
    if(elements == 0) {
        data = empty();
    } else if(elements == 1) {
        data = npc(npc(npc(buffer)->getQueue())->get(0))->getName();
    } else {
        data = ::java::lang::StringBuilder().append(u"["_j)->append(elements)
            ->append(u"]"_j)->toString();
    }
    return data;
}

java::lang::String* DataObserver::getState(Storage* storage)
{
    auto result = u""_j;
    for (auto _i = npc(java_cast< ::java::util::List* >(npc(npc(storage)->getQueue())->queue))->iterator(); _i->hasNext(); ) {
        Data* data = java_cast< Data* >(_i->next());
        {
            result = ::java::lang::StringBuilder(result).append(npc(data)->getName())->toString();
        }
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* DataObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"DataObserver", 12);
    return c;
}

java::lang::String* DataObserver::getState(Switch* switch_)
{
    return super::getState(switch_);
}

java::lang::Class* DataObserver::getClass0()
{
    return class_();
}

