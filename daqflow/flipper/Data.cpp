// Generated from /cms.flipper/src/main/java/Data.java
#include <Data.hpp>

#include <FlipperObject.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Data::Data(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Data::Data(::java::lang::String* name, bool isFragment, bool isInteresting) 
    : Data(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,isFragment,isInteresting);
}

void Data::ctor(::java::lang::String* name, bool isFragment, bool isInteresting)
{
    super::ctor();
    this->isFragment_ = isFragment;
    this->isInteresting_ = isInteresting;
    ::java::lang::String* modifiedName;
    if(this->isInteresting_ && !this->isFragment_) {
        modifiedName = npc(name)->toUpperCase();
    } else {
        modifiedName = name;
    }
    this->name = modifiedName;
}

java::lang::String* Data::getName()
{
    return name;
}

java::lang::String* Data::toString()
{
    return ::java::lang::StringBuilder().append(u"Data [name="_j)->append(name)
        ->append(u"]"_j)->toString();
}

FlipperObject* Data::getTarget()
{
    return target;
}

void Data::setTarget(FlipperObject* target)
{
    this->target = target;
}

bool Data::isDispatched()
{
    return dispatched;
}

void Data::setDispatched(bool dispatched)
{
    this->dispatched = dispatched;
}

int32_t Data::getProgress()
{
    return progress;
}

void Data::setProgress(int32_t progress)
{
    this->progress = progress;
}

bool Data::isInteresting()
{
    return isInteresting_;
}

bool Data::isFragment()
{
    return isFragment_;
}

int32_t Data::getTimeOutProgress()
{
    return timeOutProgress;
}

void Data::setTimeOutProgress(int32_t timeOutProgress)
{
    this->timeOutProgress = timeOutProgress;
}

int32_t Data::getTargetIndex()
{
    return targetIndex;
}

void Data::setTargetIndex(int32_t targetIndex)
{
    this->targetIndex = targetIndex;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Data::class_()
{
    static ::java::lang::Class* c = ::class_(u"Data", 4);
    return c;
}

java::lang::Class* Data::getClass0()
{
    return class_();
}

