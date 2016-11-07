// Generated from /cms.flipper/src/main/java/BUFU.java
#include <BUFU.hpp>

#include <Data.hpp>
#include <FlipperObject.hpp>
#include <Link.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
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

BUFU::BUFU(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

BUFU::BUFU(::java::lang::String* name, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer) 
    : BUFU(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,progressStep,timeoutStep,button,soundPlayer);
}

void BUFU::ctor(::java::lang::String* name, int32_t progressStep, int32_t timeoutStep, Button* button, SoundPlayer* soundPlayer)
{
    super::ctor(name, int32_t(1), progressStep, timeoutStep, button, soundPlayer);
}

bool BUFU::canSend()
{
    auto basicCheck = super::canSend();
    auto allLinksFree = true;
    for (auto _i = npc(getSuccessors())->iterator(); _i->hasNext(); ) {
        FlipperObject* successor = java_cast< FlipperObject* >(_i->next());
        {
            auto linksReserved = checkLinksReserved(successor);
            if(linksReserved) {
                allLinksFree = false;
            }
        }
    }
    if(basicCheck && allLinksFree) {
        return true;
    } else {
        return false;
    }
}

void BUFU::sendData()
{
    for (auto _i = npc(getSuccessors())->iterator(); _i->hasNext(); ) {
        FlipperObject* successor = java_cast< FlipperObject* >(_i->next());
        {
            reserveLinks(successor);
        }
    }
    super::sendData();
}

bool BUFU::checkLinksReserved(FlipperObject* successor)
{
    if(dynamic_cast< Link* >(successor) != nullptr) {
        auto reserved = npc(successor)->isBusy();
        if(reserved) {
            return true;
        } else {
            for (auto _i = npc(npc(successor)->getSuccessors())->iterator(); _i->hasNext(); ) {
                FlipperObject* next = java_cast< FlipperObject* >(_i->next());
                {
                    return checkLinksReserved(next);
                }
            }
        }
    }
    return false;
}

void BUFU::reserveLinks(FlipperObject* successor)
{
    if(dynamic_cast< Link* >(successor) != nullptr) {
        npc(successor)->setBusy(true);
        for (auto _i = npc(npc(successor)->getSuccessors())->iterator(); _i->hasNext(); ) {
            FlipperObject* next = java_cast< FlipperObject* >(_i->next());
            {
                reserveLinks(next);
            }
        }
    }
}

void BUFU::registerAcceptedSound(bool interesting)
{
    if(interesting) {
        npc(soundPlayer)->register_(Sound::AcceptedInterestingEvent);
    } else {
        npc(soundPlayer)->register_(Sound::AcceptedNotInteresingEvent);
    }
}

void BUFU::registerMissedSound(bool interesting)
{
    if(interesting) {
        npc(soundPlayer)->register_(Sound::MissedInterestedEvent);
    } else {
        npc(soundPlayer)->register_(Sound::MissedNotInterestingEvent);
    }
}

bool BUFU::insert(Data* data)
{
    npc(data)->setDispatched(false);
    return super::insert(data);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* BUFU::class_()
{
    static ::java::lang::Class* c = ::class_(u"BUFU", 4);
    return c;
}

java::lang::Class* BUFU::getClass0()
{
    return class_();
}

