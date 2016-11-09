// Generated from /cms.flipper/src/main/java/GameController.java


/*
THis class is reduced for testing. Just uncomment elements
*/

#include "GameController.hpp"

//#include <Button.hpp>
//#include <Dispatcher.hpp>
#include "FlipperObject.hpp"
#include "FlowObserver.hpp"
#include "SoundPlayer.hpp"


GameController::GameController()
{
    flipperObjects; //vector should be initialized
//   buttons ; // the same
    observer;// = nullptr;
}

vector<FlipperObject*>& GameController::getFlipperObjects()
{
    return flipperObjects;
}

void GameController::doStep()
{
    
    Serial.print("GameController: doStep, objects to do step: ");
    Serial.println(flipperObjects.size());
    
    for (int i = flipperObjects.size()-1; i >=0; i-- ) {
        flipperObjects[i]->doStep();
    }
    if(observer != NULL) {
        observer->persist();
    }

 /*
    for (vector<Button>::iterator it = buttons.begin() ; it != buttons.end(); ++it){
        it->doStep();
    }
    dispatcher->invalidate();*/
    soundPlayer->flush();
}

/*
vector<Button> GameController::getButtons()
{
    return buttons;
}

void GameController::setDispatcher(Dispatcher* dispatcher)
{
    this->dispatcher = dispatcher;
}*/

void GameController::setSoundPlayer(SoundPlayer* soundPlayer_)
{
    soundPlayer = soundPlayer_;
}

