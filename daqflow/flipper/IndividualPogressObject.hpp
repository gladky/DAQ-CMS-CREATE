// Generated from /cms.flipper/src/main/java/IndividualPogressObject.java

#pragma once

#include "FlipperObject.hpp"


class IndividualPogressObject
    : public FlipperObject
{


private:
    bool acceptedThisCycle;
    static int fakeInf ;

public: /* protected */
    void performInsert(Data* data) override;

public:
    bool canAccept() override;
    vector<int> getProgress() override;
    int stepImplementation(Data* current) override;
    void doStep() override;

public: /* protected */
    void finished() override;

    // Generated

public:
    IndividualPogressObject(string name, int capacity, int progressStep, SoundPlayer* soundPlayer);


};
