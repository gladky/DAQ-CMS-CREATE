// Generated from /cms.flipper/src/main/java/Storage.java
#include <Storage.hpp>

#include <Data.hpp>
#include <SimpleFifoQueue.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Storage::Storage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Storage::Storage(::java::lang::String* name, int32_t capacity, SoundPlayer* soundPlayer) 
    : Storage(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,soundPlayer);
}

void Storage::ctor(::java::lang::String* name, int32_t capacity, SoundPlayer* soundPlayer)
{
    super::ctor(name, capacity, int32_t(0), soundPlayer);
}

bool Storage::canAccept()
{
    if(npc(queue)->size() == capacity) {
        return false;
    } else {
        return true;
    }
}

void Storage::finished()
{
}

void Storage::performInsert(Data* data)
{
    super::performInsert(data);
    if(npc(data)->isInteresting()) {
        npc(soundPlayer)->register_(Sound::ArrivedInterestingToStorage);
    } else {
        npc(soundPlayer)->register_(Sound::ArrivedNotInterestingToStorage);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Storage::class_()
{
    static ::java::lang::Class* c = ::class_(u"Storage", 7);
    return c;
}

java::lang::Class* Storage::getClass0()
{
    return class_();
}

