// Generated from /cms.flipper/src/main/java/DataObserver.java

/*
THis class is reduced
*/

#include "BUFU.hpp"
#include "Switch.hpp"
#include "Buffer.hpp"
#include "DataObserver.hpp"
#include "Data.hpp"
#include "Link.hpp"
#include "SimpleFifoQueue.hpp"
#include "Storage.hpp"


DataObserver::DataObserver(FlipperGame* flipperGame)
: FlowObserver(flipperGame, 2,4,5,14,17,4)
{
}

string DataObserver::getState(Link* link)
{
    if(link->getQueue()->queue.size() == 0) {
        return "";
    } else {
        return link->getQueue()->queue[0]->getName();
    }
}


string DataObserver::getState(BUFU* bufu)
{
    if(bufu->getQueue()->queue.size() == 0) {
        return "";
    } else {
        return bufu->getQueue()->get(0)->getName();
    }
}

string DataObserver::getState(Buffer* buffer)
{
    string data = "";
    int elements = buffer->getQueue()->size();
    if(elements == 0) {
        data = "";
    } else if(elements == 1) {
        data = buffer->getQueue()->get(0)->getName();
    } else {
        data.append("[");
	data.append(toString(elements));
	data.append("]");
    }
    return data;
}

string DataObserver::getState(Storage* storage)
{
    string result = "";
    for (int i = 0; i < storage->getQueue()->queue.size(); i++ ) {
        Data* data = storage->getQueue()->queue[i];
        {
            result.append(data->getName());
        }
    }
    return result;
}


string DataObserver::getState(Switch* switch_)
{
    return FlowObserver::getState(switch_);
}


