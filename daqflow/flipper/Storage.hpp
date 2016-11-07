// Generated from /cms.flipper/src/main/java/Storage.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/fwd-cms.flipper.hpp>
#include <SinglePogressObject.hpp>

struct default_init_tag;

class Storage
    : public SinglePogressObject
{

public:
    typedef SinglePogressObject super;
protected:
    void ctor(::java::lang::String* name, int32_t capacity, SoundPlayer* soundPlayer);

public:
    bool canAccept() override;

public: /* protected */
    void finished() override;
    void performInsert(Data* data) override;

    // Generated

public:
    Storage(::java::lang::String* name, int32_t capacity, SoundPlayer* soundPlayer);
protected:
    Storage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
