// Generated from /cms.flipper/src/main/java/FlipperGame.java
#include <FlipperGame.hpp>

#include <Buffer.hpp>
#include <Button.hpp>
#include <DataObserver.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
#include <FlipperObjectFactory.hpp>
#include <FragmentGenerator.hpp>
#include <GameController.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/List.hpp>
#include <ObjectArray.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

FlipperGame::FlipperGame(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

FlipperGame::FlipperGame() 
    : FlipperGame(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

FlipperGame::FlipperGame(FlipperObjectFactory* factory) 
    : FlipperGame(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

constexpr int32_t FlipperGame::linkBoost;

void FlipperGame::ctor()
{
    ctor(new FlipperObjectFactory());
}

void FlipperGame::ctor(FlipperObjectFactory* factory)
{
    super::ctor();
    this->factory = factory;
    this->controller = npc(factory)->getController();
    buttonL1 = npc(factory)->createButton(u"Lv1 btn"_j);
    buttonHLT_L1 = npc(factory)->createButton(u"L1 btn"_j);
    buttonHLT_L2 = npc(factory)->createButton(u"L2 btn"_j);
    buttonHLT_L3 = npc(factory)->createButton(u"L3 btn"_j);
    buttonHLT_R1 = npc(factory)->createButton(u"R1 btn"_j);
    buttonHLT_R2 = npc(factory)->createButton(u"R2 btn"_j);
    buttonHLT_R3 = npc(factory)->createButton(u"R3 btn"_j);
    link11 = npc(factory)->createLink(u"11"_j, int32_t(20) / linkBoost);
    link12 = npc(factory)->createLink(u"12"_j, int32_t(20) / linkBoost);
    link13 = npc(factory)->createLink(u"13"_j, int32_t(20) / linkBoost);
    link14 = npc(factory)->createLink(u"14"_j, int32_t(20) / linkBoost);
    buffer1 = npc(factory)->createBuffer(u"buf1"_j, buttonL1, true);
    buffer2 = npc(factory)->createBuffer(u"buf2"_j, buttonL1, true);
    buffer3 = npc(factory)->createBuffer(u"buf3"_j, buttonL1, true);
    buffer4 = npc(factory)->createBuffer(u"buf4"_j, buttonL1, false);
    link21 = npc(factory)->createLink(u"21"_j, int32_t(20) / linkBoost);
    link22 = npc(factory)->createLink(u"22"_j, int32_t(20) / linkBoost);
    link23 = npc(factory)->createLink(u"23"_j, int32_t(20) / linkBoost);
    link24 = npc(factory)->createLink(u"24"_j, int32_t(20) / linkBoost);
    switch_ = npc(factory)->createSwitch(u"switch"_j);
    link31 = npc(factory)->createLink(u"31"_j, int32_t(13) / linkBoost);
    link32 = npc(factory)->createLink(u"32"_j, int32_t(17) / linkBoost);
    link33 = npc(factory)->createLink(u"33"_j, int32_t(34) / linkBoost);
    link34 = npc(factory)->createLink(u"34"_j, int32_t(13) / linkBoost);
    link35 = npc(factory)->createLink(u"35"_j, int32_t(17) / linkBoost);
    link36 = npc(factory)->createLink(u"36"_j, int32_t(34) / linkBoost);
    bufuR1 = npc(factory)->createBUFU(u"R1BF"_j, buttonHLT_R1);
    bufuL1 = npc(factory)->createBUFU(u"L1BF"_j, buttonHLT_L1);
    bufuR2 = npc(factory)->createBUFU(u"R2BF"_j, buttonHLT_R2);
    bufuL2 = npc(factory)->createBUFU(u"L2BF"_j, buttonHLT_L2);
    bufuR3 = npc(factory)->createBUFU(u"R3BF"_j, buttonHLT_R3);
    bufuL3 = npc(factory)->createBUFU(u"L3BF"_j, buttonHLT_L3);
    link41 = npc(factory)->createLink(u"41"_j, int32_t(10) / linkBoost);
    link42 = npc(factory)->createLink(u"42"_j, int32_t(4) / linkBoost);
    link43 = npc(factory)->createLink(u"43"_j, int32_t(13) / linkBoost);
    link44 = npc(factory)->createLink(u"44"_j, int32_t(25) / linkBoost);
    link45 = npc(factory)->createLink(u"45"_j, int32_t(10) / linkBoost);
    link46 = npc(factory)->createLink(u"46"_j, int32_t(4) / linkBoost);
    link47 = npc(factory)->createLink(u"47"_j, int32_t(13) / linkBoost);
    link48 = npc(factory)->createLink(u"48"_j, int32_t(25) / linkBoost);
    storage = npc(factory)->createStorage();
    dispatcher = npc(factory)->createDispatcher(::java::util::Arrays::asList(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(bufuL1), static_cast< ::java::lang::Object* >(bufuL2), static_cast< ::java::lang::Object* >(bufuL3), static_cast< ::java::lang::Object* >(bufuR1), static_cast< ::java::lang::Object* >(bufuR2), static_cast< ::java::lang::Object* >(bufuR3)})), ::java::util::Arrays::asList(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(link31), static_cast< ::java::lang::Object* >(link32), static_cast< ::java::lang::Object* >(link33), static_cast< ::java::lang::Object* >(link34), static_cast< ::java::lang::Object* >(link35), static_cast< ::java::lang::Object* >(link36)})));
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
    npc(fragmentGenerator)->generateAndInsertFragments();
}

void FlipperGame::pressButtonLevel1()
{
    npc(buttonL1)->press();
}

void FlipperGame::pressButtonHLT_L1()
{
    npc(buttonHLT_L1)->press();
}

void FlipperGame::pressButtonHLT_L2()
{
    npc(buttonHLT_L2)->press();
}

void FlipperGame::pressButtonHLT_L3()
{
    npc(buttonHLT_L3)->press();
}

void FlipperGame::pressButtonHLT_R1()
{
    npc(buttonHLT_R1)->press();
}

void FlipperGame::pressButtonHLT_R2()
{
    npc(buttonHLT_R2)->press();
}

void FlipperGame::pressButtonHLT_R3()
{
    npc(buttonHLT_R3)->press();
}

GameController* FlipperGame::getController()
{
    return controller;
}

void FlipperGame::doStep()
{
    npc(controller)->doStep();
}

void FlipperGame::doSteps(int32_t steps)
{
    for (auto i = int32_t(0); i < steps; i++) {
        npc(controller)->doStep();
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
    return npc(factory)->getSoundPlayer();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* FlipperGame::class_()
{
    static ::java::lang::Class* c = ::class_(u"FlipperGame", 11);
    return c;
}

java::lang::Class* FlipperGame::getClass0()
{
    return class_();
}

