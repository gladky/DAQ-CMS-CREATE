// Generated from /cms.flipper/src/main/java/GameController.java
#include <GameController.hpp>

#include <Button.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
//#include <FlowObserver.hpp>
#include <SoundPlayer.hpp>


void GameController::GameController()
{
    flipperObjects; //vector should be initialized
    buttons ; // the same
//    observer = nullptr;
}

vector<FlipperObject> GameController::getFlipperObjects()
{
    return flipperObjects;
}

void GameController::doStep()
{
    
    for (vector<FlipperObject>::reverse_iterator i = flipperObjects.rbegin(); i != flipperObjects.rend(); ++i ) {
        i->doStep();
    }
    //if(observer != nullptr) {
    //    observer->persist();
    //}

    for (vector<Button>::iterator it = buttons.begin() ; it != buttons.end(); ++it){
        it->doStep();
    }
    dispatcher->invalidate();
    soundPlayer->flush();
}

vector<Button> GameController::getButtons()
{
    return buttons;
}

void GameController::setDispatcher(Dispatcher* dispatcher)
{
    this->dispatcher = dispatcher;
}

void GameController::setSoundPlayer(SoundPlayer* soundPlayer)
{
    this->soundPlayer = soundPlayer;
}

