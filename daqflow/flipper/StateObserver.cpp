// Generated from /cms.flipper/src/main/java/StateObserver.java
#include <StateObserver.hpp>

#include <BUFU.hpp>
#include <Buffer.hpp>
#include <Link.hpp>
#include <Storage.hpp>




//TODO: inheritance
void StateObserver::ctor(FlipperGame* flipperGame): FlowObserver
{
    super::ctor(flipperGame, int32_t(3), int32_t(3), int32_t(3), int32_t(3), int32_t(3), int32_t(8));
}

string StateObserver::getState(Link* link)
{
    return spaceSafePrintList(link->getProgress());
}

string StateObserver::getState(BUFU* bufu)
{
    return spaceSafePrintList(bufu->getProgress());
}

string StateObserver::getState(Buffer* buffer)
{
    return spaceSafePrintList(buffer->getProgress());
}

string StateObserver::getState(Storage* storage)
{
    return spaceSafePrintList(storage->getProgress());
}

string StateObserver::spaceSafePrintList(vector<?> list)
{
    string result = "";
    for (int32_t i = 0; i < list->size(); i++) {
        if(i != 0) {
            result = result.append(",");
        }
        result = result.append((*list)[i])->toString();
    }
    return result;
}



string StateObserver::getState(Switch* switch_)
{
    return super::getState(switch_);
}


