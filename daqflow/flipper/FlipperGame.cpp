// Generated from /cms.flipper/src/main/java/FlipperGame.java
#include "FlipperGame.hpp"

//#include "Buffer.hpp"
//#include "Button.hpp"
#include "DataObserver.hpp"
//#include "Dispatcher.hpp"
#include "FlipperObject.hpp"
#include "FlipperObjectFactory.hpp"
#include "FragmentGenerator.hpp"
#include "GameController.hpp"
//#include "SoundPlayer.hpp"


int FlipperGame::linkBoost =4;



/*
THis class is reduced for testing. Just uncomment elements
*/

FlipperGame::FlipperGame(FlipperObjectFactory* factory_)
{
    factory = factory_;
    controller = factory_->getController();
/*
    buttonL1 = factory->createButton("Lv1 btn");
    buttonHLT_L1 = factory->createButton("L1 btn");
    buttonHLT_L2 = factory->createButton("L2 btn");
    buttonHLT_L3 = factory->createButton("L3 btn");
    buttonHLT_R1 = factory->createButton("R1 btn");
    buttonHLT_R2 = factory->createButton("R2 btn");
    buttonHLT_R3 = factory->createButton("R3 btn");
*/
    link11 = factory->createLink("11", 20 / linkBoost);
    link12 = factory->createLink("12", 20 / linkBoost);
    link13 = factory->createLink("13", 20 / linkBoost);
    link14 = factory->createLink("14", 20 / linkBoost);

/*
    buffer1 = factory->createBuffer("buf1", buttonL1, true);
    buffer2 = factory->createBuffer("buf2", buttonL1, true);
    buffer3 = factory->createBuffer("buf3", buttonL1, true);
    buffer4 = factory->createBuffer("buf4", buttonL1, false);
    link21 = factory->createLink("21", int32_t(20) / linkBoost);
    link22 = factory->createLink("22", int32_t(20) / linkBoost);
    link23 = factory->createLink("23", int32_t(20) / linkBoost);
    link24 = factory->createLink("24", int32_t(20) / linkBoost);
    switch_ = factory->createSwitch("switch");
    link31 = factory->createLink("31", int32_t(13) / linkBoost);
    link32 = factory->createLink("32", int32_t(17) / linkBoost);
    link33 = factory->createLink("33", int32_t(34) / linkBoost);
    link34 = factory->createLink("34", int32_t(13) / linkBoost);
    link35 = factory->createLink("35", int32_t(17) / linkBoost);
    link36 = factory->createLink("36", int32_t(34) / linkBoost);
    bufuR1 = factory->createBUFU("R1BF", buttonHLT_R1);
    bufuL1 = factory->createBUFU("L1BF", buttonHLT_L1);
    bufuR2 = factory->createBUFU("R2BF", buttonHLT_R2);
    bufuL2 = factory->createBUFU("L2BF", buttonHLT_L2);
    bufuR3 = factory->createBUFU("R3BF", buttonHLT_R3);
    bufuL3 = factory->createBUFU("L3BF", buttonHLT_L3);
    link41 = factory->createLink("41", int32_t(10) / linkBoost);
    link42 = factory->createLink("42", int32_t(4) / linkBoost);
    link43 = factory->createLink("43", int32_t(13) / linkBoost);
    link44 = factory->createLink("44", int32_t(25) / linkBoost);
    link45 = factory->createLink("45", int32_t(10) / linkBoost);
    link46 = factory->createLink("46", int32_t(4) / linkBoost);
    link47 = factory->createLink("47", int32_t(13) / linkBoost);
    link48 = factory->createLink("48", int32_t(25) / linkBoost);
    storage = factory->createStorage();

    vector<FlipperObject*> targetsList;
    targets.push_back(bufuL1);
    targets.push_back(bufuL2);
    targets.push_back(bufuL3);
    targets.push_back(bufuR1);
    targets.push_back(bufuR2);
    targets.push_back(bufuR3);

    vector<FlipperObject*> linksList;
    linksList.push_back(link31);
    linksList.push_back(link32);
    linksList.push_back(link33);
    linksList.push_back(link34);
    linksList.push_back(link35);
    linksList.push_back(link36);

    dispatcher = factory->createDispatcher(targetsList,linksList);
    buffer1->setDispatcher(dispatcher);
    buffer2->setDispatcher(dispatcher);
    buffer3->setDispatcher(dispatcher);
    buffer4->setDispatcher(dispatcher);
    link11->getSuccessors().push_back(buffer1);
    link12->getSuccessors().push_back(buffer2);
    link13->getSuccessors().push_back(buffer3);
    link14->getSuccessors().push_back(buffer4);
    buffer1->getSuccessors().push_back(link21);
    buffer2->getSuccessors().push_back(link22);
    buffer3->getSuccessors().push_back(link23);
    buffer4->getSuccessors().push_back(link24);
    link21->getSuccessors().push_back(switch_);
    link22->getSuccessors().push_back(switch_);
    link23->getSuccessors().push_back(switch_);
    link24->getSuccessors().push_back(switch_);
    switch_->getSuccessors().push_back(link31);
    switch_->getSuccessors().push_back(link32);
    switch_->getSuccessors().push_back(link33);
    switch_->getSuccessors().push_back(link34);
    switch_->getSuccessors().push_back(link35);
    switch_->getSuccessors().push_back(link36);
    link31->getSuccessors().push_back(bufuL1);
    link32->getSuccessors().push_back(bufuL2);
    link33->getSuccessors().push_back(bufuL3);
    link34->getSuccessors().push_back(bufuR1);
    link35->getSuccessors().push_back(bufuR2);
    link36->getSuccessors().push_back(bufuR3);
    bufuL1->getSuccessors().push_back(link41);
    link41->getSuccessors().push_back(link43);
    bufuL2->getSuccessors().push_back(link42);
    bufuL3->getSuccessors().push_back(link44);
    link42->getSuccessors().push_back(link43);
    link43->getSuccessors().push_back(link44);
    bufuR1->getSuccessors().push_back(link45);
    link45->getSuccessors().push_back(link47);
    bufuR2->getSuccessors().push_back(link46);
    bufuR3->getSuccessors().push_back(link48);
    link46->getSuccessors().push_back(link47);
    link47->getSuccessors().push_back(link48);
    link44->getSuccessors().push_back(storage);
    link48->getSuccessors().push_back(storage);*/
    controller->observer = new DataObserver(this);
    fragmentGenerator = new FragmentGenerator(link11, link12, link13, link14);
}

void FlipperGame::generateNewFragments()
{
    fragmentGenerator->generateAndInsertFragments();
}
/*
void FlipperGame::pressButtonLevel1()
{
    buttonL1->press();
}

void FlipperGame::pressButtonHLT_L1()
{
    buttonHLT_L1->press();
}

void FlipperGame::pressButtonHLT_L2()
{
    buttonHLT_L2->press();
}

void FlipperGame::pressButtonHLT_L3()
{
    buttonHLT_L3->press();
}

void FlipperGame::pressButtonHLT_R1()
{
    buttonHLT_R1->press();
}

void FlipperGame::pressButtonHLT_R2()
{
    buttonHLT_R2->press();
}

void FlipperGame::pressButtonHLT_R3()
{
    buttonHLT_R3->press();
}*/

GameController* FlipperGame::getController()
{
    return controller;
}

void FlipperGame::doStep()
{
    controller->doStep();
}

void FlipperGame::doSteps(int steps)
{
    for (int i = 0; i < steps; i++) {
        controller->doStep();
    }
}
/*
FlipperObject* FlipperGame::getStorage()
{
    return storage;
}

FlipperObject* FlipperGame::getSwitch()
{
    return switch_;
}

FlipperObject* FlipperGame::getBufuL1()
{
    return bufuL1;
}

FlipperObject* FlipperGame::getBufuL2()
{
    return bufuL2;
}

FlipperObject* FlipperGame::getBufuL3()
{
    return bufuL3;
}

FlipperObject* FlipperGame::getBufuR1()
{
    return bufuR1;
}

FlipperObject* FlipperGame::getBufuR2()
{
    return bufuR2;
}

FlipperObject* FlipperGame::getBufuR3()
{
    return bufuR3;
}

Buffer* FlipperGame::getBuffer1()
{
    return buffer1;
}

Buffer* FlipperGame::getBuffer2()
{
    return buffer2;
}

Buffer* FlipperGame::getBuffer3()
{
    return buffer3;
}

Buffer* FlipperGame::getBuffer4()
{
    return buffer4;
}

SoundPlayer* FlipperGame::getSoundPlayer()
{
    return factory->getSoundPlayer();
}*/


