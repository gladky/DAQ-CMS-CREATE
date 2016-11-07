// Generated from /cms.flipper/src/main/java/FlipperObject.java
#include <FlipperObject.hpp>

#include <Data.hpp>
#include <Link.hpp>
#include <SimpleFifoQueue.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

FlipperObject::FlipperObject(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

FlipperObject::FlipperObject(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer) 
    : FlipperObject(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,capacity,progressStep,soundPlayer);
}

void FlipperObject::ctor(::java::lang::String* name, int32_t capacity, int32_t progressStep, SoundPlayer* soundPlayer)
{
    super::ctor(name);
    this->progressStep = progressStep;
    this->successors = new ::java::util::ArrayList();
    this->capacity = capacity;
    this->queue = new SimpleFifoQueue(capacity);
    this->setBusy(false);
    this->soundPlayer = soundPlayer;
}

bool FlipperObject::insert(Data* data)
{
    if(!canAccept()) {
        return false;
    } else {
        performInsert(data);
        reserved = false;
        return true;
    }
}

bool FlipperObject::canAccept()
{
    bool iAmAbleToAccept;
    if(npc(queue)->size() == capacity) {
        iAmAbleToAccept = false;
        return false;
    } else {
        iAmAbleToAccept = true;
    }
    auto existsNonLinkSuccessorsCanAccept = false;
    if(dynamic_cast< Link* >(this) != nullptr) {
        for (auto _i = npc(successors)->iterator(); _i->hasNext(); ) {
            FlipperObject* successor = java_cast< FlipperObject* >(_i->next());
            {
                auto canAccept = npc(successor)->canAccept();
                if(canAccept == true) {
                    existsNonLinkSuccessorsCanAccept = true;
                }
            }
        }
    } else {
        existsNonLinkSuccessorsCanAccept = true;
    }
    if(iAmAbleToAccept == false || existsNonLinkSuccessorsCanAccept == false) {
        return false;
    } else {
        return true;
    }
}

bool FlipperObject::canSend()
{
    auto allDirectAccept = true;
    for (auto _i = npc(successors)->iterator(); _i->hasNext(); ) {
        FlipperObject* successor = java_cast< FlipperObject* >(_i->next());
        {
            auto accept = npc(successor)->canAccept();
            if(!accept) {
                allDirectAccept = false;
            }
        }
    }
    if(allDirectAccept) {
        return true;
    } else {
        return false;
    }
}

void FlipperObject::sendData()
{
    auto data = npc(queue)->poll();
    for (auto _i = npc(successors)->iterator(); _i->hasNext(); ) {
        FlipperObject* successor = java_cast< FlipperObject* >(_i->next());
        {
            npc(successor)->insert(data);
        }
    }
}

java::util::List* FlipperObject::getSuccessors()
{
    return successors;
}

bool FlipperObject::isBusy()
{
    return reserved;
}

void FlipperObject::setBusy(bool busy)
{
    this->reserved = busy;
}

SimpleFifoQueue* FlipperObject::getQueue()
{
    return queue;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* FlipperObject::class_()
{
    static ::java::lang::Class* c = ::class_(u"FlipperObject", 13);
    return c;
}

java::lang::Class* FlipperObject::getClass0()
{
    return class_();
}

