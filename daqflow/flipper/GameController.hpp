// Generated from /cms.flipper/src/main/java/GameController.java

#pragma once


#include "FlipperObject.hpp"
#include "Button.hpp"

class GameController
{

private:
    std::vector<FlipperObject> flipperObjects {  };
    std::vector<Button> buttons {  };
    Dispatcher* dispatcher {  };
    SoundPlayer* soundPlayer {  };

public:
    FlowObserver* observer {  };
protected:
    void ctor();

public:
    virtual std::vector<FlipperObject> getFlipperObjects();
    virtual void doStep();
    virtual std::vector<Button> getButtons();
    virtual void setDispatcher(Dispatcher* dispatcher);
    virtual void setSoundPlayer(SoundPlayer* soundPlayer);

    // Generated
    GameController();
}
;
