// Generated from /cms.flipper/src/main/java/FlipperObjectFactory.java
#include "FlipperObjectFactory.hpp"


/*
This class is reduced, uncomment to introduce new elements
*/

//#include <BUFU.hpp>
#include "Buffer.hpp"
#include "Button.hpp"
#include "Dispatcher.hpp"
#include "FlipperObject.hpp"
#include "GameController.hpp"
#include "Link.hpp"
#include "SoundPlayer.hpp"
#include "Storage.hpp"
//#include <Switch.hpp>



FlipperObjectFactory::FlipperObjectFactory() 
{

    Serial.println("FlipperObjectFactory: initializing controller");
    controller = new GameController();
    bufferProcessingStep = DEFAULT_BUFFER_PROCESSING_STEP;
    bufferTimeoutStep = DEFAULT_BUFFER_TIMEOUT_STEP;
    bufuProcessingStep = DEFAULT_BUFU_PROCESSING_STEP;
    bufuTimeoutStep = DEFAULT_BUFU_TIMEOUT_STEP;

    Serial.println("FlipperObjectFactory: initializing sound player");
    soundPlayer = new SoundPlayer("SP");
    controller->setSoundPlayer(soundPlayer);
}

int FlipperObjectFactory::DEFAULT_BUFFER_PROCESSING_STEP = 8;

int FlipperObjectFactory::DEFAULT_BUFFER_TIMEOUT_STEP=25;

int FlipperObjectFactory::DEFAULT_BUFU_PROCESSING_STEP=10;

int FlipperObjectFactory::DEFAULT_BUFU_TIMEOUT_STEP=25;


Link* FlipperObjectFactory::createLink(string name, int logicalLength)
{
    int calculatedStep = 100 / logicalLength;
    if(calculatedStep < 1) {
        calculatedStep = 1;
    } else if(calculatedStep > 50) {
        calculatedStep = 50;
    }
    string uniqueName = getShortName(name);
    Link* link = new Link(uniqueName, 1, calculatedStep, soundPlayer);
    controller->getFlipperObjects().push_back(link);
    return link;
}

/*
FlipperObject* FlipperObjectFactory::createBUFU(string name, Button* button)
{
    string uniqueName = getShortName(name);
    FlipperObject* bufu = new BUFU(uniqueName, bufuProcessingStep, bufuTimeoutStep, button, soundPlayer);
    controller->getFlipperObjects()->add(bufu);
    return bufu;
}

FlipperObject* FlipperObjectFactory::createSwitch(string name)
{
    string uniqueName = getShortName(name);
    FlipperObject* switch_ = new Switch(uniqueName, soundPlayer);
    controller->getFlipperObjects()->add(switch_);
    return switch_;
}
*/

FlipperObject* FlipperObjectFactory::createStorage()
{
    string uniqueName = getShortName("Storage");
    FlipperObject* storage = new Storage(uniqueName, 40, soundPlayer);
    controller->getFlipperObjects().push_back(storage);
    return storage;
}



Buffer* FlipperObjectFactory::createBuffer(string name, Button* button, bool soundMasked)
{
    string uniqueName = getShortName(name);
    Buffer* buffer = new Buffer(uniqueName, 12, bufferProcessingStep, bufferTimeoutStep, button, soundPlayer, soundMasked);
    controller->getFlipperObjects().push_back(buffer);
    return buffer;
}

Dispatcher* FlipperObjectFactory::createDispatcher(vector<FlipperObject*> bufus, vector<FlipperObject*> links)
{
    Dispatcher* dispatcher = new Dispatcher(bufus, links, soundPlayer);
    controller->setDispatcher(dispatcher);
    return dispatcher;
}

Button* FlipperObjectFactory::createButton(string name)
{
    string uniqueName = getShortName(name);
    Button* button = new Button(uniqueName, soundPlayer);
    controller->getButtons().push_back(button);
    return button;
}


string FlipperObjectFactory::getShortName(string name)
{
    return name;
}

GameController* FlipperObjectFactory::getController()
{
    Serial.println("FlipperObjectFactory: Getting controller");
    return controller;
}

void FlipperObjectFactory::setBufferProcessingStep(int bufferProcessingStep_)
{
    bufferProcessingStep = bufferProcessingStep_;
}

void FlipperObjectFactory::setBufferTimeoutStep(int bufferTimeoutStep_)
{
    bufferTimeoutStep = bufferTimeoutStep_;
}

void FlipperObjectFactory::setBufuProcessingStep(int bufuProcessingStep_)
{
    bufuProcessingStep = bufuProcessingStep_;
}

void FlipperObjectFactory::setBufuTimeoutStep(int bufuTimeoutStep_)
{
    bufuTimeoutStep = bufuTimeoutStep_;
}



SoundPlayer* FlipperObjectFactory::getSoundPlayer()
{
    return soundPlayer;
}


