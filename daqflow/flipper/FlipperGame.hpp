// Generated from /cms.flipper/src/main/java/FlipperGame.java

#ifndef _FLIPPER_GAME_H
#define _FLIPPER_GAME_H

#include "GameController.hpp"
#include "FlipperObjectFactory.hpp"
#include "FragmentGenerator.hpp"


/*
THis class is reduced for testing. Just uncomment elements
*/

class FlipperGame
{


private:
    GameController* controller;
    FlipperObjectFactory* factory;

/*
public:
    Button* buttonL1 {  };
    Button* buttonHLT_L1 {  };
    Button* buttonHLT_L2 {  };
    Button* buttonHLT_L3 {  };
    Button* buttonHLT_R1 {  };
    Button* buttonHLT_R2 {  };
    Button* buttonHLT_R3 {  };
*/


private:
    FlipperObject* storage;



public:
    Link* link11;
    Link* link12;
    Link* link13;
    Link* link14;


/*
private:
    Buffer* buffer1 {  };
    Buffer* buffer2 {  };
    Buffer* buffer3 {  };
    Buffer* buffer4 {  };
*/

/*
public:
    FlipperObject* link21 {  };
    FlipperObject* link22 {  };
    FlipperObject* link23 {  };
    FlipperObject* link24 {  };
    FlipperObject* link31 {  };
    FlipperObject* link32 {  };
    FlipperObject* link33 {  };
    FlipperObject* link34 {  };
    FlipperObject* link35 {  };
    FlipperObject* link36 {  };

private:
    FlipperObject* bufuL1 {  };
    FlipperObject* bufuL2 {  };
    FlipperObject* bufuL3 {  };
    FlipperObject* bufuR1 {  };
    FlipperObject* bufuR2 {  };
    FlipperObject* bufuR3 {  };

public:
    FlipperObject* link41 {  };
    FlipperObject* link42 {  };
    FlipperObject* link43 {  };
    FlipperObject* link44 {  };
    FlipperObject* link45 {  };
    FlipperObject* link46 {  };
    FlipperObject* link47 {  };
    FlipperObject* link48 {  };

*/

private:
    //FlipperObject* switch_ {  };
    FragmentGenerator* fragmentGenerator;

public:
    static int linkBoost ;

/*
public:
    Dispatcher* dispatcher {  };
*/

public:
    virtual void generateNewFragments();
    //virtual void pressButtonLevel1();
    //virtual void pressButtonHLT_L1();
    //virtual void pressButtonHLT_L2();
    //virtual void pressButtonHLT_L3();
    //virtual void pressButtonHLT_R1();
    //virtual void pressButtonHLT_R2();
    //virtual void pressButtonHLT_R3();
    virtual GameController* getController();
    virtual void doStep();
    virtual void doSteps(int steps);
    virtual FlipperObject* getStorage();
    //virtual FlipperObject* getSwitch();
    //virtual FlipperObject* getBufuL1();
    //virtual FlipperObject* getBufuL2();
    //virtual FlipperObject* getBufuL3();
    //virtual FlipperObject* getBufuR1();
    //virtual FlipperObject* getBufuR2();
    //virtual FlipperObject* getBufuR3();
    //virtual Buffer* getBuffer1();
    //virtual Buffer* getBuffer2();
    //virtual Buffer* getBuffer3();
    //virtual Buffer* getBuffer4();
    virtual SoundPlayer* getSoundPlayer();

    // Generated
    FlipperGame();
    //FlipperGame(FlipperObjectFactory* factory);


};


#endif
