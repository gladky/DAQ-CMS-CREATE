// Generated from /cms.flipper/src/main/java/DataObserver.java

/*
THis class is reduced
*/

//#include <BUFU.hpp>
//#include <Buffer.hpp>
#include "DataObserver.hpp"
#include "Data.hpp"
#include "Link.hpp"
#include "SimpleFifoQueue.hpp"
#include "Storage.hpp"


DataObserver::DataObserver(FlipperGame* flipperGame)
: FlowObserver(flipperGame, 2,4,5,14,7,4)
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

/*
java::lang::String* DataObserver::getState(BUFU* bufu)
{
    if(npc(java_cast< ::java::util::List* >(npc(npc(bufu)->getQueue())->queue))->size() == 0) {
        return u""_j;
    } else {
        return npc(java_cast< Data* >(npc(java_cast< ::java::util::List* >(npc(npc(bufu)->getQueue())->queue))->get(0)))->getName();
    }
}

java::lang::String* DataObserver::getState(Buffer* buffer)
{
    auto data = u""_j;
    auto elements = npc(npc(buffer)->getQueue())->size();
    if(elements == 0) {
        data = empty();
    } else if(elements == 1) {
        data = npc(npc(npc(buffer)->getQueue())->get(0))->getName();
    } else {
        data = ::java::lang::StringBuilder().append(u"["_j)->append(elements)
            ->append(u"]"_j)->toString();
    }
    return data;
}
*/
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


/*java::lang::String* DataObserver::getState(Switch* switch_)
{
    return super::getState(switch_);
}*/


