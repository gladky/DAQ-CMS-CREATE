// Generated from /cms.flipper/src/main/java/FlipperGame.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class FlipperGame
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    GameController* controller {  };
    FlipperObjectFactory* factory {  };

public:
    Button* buttonL1 {  };
    Button* buttonHLT_L1 {  };
    Button* buttonHLT_L2 {  };
    Button* buttonHLT_L3 {  };
    Button* buttonHLT_R1 {  };
    Button* buttonHLT_R2 {  };
    Button* buttonHLT_R3 {  };

private:
    FlipperObject* storage {  };

public:
    FlipperObject* link11 {  };
    FlipperObject* link12 {  };
    FlipperObject* link13 {  };
    FlipperObject* link14 {  };

private:
    Buffer* buffer1 {  };
    Buffer* buffer2 {  };
    Buffer* buffer3 {  };
    Buffer* buffer4 {  };

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

private:
    FlipperObject* switch_ {  };
    FragmentGenerator* fragmentGenerator {  };

public:
    static constexpr int32_t linkBoost { int32_t(4) };

public: /* protected */
    Dispatcher* dispatcher {  };
protected:
    void ctor();
    void ctor(FlipperObjectFactory* factory);

public:
    virtual void generateNewFragments();
    virtual void pressButtonLevel1();
    virtual void pressButtonHLT_L1();
    virtual void pressButtonHLT_L2();
    virtual void pressButtonHLT_L3();
    virtual void pressButtonHLT_R1();
    virtual void pressButtonHLT_R2();
    virtual void pressButtonHLT_R3();
    virtual GameController* getController();
    virtual void doStep();
    virtual void doSteps(int32_t steps);
    virtual FlipperObject* getStorage();
    virtual FlipperObject* getSwitch();
    virtual FlipperObject* getBufuL1();
    virtual FlipperObject* getBufuL2();
    virtual FlipperObject* getBufuL3();
    virtual FlipperObject* getBufuR1();
    virtual FlipperObject* getBufuR2();
    virtual FlipperObject* getBufuR3();
    virtual Buffer* getBuffer1();
    virtual Buffer* getBuffer2();
    virtual Buffer* getBuffer3();
    virtual Buffer* getBuffer4();
    virtual SoundPlayer* getSoundPlayer();

    // Generated
    FlipperGame();
    FlipperGame(FlipperObjectFactory* factory);
protected:
    FlipperGame(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};