// Generated from /cms.flipper/src/main/java/GameController.java

#pragma once


/*
THis class is reduced for testing. Just uncomment elements
*/


#include "FlipperObject.hpp"
//#include "Button.hpp"
//#include "Dispatcher.hpp"
#include "SoundPlayer.hpp"
#include "FlowObserver.hpp"
#include <vector>

using namespace std;

class GameController
{

private:
    vector<FlipperObject*> flipperObjects;
  //  vector<Button> buttons {  };
 //   Dispatcher* dispatcher {  };
    SoundPlayer* soundPlayer {  };

public:
    FlowObserver* observer;

public:
    virtual vector<FlipperObject*> getFlipperObjects();
    virtual void doStep();
    //virtual vector<Button> getButtons();
    //virtual void setDispatcher(Dispatcher* dispatcher);
    virtual void setSoundPlayer(SoundPlayer* soundPlayer);

    // Generated
    GameController();
}
;
