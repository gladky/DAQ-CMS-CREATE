// Generated from /cms.flipper/src/main/java/SimpleFifoQueue.java
#include "SimpleFifoQueue.hpp"

#include "Data.hpp"

#include <vector>

using namespace std;


SimpleFifoQueue::SimpleFifoQueue(int capacity_) 
{
    capacity= capacity_;
    //queue(capacity_); // underlying data structure is unlimited watch out
    tailIndex = 0;
}


Data* SimpleFifoQueue::peek()
{
    return queue[0];
}

Data* SimpleFifoQueue::poll()
{
    Data* result = queue[0];
    queue.erase(queue.begin()); // remove(0)
    tailIndex--;
    return result;
}

bool SimpleFifoQueue::add(Data* data)
{
    if(tailIndex >= capacity)
        return false;

    queue.insert(queue.begin()+tailIndex, data); // add(index,element)
    tailIndex++;
    return true;
}

int SimpleFifoQueue::size()
{
    return tailIndex;
}

string SimpleFifoQueue::toString()
{
    string result = "";
    for (int i = 0 ; i < tailIndex; i++){
        result.append(queue[i]->getName());
        result.append(",");
    }
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
    return queue[index];
}

void SimpleFifoQueue::clear()
{
    tailIndex = 0;
    queue.clear();
}

vector<int> SimpleFifoQueue::getProgress()
{
    vector<int> progress;
    if(queue.size() == 0) {
        progress.push_back(0);
    }
    for (int i = 0; i < queue.size(); i++) {
        progress.push_back(queue[i]->getProgress());
    }
    
    return progress;
}

