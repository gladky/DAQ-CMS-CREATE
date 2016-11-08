// Generated from /cms.flipper/src/main/java/FlipperGame.java
#include "FlipperGame.hpp"

#include "Buffer.hpp"
#include "Button.hpp"
#include "DataObserver.hpp"
#include "Dispatcher.hpp"
#include "FlipperObject.hpp"
#include "FlipperObjectFactory.hpp"
#include "FragmentGenerator.hpp"
#include "GameController.hpp"
#include "SoundPlayer.hpp"


constexpr int32_t FlipperGame::linkBoost;

void FlipperGame::ctor()
{
    ctor(new FlipperObjectFactory());
}

void FlipperGame::ctor(FlipperObjectFactory* factory)
{
    super::ctor();
    this->factory = factory;
    this->controller = factory->getController();
    buttonL1 = factory->createButton(u"Lv1 btn"_j);
    buttonHLT_L1 = factory->createButton(u"L1 btn"_j);
    buttonHLT_L2 = factory->createButton(u"L2 btn"_j);
    buttonHLT_L3 = factory->createButton(u"L3 btn"_j);
    buttonHLT_R1 = factory->createButton(u"R1 btn"_j);
    buttonHLT_R2 = factory->createButton(u"R2 btn"_j);
    buttonHLT_R3 = factory->createButton(u"R3 btn"_j);
    link11 = factory->createLink(u"11"_j, int32_t(20) / linkBoost);
    link12 = factory->createLink(u"12"_j, int32_t(20) / linkBoost);
    link13 = factory->createLink(u"13"_j, int32_t(20) / linkBoost);
    link14 = factory->createLink(u"14"_j, int32_t(20) / linkBoost);
    buffer1 = factory->createBuffer(u"buf1"_j, buttonL1, true);
    buffer2 = factory->createBuffer(u"buf2"_j, buttonL1, true);
    buffer3 = factory->createBuffer(u"buf3"_j, buttonL1, true);
    buffer4 = factory->createBuffer(u"buf4"_j, buttonL1, false);
    link21 = factory->createLink(u"21"_j, int32_t(20) / linkBoost);
    link22 = factory->createLink(u"22"_j, int32_t(20) / linkBoost);
    link23 = factory->createLink(u"23"_j, int32_t(20) / linkBoost);
    link24 = factory->createLink(u"24"_j, int32_t(20) / linkBoost);
    switch_ = factory->createSwitch(u"switch"_j);
    link31 = factory->createLink(u"31"_j, int32_t(13) / linkBoost);
    link32 = factory->createLink(u"32"_j, int32_t(17) / linkBoost);
    link33 = factory->createLink(u"33"_j, int32_t(34) / linkBoost);
    link34 = factory->createLink(u"34"_j, int32_t(13) / linkBoost);
    link35 = factory->createLink(u"35"_j, int32_t(17) / linkBoost);
    link36 = factory->createLink(u"36"_j, int32_t(34) / linkBoost);
    bufuR1 = factory->createBUFU(u"R1BF"_j, buttonHLT_R1);
    bufuL1 = factory->createBUFU(u"L1BF"_j, buttonHLT_L1);
    bufuR2 = factory->createBUFU(u"R2BF"_j, buttonHLT_R2);
    bufuL2 = factory->createBUFU(u"L2BF"_j, buttonHLT_L2);
    bufuR3 = factory->createBUFU(u"R3BF"_j, buttonHLT_R3);
    bufuL3 = factory->createBUFU(u"L3BF"_j, buttonHLT_L3);
    link41 = factory->createLink(u"41"_j, int32_t(10) / linkBoost);
    link42 = factory->createLink(u"42"_j, int32_t(4) / linkBoost);
    link43 = factory->createLink(u"43"_j, int32_t(13) / linkBoost);
    link44 = factory->createLink(u"44"_j, int32_t(25) / linkBoost);
    link45 = factory->createLink(u"45"_j, int32_t(10) / linkBoost);
    link46 = factory->createLink(u"46"_j, int32_t(4) / linkBoost);
    link47 = factory->createLink(u"47"_j, int32_t(13) / linkBoost);
    link48 = factory->createLink(u"48"_j, int32_t(25) / linkBoost);
    storage = factory->createStorage();
    dispatcher = factory->createDispatcher(::java::util::Arrays::asList(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(bufuL1), static_cast< ::java::lang::Object* >(bufuL2), static_cast< ::java::lang::Object* >(bufuL3), static_cast< ::java::lang::Object* >(bufuR1), static_cast< ::java::lang::Object* >(bufuR2), static_cast< ::java::lang::Object* >(bufuR3)})), ::java::util::Arrays::asList(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(link31), static_cast< ::java::lang::Object* >(link32), static_cast< ::java::lang::Object* >(link33), static_cast< ::java::lang::Object* >(link34), static_cast< ::java::lang::Object* >(link35), static_cast< ::java::lang::Object* >(link36)})));
    npc(buffer1)->setDispatcher(dispatcher);
    npc(buffer2)->setDispatcher(dispatcher);
    npc(buffer3)->setDispatcher(dispatcher);
    npc(buffer4)->setDispatcher(dispatcher);
    npc(npc(link11)->getSuccessors())->add(static_cast< ::java::lang::Object* >(buffer1));
    npc(npc(link12)->getSuccessors())->add(static_cast< ::java::lang::Object* >(buffer2));
    npc(npc(link13)->getSuccessors())->add(static_cast< ::java::lang::Object* >(buffer3));
    npc(npc(link14)->getSuccessors())->add(static_cast< ::java::lang::Object* >(buffer4));
    npc(npc(buffer1)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link21));
    npc(npc(buffer2)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link22));
    npc(npc(buffer3)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link23));
    npc(npc(buffer4)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link24));
    npc(npc(link21)->getSuccessors())->add(static_cast< ::java::lang::Object* >(switch_));
    npc(npc(link22)->getSuccessors())->add(static_cast< ::java::lang::Object* >(switch_));
    npc(npc(link23)->getSuccessors())->add(static_cast< ::java::lang::Object* >(switch_));
    npc(npc(link24)->getSuccessors())->add(static_cast< ::java::lang::Object* >(switch_));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link31));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link32));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link33));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link34));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link35));
    npc(npc(switch_)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link36));
    npc(npc(link31)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuL1));
    npc(npc(link32)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuL2));
    npc(npc(link33)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuL3));
    npc(npc(link34)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuR1));
    npc(npc(link35)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuR2));
    npc(npc(link36)->getSuccessors())->add(static_cast< ::java::lang::Object* >(bufuR3));
    npc(npc(bufuL1)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link41));
    npc(npc(link41)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link43));
    npc(npc(bufuL2)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link42));
    npc(npc(bufuL3)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link44));
    npc(npc(link42)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link43));
    npc(npc(link43)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link44));
    npc(npc(bufuR1)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link45));
    npc(npc(link45)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link47));
    npc(npc(bufuR2)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link46));
    npc(npc(bufuR3)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link48));
    npc(npc(link46)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link47));
    npc(npc(link47)->getSuccessors())->add(static_cast< ::java::lang::Object* >(link48));
    npc(npc(link44)->getSuccessors())->add(static_cast< ::java::lang::Object* >(storage));
    npc(npc(link48)->getSuccessors())->add(static_cast< ::java::lang::Object* >(storage));
    npc(controller)->observer = new DataObserver(this);
    fragmentGenerator = new FragmentGenerator(link11, link12, link13, link14);
}

void FlipperGame::generateNewFragments()
{
    fragmentGenerator->generateAndInsertFragments();
}

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
}

GameController* FlipperGame::getController()
{
    return controller;
}

void FlipperGame::doStep()
{
    controller->doStep();
}

void FlipperGame::doSteps(int32_t steps)
{
    for (auto i = int32_t(0); i < steps; i++) {
        controller->doStep();
    }
}

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
}


