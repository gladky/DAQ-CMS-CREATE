// Generated from /cms.flipper/src/main/java/FlipperObjectFactory.java

#pragma once



class FlipperObjectFactory
{


private:
    GameController* controller ;
    static constexpr int32_t DEFAULT_BUFFER_PROCESSING_STEP { 8 };
    static constexpr int32_t DEFAULT_BUFFER_TIMEOUT_STEP { 25 };
    static constexpr int32_t DEFAULT_BUFU_PROCESSING_STEP {10 };
    static constexpr int32_t DEFAULT_BUFU_TIMEOUT_STEP { 25 };
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
