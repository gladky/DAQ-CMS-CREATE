// Generated from /cms.flipper/src/main/java/SoundPlayer.java
#include <SoundPlayer.hpp>

#include <Sound.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/List.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

SoundPlayer::SoundPlayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

SoundPlayer::SoundPlayer(::java::lang::String* name) 
    : SoundPlayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void SoundPlayer::ctor(::java::lang::String* name)
{
    super::ctor(name);
    sounds = new ::java::util::ArrayList();
}

void SoundPlayer::register_(int32_t soundId)
{
    npc(sounds)->add(::java::lang::Integer::valueOf(soundId));
}

java::util::List* SoundPlayer::getSounds()
{
    return sounds;
}

void SoundPlayer::flush()
{
    npc(sounds)->clear();
}

void SoundPlayer::register_(Sound* sound)
{
    register_(npc(sound)->getId());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* SoundPlayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"SoundPlayer", 11);
    return c;
}

java::lang::Class* SoundPlayer::getClass0()
{
    return class_();
}

