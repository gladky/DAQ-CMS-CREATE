// Generated from /cms.flipper/src/main/java/Event.java

#pragma once

#include "Data.hpp"


class Event
    : public Data
{


private:
    static string generateSimpleName(Data* d);
    static bool isInteresting(Data* fragment1, Data* fragment2, Data* fragment3, Data* fragment4);

    // Generated

public:
    Event(Data* f1, Data* f2, Data* f3, Data* f4);
    //Event(string name, bool interesting);
    //Event(string name);


public:
    virtual bool isInteresting();

};
