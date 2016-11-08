// Generated from /cms.flipper/src/main/java/ArduinoTest.java
#include <ArduinoTest.hpp>

#include <FlipperGame.hpp>
#include <FlipperObject.hpp>
#include <FlowObserver.hpp>
#include <GameController.hpp>
#include <SimpleFifoQueue.hpp>


ArduinoTest::ArduinoTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

ArduinoTest::ArduinoTest()
    : ArduinoTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void ArduinoTest::main(::java::lang::StringArray* args)
{
    clinit();
    auto flipperGame = new FlipperGame();
    for (auto i = int32_t(0); i < 250; i++) {
        if(i % int32_t(4) == 0 && i < 200) {
            npc(flipperGame)->generateNewFragments();
        }
        npc(flipperGame)->pressButtonLevel1();
        npc(flipperGame)->pressButtonHLT_L1();
        npc(flipperGame)->pressButtonHLT_L2();
        npc(flipperGame)->pressButtonHLT_L3();
        npc(flipperGame)->pressButtonHLT_R1();
        npc(flipperGame)->pressButtonHLT_R2();
        npc(flipperGame)->pressButtonHLT_R3();
        npc(flipperGame)->doStep();
    }
    npc(::java::lang::System::out())->println(npc(npc(npc(flipperGame)->getController())->observer)->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"There should be x events in storage: "_j)->append(npc(npc(npc(flipperGame)->getStorage())->getQueue())->size())->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* ArduinoTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"ArduinoTest", 11);
    return c;
}

java::lang::Class* ArduinoTest::getClass0()
{
    return class_();
}

