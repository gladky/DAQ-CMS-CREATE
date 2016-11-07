// Generated from /cms.flipper/src/main/java/Dispatcher.java
#include <Dispatcher.hpp>

#include <FlipperObject.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/List.hpp>
#include <java/util/Random.hpp>

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

Dispatcher::Dispatcher(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Dispatcher::Dispatcher(::java::util::List* targets, ::java::util::List* linksToTargets, SoundPlayer* soundPlayer) 
    : Dispatcher(*static_cast< ::default_init_tag* >(0))
{
    ctor(targets,linksToTargets,soundPlayer);
}

void Dispatcher::ctor(::java::util::List* targets, ::java::util::List* linksToTargets, SoundPlayer* soundPlayer)
{
    super::ctor(u"Dispatcher"_j);
    this->targets = targets;
    this->linksToTarget = linksToTargets;
    this->valid = false;
    this->backpressure = false;
    this->soundPlayer = soundPlayer;
}

FlipperObject* Dispatcher::getTarget(int32_t id)
{
    return java_cast< FlipperObject* >(npc(targets)->get(id));
}

FlipperObject* Dispatcher::getLink(int32_t id)
{
    return java_cast< FlipperObject* >(npc(linksToTarget)->get(id));
}

int32_t Dispatcher::findAvailableTarget()
{
    if(valid) {
    } else {
        result = -int32_t(1);
        ::java::util::List* ready = new ::java::util::ArrayList();
        for (auto i = int32_t(0); i < npc(targets)->size(); i++) {
            auto bufu = java_cast< FlipperObject* >(npc(targets)->get(i));
            if(!npc(bufu)->isBusy() && npc(bufu)->canAccept()) {
                npc(ready)->add(::java::lang::Integer::valueOf(i));
            }
        }
        if(npc(ready)->size() > 0) {
            if(backpressure == true) {
                npc(soundPlayer)->register_(Sound::BackpressureOver);
            }
            backpressure = false;
            int32_t choosenRandom = (npc(java_cast< ::java::lang::Integer* >(npc(ready)->get((new ::java::util::Random())->nextInt(npc(ready)->size())))))->intValue();
            int32_t choosen = (npc(java_cast< ::java::lang::Integer* >(npc(ready)->get(0))))->intValue();
            result = choosenRandom;
            result = choosen;
            valid = true;
        } else {
            if(backpressure == false) {
                npc(soundPlayer)->register_(Sound::Backpressure);
            }
            backpressure = true;
        }
    }
    return result;
}

void Dispatcher::invalidate()
{
    result = -int32_t(1);
    valid = false;
}

bool Dispatcher::isBackpressure()
{
    return backpressure;
}

int32_t Dispatcher::getResult()
{
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Dispatcher::class_()
{
    static ::java::lang::Class* c = ::class_(u"Dispatcher", 10);
    return c;
}

java::lang::Class* Dispatcher::getClass0()
{
    return class_();
}

