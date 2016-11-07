// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java
#include <SimpleFifoQueue.hpp>

#include <Data.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/List.hpp>
#include <Array.hpp>

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

SimpleFifoQueue::SimpleFifoQueue(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

SimpleFifoQueue::SimpleFifoQueue(int32_t capacity) 
    : SimpleFifoQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(capacity);
}

void SimpleFifoQueue::ctor(int32_t capacity)
{
    super::ctor();
    this->capacity = capacity;
    this->queue = new ::java::util::ArrayList(capacity);
    this->tailIndex = 0;
}

Data* SimpleFifoQueue::peek()
{
    return java_cast< Data* >(npc(queue)->get(0));
}

Data* SimpleFifoQueue::poll()
{
    auto result = java_cast< Data* >(npc(queue)->remove(int32_t(0)));
    tailIndex--;
    return result;
}

bool SimpleFifoQueue::add(Data* data)
{
    if(tailIndex >= capacity)
        return false;

    npc(queue)->add(tailIndex, data);
    tailIndex++;
    return true;
}

int32_t SimpleFifoQueue::size()
{
    return tailIndex;
}

java::lang::String* SimpleFifoQueue::toString()
{
    return npc(queue)->toString();
}

bool SimpleFifoQueue::isEmpty()
{
    if(size() == 0)
        return true;
    else
        return false;
}

Data* SimpleFifoQueue::get(int32_t index)
{
    return java_cast< Data* >(npc(queue)->get(index));
}

void SimpleFifoQueue::clear()
{
    tailIndex = 0;
    npc(queue)->clear();
}

int32_tArray* SimpleFifoQueue::getProgress()
{
    if(npc(queue)->size() == 0) {
        return new ::int32_tArray({int32_t(0)});
    }
    auto progressArray_ = new ::int32_tArray(npc(queue)->size());
    for (auto i = int32_t(0); i < npc(queue)->size(); i++) {
        (*progressArray_)[i] = npc(java_cast< Data* >(npc(queue)->get(i)))->getProgress();
    }
    return progressArray_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* SimpleFifoQueue::class_()
{
    static ::java::lang::Class* c = ::class_(u"SimpleFifoQueue", 15);
    return c;
}

java::lang::Class* SimpleFifoQueue::getClass0()
{
    return class_();
}

