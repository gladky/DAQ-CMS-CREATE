// Generated from /cms.flipper/src/main/java/SinglePogressObject.java
#include <SinglePogressObject.hpp>

#include <Data.hpp>
#include <SimpleFifoQueue.hpp>
#include <java/lang/NullPointerException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

SinglePogressObject::SinglePogressObject(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

SinglePogressObject::SinglePogressObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer) 
    : SinglePogressObject(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,progressStep,soundPlayer);
}

void SinglePogressObject::ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer)
{
    super::ctor(name, capacity, progressStep, soundPlayer);
}

void SinglePogressObject::performInsert(Data* data)
{
    npc(queue)->add(data);
    auto size = npc(queue)->size();
    auto result = size * int32_t(100) / capacity;
    this->progress = result;
}

void SinglePogressObject::doStep()
{
    auto progress = stepImplementation(static_cast< Data* >(nullptr));
    if(progress > 99) {
        if(canSend()) {
            sendData();
        }
    }
}

bool SinglePogressObject::canAccept()
{
    if(npc(queue)->size() == capacity) {
        return false;
    } else {
        return true;
    }
}

int32_tArray* SinglePogressObject::getProgress()
{
    return new ::int32_tArray({progress});
}

int32_t SinglePogressObject::stepImplementation(Data* data)
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* SinglePogressObject::class_()
{
    static ::java::lang::Class* c = ::class_(u"SinglePogressObject", 19);
    return c;
}

java::lang::Class* SinglePogressObject::getClass0()
{
    return class_();
}

