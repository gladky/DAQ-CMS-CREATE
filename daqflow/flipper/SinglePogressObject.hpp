// Generated from /cms.flipper/src/main/java/SinglePogressObject.java

#pragma once

#include "FlipperObject.hpp"


class SinglePogressObject
    : public FlipperObject
{


private:
    int progress;

public: /* protected */
    void performInsert(Data* data) override;

public:
    void doStep() override;
    bool canAccept() override;
    vector<int> getProgress() override;

public: /* protected */
    int stepImplementation(Data* data) override;

    // Generated

public:
    SinglePogressObject(string name, int capacity, int progressStep, SoundPlayer* soundPlayer);



};
