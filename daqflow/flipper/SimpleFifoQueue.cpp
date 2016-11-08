// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java
#include <SimpleFifoQueue.hpp>

#include <Data.hpp>



SimpleFifoQueue::SimpleFifoQueue(int capacity_) 
{
    capacity= capacity_;
    queue(capacity_);
    tailIndex = 0;
}


Data* SimpleFifoQueue::peek()
{
    return queue->get(0);
}

Data* SimpleFifoQueue::poll()
{
    Data result = queue->erase(0);
    tailIndex--;
    return result;
}

bool SimpleFifoQueue::add(Data* data)
{
    if(tailIndex >= capacity)
        return false;

    queue->insert(tailIndex, data);
    tailIndex++;
    return true;
}

int32_t SimpleFifoQueue::size()
{
    return tailIndex;
}

string SimpleFifoQueue::toString()
{
    string result = "";
    for (it=queue.begin(); it<queue.end(); it++)
        result.append(*it);
        result.append(",")
    return result;
}

bool SimpleFifoQueue::isEmpty()
{
    if(size() == 0)
        return true;
    else
        return false;
}

Data* SimpleFifoQueue::get(int index)
{
    return queue->get(index);
}

void SimpleFifoQueue::clear()
{
    tailIndex = 0;
    queue->clear();
}

vector<int> SimpleFifoQueue::getProgress()
{
    if(queue->size() == 0) {
        return new ::int32_tArray({int32_t(0)});
    }
    auto progressArray_ = new ::int32_tArray(npc(queue)->size());
    for (auto i = int32_t(0); i < npc(queue)->size(); i++) {
        (*progressArray_)[i] = npc(java_cast< Data* >(npc(queue)->get(i)))->getProgress();
    }
    return progressArray_;
}

