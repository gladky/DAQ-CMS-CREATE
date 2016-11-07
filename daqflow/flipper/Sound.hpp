// Generated from /cms.flipper/src/main/java/Sound.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/io/fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <java/lang/Enum.hpp>

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

struct default_init_tag;

class Sound final
    : public ::java::lang::Enum
{

public:
    typedef ::java::lang::Enum super;

public: /* package */
    static Sound *GameStart;
    static Sound *GameOver;
    static Sound *EmptyProtonBottle;
    static Sound *FullStorage;
    static Sound *Backpressure;
    static Sound *BackpressureOver;
    static Sound *AcceptedInterestingFragments;
    static Sound *AcceptedInterestingEvent;
    static Sound *AcceptedNonInterestingFragments;
    static Sound *AcceptedNotInteresingEvent;
    static Sound *MissedInterestedEvent;
    static Sound *MissedInterestingFragments;
    static Sound *MissedNotInterestingFragments;
    static Sound *MissedNotInterestingEvent;
    static Sound *ArrivedInterestingToStorage;
    static Sound *ArrivedNotInterestingToStorage;
    static Sound *ButtonPressedWhenDisabled;
    static Sound *ButtonPressedWhenEnabled;

private:
    int32_t id {  };
protected:
    void ctor(::java::lang::String* name, int ordinal, int32_t id);

public:
    int32_t getId();
    static Sound* getById(int32_t id);

    // Generated

private:
    Sound(::java::lang::String* name, int ordinal, int32_t id);
protected:
    Sound(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static Sound* valueOf(::java::lang::String* a0);
    static SoundArray* values();

private:
    virtual ::java::lang::Class* getClass0();
};
