// Generated from /cms.flipper/src/main/java/DataObserver.java

#pragma once
/*
this class is reduced
*/

#include "FlowObserver.hpp"
#include "Storage.hpp"
#include "Link.hpp"
#include "Buffer.hpp"


class DataObserver
    : public FlowObserver
{

public: /* protected */
    string getState(Link* link) override;
    //string getState(BUFU* bufu) override;
    string getState(Buffer* buffer) override;
    string getState(Storage* storage) override;

    // Generated

public:
    DataObserver(FlipperGame* flipperGame);


//public: /* protected */
//    virtual string getState(Switch* switch_);

};
