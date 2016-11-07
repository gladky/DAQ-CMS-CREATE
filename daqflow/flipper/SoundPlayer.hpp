// Generated from /cms.flipper/src/main/java/SoundPlayer.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <java/util/fwd-cms.flipper.hpp>
#include <NamedObject.hpp>

struct default_init_tag;

class SoundPlayer
    : public NamedObject
{

public:
    typedef NamedObject super;
protected:
    void ctor(::java::lang::String* name);

private:
    ::java::util::List* sounds {  };

public:
    virtual void register_(int32_t soundId);
    virtual ::java::util::List* getSounds();
    virtual void flush();
    virtual void register_(Sound* sound);

    // Generated
    SoundPlayer(::java::lang::String* name);
protected:
    SoundPlayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
