// Generated from /cms.flipper/src/main/java/FlowObserver.java

#pragma once

/*
This class is reduced, uncomment
*/

#include "FlipperGame.hpp"
#include "Link.hpp"
#include "NamedObject.hpp"
#include "FlipperObject.hpp"

#include <string>
#include <vector>
using namespace std;

class FlipperGame;

class FlowObserver
{


private:
    int MIN_WIDTH ;
    int WIDTH ;
    int SWITCH_WIDTH ;
    int STORAGE_WIDTH ;
    int SOUND_WIDTH ;
    int BUFFER_WIDTH ;
    static string empty_;
    vector<NamedObject*> observedObjects ;
    vector<vector<string> > states;
    vector<int> lengths; // map was used

public: /* protected */
    virtual string getState(Link* link) = 0;
    //virtual string getState(BUFU* bufu) = 0;
    //virtual string getState(Buffer* buffer) = 0;
    //virtual string getState(Storage* storage) = 0;
    //virtual string getState(Switch* switch_);

private:
    string getState(FlipperObject* observedObject);
    //Pair* getState(Button* observedButtonObject);

public:
    virtual void persist();
    string toString();// override;

private:
    string toString(vector<string> row);

public:

    // Generated
    FlowObserver(FlipperGame* flipperGame, int minWidth, int width, int switchWidth, int storageWidth, int soundWidth, int bufferWidth);

    static string fixedLengthString(string string, int length);


};
