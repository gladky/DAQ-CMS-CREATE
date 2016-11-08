// Generated from /cms.flipper/src/main/java/FlipperObjectFactory.java

#pragma once

#include "Buffer.hpp"
#include "GameController.hpp"
#include "SoundPlayer.hpp"
#include "FlipperObject.hpp"


class FlipperObjectFactory
{


private:
    GameController* controller ;
    static int DEFAULT_BUFFER_PROCESSING_STEP ;
    static int DEFAULT_BUFFER_TIMEOUT_STEP ;
    static int DEFAULT_BUFU_PROCESSING_STEP;
    static int DEFAULT_BUFU_TIMEOUT_STEP;
    int bufferProcessingStep ;
    int bufferTimeoutStep ;
    int bufuProcessingStep;
    int bufuTimeoutStep;
    SoundPlayer* soundPlayer;

public:
    virtual FlipperObject* createLink(string name, int logicalLength);
    virtual FlipperObject* createBUFU(string name, Button* button);
    virtual FlipperObject* createSwitch(string name);

private:
    string getShortName(string name);

public:
    virtual FlipperObject* createStorage();
    virtual Buffer* createBuffer(string name, Button* button, bool soundMasked);
    virtual Dispatcher* createDispatcher(vector<FlipperObject> bufus, vector<FlipperObject> links);
    virtual Button* createButton(string name);
    virtual GameController* getController();
    virtual void setBufferProcessingStep(int bufferProcessingStep);
    virtual void setBufferTimeoutStep(int bufferTimeoutStep);
    virtual void setBufuProcessingStep(int bufuProcessingStep);
    virtual void setBufuTimeoutStep(int bufuTimeoutStep);
    virtual SoundPlayer* getSoundPlayer();

    // Generated
    FlipperObjectFactory();

};
