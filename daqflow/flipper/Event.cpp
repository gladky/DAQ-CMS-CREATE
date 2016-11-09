// Generated from /cms.flipper/src/main/java/Event.java
#include "Event.hpp"

#include "Data.hpp"




Event::Event(Data* f1, Data* f2, Data* f3, Data* f4)
: Data(generateSimpleName(f4), false, isInteresting(f1, f2, f3, f4))
{
    this->setTarget(f4->getTarget());
    this->setDispatched(f4->isDispatched());
}



string Event::generateSimpleName(Data* d)
{
    string name = "e";
    name.append(d->getName());
    return name;
}

bool Event::isInteresting(Data* fragment1, Data* fragment2, Data* fragment3, Data* fragment4)
{
    bool interesting = false;
    if(fragment1->isInteresting() && fragment2->isInteresting() && fragment3->isInteresting()&& fragment4->isInteresting()) {
        interesting = true;
    }
    return interesting;
}



bool Event::isInteresting()
{
    return Data::isInteresting();
}

