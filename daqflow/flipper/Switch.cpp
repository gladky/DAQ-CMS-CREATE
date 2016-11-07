// Generated from /cms.flipper/src/main/java/Switch.java
#include <Switch.hpp>

#include <Data.hpp>
#include <Event.hpp>
#include <FlipperObject.hpp>
#include <SimpleFifoQueue.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Switch::Switch(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Switch::Switch(::java::lang::String* name, SoundPlayer* soundPlayer) 
    : Switch(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,soundPlayer);
}

void Switch::ctor(::java::lang::String* name, SoundPlayer* soundPlayer)
{
    super::ctor(name, int32_t(4), int32_t(50), soundPlayer);
    this->outputQueue = new SimpleFifoQueue(int32_t(1));
}

bool Switch::canAccept()
{
    auto basicAccept = super::canAccept();
    if(basicAccept) {
        return true;
    } else {
        return false;
    }
}

int32_t Switch::stepImplementation(Data* data)
{
    if(npc(queue)->size() == 4) {
        auto fragment1 = npc(queue)->get(0);
        auto fragment2 = npc(queue)->get(1);
        auto fragment3 = npc(queue)->get(2);
        auto fragment4 = npc(queue)->get(3);
        auto event = new Event(fragment1, fragment2, fragment3, fragment4);
        npc(outputQueue)->add(event);
        npc(queue)->clear();
        return 100;
    } else if(npc(queue)->size() == 3) {
        return 75;
    } else if(npc(queue)->size() == 2) {
        return 50;
    } else if(npc(queue)->size() == 1) {
        return 25;
    } else {
        return 0;
    }
}

bool Switch::canSend()
{
    return true;
}

void Switch::sendData()
{
    auto data = npc(outputQueue)->poll();
    auto bufuSuccessor = npc(data)->getTarget();
    if(npc(bufuSuccessor)->canAccept()) {
        npc(bufuSuccessor)->setBusy(true);
        npc(bufuSuccessor)->insert(data);
        return;
    }
}

void Switch::finished()
{
    return;
}

SimpleFifoQueue* Switch::getOutputQueue()
{
    return outputQueue;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Switch::class_()
{
    static ::java::lang::Class* c = ::class_(u"Switch", 6);
    return c;
}

java::lang::Class* Switch::getClass0()
{
    return class_();
}

