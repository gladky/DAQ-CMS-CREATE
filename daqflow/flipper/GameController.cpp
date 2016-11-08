// Generated from /cms.flipper/src/main/java/GameController.java
#include <GameController.hpp>

#include <Button.hpp>
#include <Dispatcher.hpp>
#include <FlipperObject.hpp>
#include <FlowObserver.hpp>
#include <SoundPlayer.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedHashSet.hpp>
#include <java/util/List.hpp>
#include <java/util/ListIterator.hpp>
#include <java/util/Set.hpp>

GameController::GameController() 
    : GameController(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void GameController::ctor()
{
    super::ctor();
    this->flipperObjects = new ::java::util::ArrayList();
    this->buttons = new ::java::util::LinkedHashSet();
    this->observer = nullptr;
}

java::util::List* GameController::getFlipperObjects()
{
    return flipperObjects;
}

void GameController::doStep()
{
    auto li = npc(flipperObjects)->listIterator(npc(flipperObjects)->size());
    while (npc(li)->hasPrevious()) {
        auto flipperObject = java_cast< FlipperObject* >(npc(li)->previous());
        npc(flipperObject)->doStep();
    }
    if(observer != nullptr) {
        npc(observer)->persist();
    }
    for (auto _i = npc(buttons)->iterator(); _i->hasNext(); ) {
        Button* button = java_cast< Button* >(_i->next());
        {
            npc(button)->doStep();
        }
    }
    npc(dispatcher)->invalidate();
    npc(soundPlayer)->flush();
}

java::util::Set* GameController::getButtons()
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

