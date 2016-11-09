// Generated from /cms.flipper/src/main/java/Storage.java

#pragma once

#include "SinglePogressObject.hpp"


class Storage
    : public SinglePogressObject
{

public:
    bool canAccept() override;

public: /* protected */
    void finished() override;
    void performInsert(Data* data) override;

    // Generated

public:
    Storage(string name, int capacity, SoundPlayer* soundPlayer);

};
