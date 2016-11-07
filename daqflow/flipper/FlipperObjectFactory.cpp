// Generated from /cms.flipper/src/main/java/FlipperObjectFactory.java
#include <FlipperObjectFactory.hpp>

#include <BUFU.hpp>
#include <Buffer.hpp>
#include <Button.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
#include <GameController.hpp>
#include <Link.hpp>
#include <SoundPlayer.hpp>
#include <Storage.hpp>
#include <Switch.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/List.hpp>
#include <java/util/Set.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

FlipperObjectFactory::FlipperObjectFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

FlipperObjectFactory::FlipperObjectFactory() 
    : FlipperObjectFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t FlipperObjectFactory::DEFAULT_BUFFER_PROCESSING_STEP;

constexpr int32_t FlipperObjectFactory::DEFAULT_BUFFER_TIMEOUT_STEP;

constexpr int32_t FlipperObjectFactory::DEFAULT_BUFU_PROCESSING_STEP;

constexpr int32_t FlipperObjectFactory::DEFAULT_BUFU_TIMEOUT_STEP;

void FlipperObjectFactory::ctor()
{
    super::ctor();
    this->controller = new GameController();
    bufferProcessingStep = DEFAULT_BUFFER_PROCESSING_STEP;
    bufferTimeoutStep = DEFAULT_BUFFER_TIMEOUT_STEP;
    bufuProcessingStep = DEFAULT_BUFU_PROCESSING_STEP;
    bufuTimeoutStep = DEFAULT_BUFU_TIMEOUT_STEP;
    soundPlayer = new SoundPlayer(u"SP"_j);
    npc(this->controller)->setSoundPlayer(soundPlayer);
}

FlipperObject* FlipperObjectFactory::createLink(::java::lang::String* name, int32_t logicalLength)
{
    auto calculatedStep = int32_t(100) / logicalLength;
    if(calculatedStep < 1) {
        calculatedStep = 1;
    } else if(calculatedStep > 50) {
        calculatedStep = 50;
    }
    auto uniqueName = getShortName(name);
    FlipperObject* link = new Link(uniqueName, int32_t(1), calculatedStep, soundPlayer);
    npc(npc(controller)->getFlipperObjects())->add(static_cast< ::java::lang::Object* >(link));
    return link;
}

FlipperObject* FlipperObjectFactory::createBUFU(::java::lang::String* name, Button* button)
{
    auto uniqueName = getShortName(name);
    FlipperObject* bufu = new BUFU(uniqueName, bufuProcessingStep, bufuTimeoutStep, button, soundPlayer);
    npc(npc(controller)->getFlipperObjects())->add(static_cast< ::java::lang::Object* >(bufu));
    return bufu;
}

FlipperObject* FlipperObjectFactory::createSwitch(::java::lang::String* name)
{
    auto uniqueName = getShortName(name);
    FlipperObject* switch_ = new Switch(uniqueName, soundPlayer);
    npc(npc(controller)->getFlipperObjects())->add(static_cast< ::java::lang::Object* >(switch_));
    return switch_;
}

java::lang::String* FlipperObjectFactory::getShortName(::java::lang::String* name)
{
    return name;
}

FlipperObject* FlipperObjectFactory::createStorage()
{
    auto uniqueName = getShortName(u"Storage"_j);
    FlipperObject* storage = new Storage(uniqueName, int32_t(40), soundPlayer);
    npc(npc(controller)->getFlipperObjects())->add(static_cast< ::java::lang::Object* >(storage));
    return storage;
}

Buffer* FlipperObjectFactory::createBuffer(::java::lang::String* name, Button* button, bool soundMasked)
{
    auto uniqueName = getShortName(name);
    auto buffer = new Buffer(uniqueName, int32_t(12), bufferProcessingStep, bufferTimeoutStep, button, soundPlayer, soundMasked);
    npc(npc(controller)->getFlipperObjects())->add(static_cast< ::java::lang::Object* >(buffer));
    return buffer;
}

Dispatcher* FlipperObjectFactory::createDispatcher(::java::util::List* bufus, ::java::util::List* links)
{
    auto dispatcher = new Dispatcher(bufus, links, soundPlayer);
    npc(controller)->setDispatcher(dispatcher);
    return dispatcher;
}

Button* FlipperObjectFactory::createButton(::java::lang::String* name)
{
    auto uniqueName = getShortName(name);
    auto button = new Button(uniqueName, soundPlayer);
    npc(npc(controller)->getButtons())->add(static_cast< ::java::lang::Object* >(button));
    return button;
}

GameController* FlipperObjectFactory::getController()
{
    return controller;
}

void FlipperObjectFactory::setBufferProcessingStep(int32_t bufferProcessingStep)
{
    this->bufferProcessingStep = bufferProcessingStep;
}

void FlipperObjectFactory::setBufferTimeoutStep(int32_t bufferTimeoutStep)
{
    this->bufferTimeoutStep = bufferTimeoutStep;
}

void FlipperObjectFactory::setBufuProcessingStep(int32_t bufuProcessingStep)
{
    this->bufuProcessingStep = bufuProcessingStep;
}

void FlipperObjectFactory::setBufuTimeoutStep(int32_t bufuTimeoutStep)
{
    this->bufuTimeoutStep = bufuTimeoutStep;
}

SoundPlayer* FlipperObjectFactory::getSoundPlayer()
{
    return soundPlayer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* FlipperObjectFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"FlipperObjectFactory", 20);
    return c;
}

java::lang::Class* FlipperObjectFactory::getClass0()
{
    return class_();
}

