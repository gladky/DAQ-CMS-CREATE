// Generated from /cms.flipper/src/main/java/IndividualPogressObject.java
#include <IndividualPogressObject.hpp>

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

IndividualPogressObject::IndividualPogressObject(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

IndividualPogressObject::IndividualPogressObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer) 
    : IndividualPogressObject(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,progressStep,soundPlayer);
}

constexpr int32_t IndividualPogressObject::fakeInf;

void IndividualPogressObject::ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer)
{
    super::ctor(name, capacity, progressStep, soundPlayer);
}

void IndividualPogressObject::performInsert(Data* data)
{
    npc(data)->setProgress(0);
    npc(data)->setTimeOutProgress(0);
    npc(queue)->add(data);
    acceptedThisCycle = true;
}

bool IndividualPogressObject::canAccept()
{
    if(acceptedThisCycle) {
        return false;
    }
    return super::canAccept();
}

int32_tArray* IndividualPogressObject::getProgress()
{
    return npc(queue)->getProgress();
}

int32_t IndividualPogressObject::stepImplementation(Data* current)
{
    auto newProgress = npc(current)->getProgress() + progressStep;
    npc(current)->setProgress(newProgress);
    return newProgress;
}

void IndividualPogressObject::doStep()
{
    if(!npc(queue)->isEmpty()) {
        auto localProgressLimit = fakeInf;
        auto initialSize = npc(queue)->size();
        auto recentSize = initialSize;
        for (auto i = int32_t(0); i < recentSize; i++) {
            auto current = npc(queue)->get(i);
            if(npc(current)->getProgress() + progressStep < localProgressLimit) {
                auto progress = stepImplementation(current);
                if(progress < localProgressLimit) {
                    localProgressLimit = progress;
                }
                if(progress > 99) {
                    finished();
                    if(canSend()) {
                        sendData();
                    }
                }
            } else {
                if(npc(current)->getProgress() < localProgressLimit) {
                    localProgressLimit = npc(current)->getProgress();
                }
            }
            if(localProgressLimit > 100) {
                localProgressLimit = 100;
            }
            if(recentSize != npc(queue)->size()) {
                recentSize = npc(queue)->size();
                i--;
            }
        }
    }
    acceptedThisCycle = false;
}

void IndividualPogressObject::finished()
{
    return;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* IndividualPogressObject::class_()
{
    static ::java::lang::Class* c = ::class_(u"IndividualPogressObject", 23);
    return c;
}

java::lang::Class* IndividualPogressObject::getClass0()
{
    return class_();
}

