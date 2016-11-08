// Generated from /cms.flipper/src/main/java/ArduinoTest.java
#include <ArduinoTest.hpp>

#include <FlipperGame.hpp>
#include <FlipperObject.hpp>
#include <FlowObserver.hpp>
#include <GameController.hpp>
#include <SimpleFifoQueue.hpp>


void ArduinoTest::main(::java::lang::StringArray* args)
{
    FlipperGame flipperGame = new FlipperGame();
    for (int32_t i = 0; i < 250; i++) {
        if(i % 4 == 0 && i < 200) {
            flipperGame->generateNewFragments();
        }
        flipperGame->pressButtonLevel1();
        flipperGame->pressButtonHLT_L1();
        flipperGame->pressButtonHLT_L2();
        flipperGame->pressButtonHLT_L3();
        flipperGame->pressButtonHLT_R1();
        flipperGame->pressButtonHLT_R2();
        flipperGame->pressButtonHLT_R3();
        flipperGame->doStep();
    }
    cout << flipperGame->getController()->observer->toString() << endl;
    cout << "There should be x events in storage: " << flipperGame->getStorage()->getQueue()->size() << endl;
}

