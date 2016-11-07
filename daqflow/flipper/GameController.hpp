// Generated from /cms.flipper/src/main/java/GameController.java

#pragma once

#include <fwd-cms.flipper.hpp>
#include <java/util/fwd-cms.flipper.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class GameController
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::List* flipperObjects {  };
    ::java::util::Set* buttons {  };
    Dispatcher* dispatcher {  };
    SoundPlayer* soundPlayer {  };

public:
    FlowObserver* observer {  };
protected:
    void ctor();

public:
    virtual ::java::util::List* getFlipperObjects();
    virtual void doStep();
    virtual ::java::util::Set* getButtons();
    virtual void setDispatcher(Dispatcher* dispatcher);
    virtual void setSoundPlayer(SoundPlayer* soundPlayer);

    // Generated
    GameController();
protected:
    GameController(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
