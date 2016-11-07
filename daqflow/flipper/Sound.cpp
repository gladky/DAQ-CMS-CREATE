// Generated from /cms.flipper/src/main/java/Sound.java
#include <Sound.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Enum.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Enum, ObjectArray, ComparableArray, ::java::io::SerializableArray > EnumArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::Sound, ::java::lang::EnumArray > SoundArray;
} // 

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Sound::Sound(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Sound::Sound(::java::lang::String* name, int ordinal, int32_t id) 
    : Sound(*static_cast< ::default_init_tag* >(0))
{
    ctor(name, ordinal, id);
}

Sound* Sound::GameStart = new ::Sound(u"GameStart"_j, 0, int32_t(1));
Sound* Sound::GameOver = new ::Sound(u"GameOver"_j, 1, int32_t(2));
Sound* Sound::EmptyProtonBottle = new ::Sound(u"EmptyProtonBottle"_j, 2, int32_t(10));
Sound* Sound::FullStorage = new ::Sound(u"FullStorage"_j, 3, int32_t(11));
Sound* Sound::Backpressure = new ::Sound(u"Backpressure"_j, 4, int32_t(12));
Sound* Sound::BackpressureOver = new ::Sound(u"BackpressureOver"_j, 5, int32_t(13));
Sound* Sound::AcceptedInterestingFragments = new ::Sound(u"AcceptedInterestingFragments"_j, 6, int32_t(20));
Sound* Sound::AcceptedInterestingEvent = new ::Sound(u"AcceptedInterestingEvent"_j, 7, int32_t(21));
Sound* Sound::AcceptedNonInterestingFragments = new ::Sound(u"AcceptedNonInterestingFragments"_j, 8, int32_t(22));
Sound* Sound::AcceptedNotInteresingEvent = new ::Sound(u"AcceptedNotInteresingEvent"_j, 9, int32_t(23));
Sound* Sound::MissedInterestedEvent = new ::Sound(u"MissedInterestedEvent"_j, 10, int32_t(31));
Sound* Sound::MissedInterestingFragments = new ::Sound(u"MissedInterestingFragments"_j, 11, int32_t(32));
Sound* Sound::MissedNotInterestingFragments = new ::Sound(u"MissedNotInterestingFragments"_j, 12, int32_t(33));
Sound* Sound::MissedNotInterestingEvent = new ::Sound(u"MissedNotInterestingEvent"_j, 13, int32_t(34));
Sound* Sound::ArrivedInterestingToStorage = new ::Sound(u"ArrivedInterestingToStorage"_j, 14, int32_t(40));
Sound* Sound::ArrivedNotInterestingToStorage = new ::Sound(u"ArrivedNotInterestingToStorage"_j, 15, int32_t(41));
Sound* Sound::ButtonPressedWhenDisabled = new ::Sound(u"ButtonPressedWhenDisabled"_j, 16, int32_t(50));
Sound* Sound::ButtonPressedWhenEnabled = new ::Sound(u"ButtonPressedWhenEnabled"_j, 17, int32_t(51));
void Sound::ctor(::java::lang::String* name, int ordinal, int32_t id)
{
    super::ctor(name, ordinal);
    this->id = id;
}

int32_t Sound::getId()
{
    return this->id;
}

Sound* Sound::getById(int32_t id)
{
    clinit();
    for(auto sound : *npc(Sound::values())) {
        if(npc(sound)->getId() == id) {
            return sound;
        }
    }
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Sound::class_()
{
    static ::java::lang::Class* c = ::class_(u"Sound", 5);
    return c;
}

Sound* Sound::valueOf(::java::lang::String* a0)
{
    if(AcceptedInterestingEvent->toString()->equals(a0))
        return AcceptedInterestingEvent;
    if(AcceptedInterestingFragments->toString()->equals(a0))
        return AcceptedInterestingFragments;
    if(AcceptedNonInterestingFragments->toString()->equals(a0))
        return AcceptedNonInterestingFragments;
    if(AcceptedNotInteresingEvent->toString()->equals(a0))
        return AcceptedNotInteresingEvent;
    if(ArrivedInterestingToStorage->toString()->equals(a0))
        return ArrivedInterestingToStorage;
    if(ArrivedNotInterestingToStorage->toString()->equals(a0))
        return ArrivedNotInterestingToStorage;
    if(Backpressure->toString()->equals(a0))
        return Backpressure;
    if(BackpressureOver->toString()->equals(a0))
        return BackpressureOver;
    if(ButtonPressedWhenDisabled->toString()->equals(a0))
        return ButtonPressedWhenDisabled;
    if(ButtonPressedWhenEnabled->toString()->equals(a0))
        return ButtonPressedWhenEnabled;
    if(EmptyProtonBottle->toString()->equals(a0))
        return EmptyProtonBottle;
    if(FullStorage->toString()->equals(a0))
        return FullStorage;
    if(GameOver->toString()->equals(a0))
        return GameOver;
    if(GameStart->toString()->equals(a0))
        return GameStart;
    if(MissedInterestedEvent->toString()->equals(a0))
        return MissedInterestedEvent;
    if(MissedInterestingFragments->toString()->equals(a0))
        return MissedInterestingFragments;
    if(MissedNotInterestingEvent->toString()->equals(a0))
        return MissedNotInterestingEvent;
    if(MissedNotInterestingFragments->toString()->equals(a0))
        return MissedNotInterestingFragments;
    throw new ::java::lang::IllegalArgumentException(a0);
}

SoundArray* Sound::values()
{
    return new SoundArray({
        AcceptedInterestingEvent,
        AcceptedInterestingFragments,
        AcceptedNonInterestingFragments,
        AcceptedNotInteresingEvent,
        ArrivedInterestingToStorage,
        ArrivedNotInterestingToStorage,
        Backpressure,
        BackpressureOver,
        ButtonPressedWhenDisabled,
        ButtonPressedWhenEnabled,
        EmptyProtonBottle,
        FullStorage,
        GameOver,
        GameStart,
        MissedInterestedEvent,
        MissedInterestingFragments,
        MissedNotInterestingEvent,
        MissedNotInterestingFragments,
    });
}

java::lang::Class* Sound::getClass0()
{
    return class_();
}

