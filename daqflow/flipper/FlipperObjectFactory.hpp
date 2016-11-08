// Generated from /cms.flipper/src/main/java/FlipperObjectFactory.java

#pragma once


struct default_init_tag;

class FlipperObjectFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    GameController* controller {  };
    static constexpr int32_t DEFAULT_BUFFER_PROCESSING_STEP { int32_t(8) };
    static constexpr int32_t DEFAULT_BUFFER_TIMEOUT_STEP { int32_t(25) };
    static constexpr int32_t DEFAULT_BUFU_PROCESSING_STEP { int32_t(10) };
    static constexpr int32_t DEFAULT_BUFU_TIMEOUT_STEP { int32_t(25) };
    int32_t bufferProcessingStep {  };
    int32_t bufferTimeoutStep {  };
    int32_t bufuProcessingStep {  };
    int32_t bufuTimeoutStep {  };
    SoundPlayer* soundPlayer {  };
protected:
    void ctor();

public:
    virtual FlipperObject* createLink(::java::lang::String* name, int32_t logicalLength);
    virtual FlipperObject* createBUFU(::java::lang::String* name, Button* button);
    virtual FlipperObject* createSwitch(::java::lang::String* name);

private:
    ::java::lang::String* getShortName(::java::lang::String* name);

public:
    virtual FlipperObject* createStorage();
    virtual Buffer* createBuffer(::java::lang::String* name, Button* button, bool soundMasked);
    virtual Dispatcher* createDispatcher(::java::util::List* bufus, ::java::util::List* links);
    virtual Button* createButton(::java::lang::String* name);
    virtual GameController* getController();
    virtual void setBufferProcessingStep(int32_t bufferProcessingStep);
    virtual void setBufferTimeoutStep(int32_t bufferTimeoutStep);
    virtual void setBufuProcessingStep(int32_t bufuProcessingStep);
    virtual void setBufuTimeoutStep(int32_t bufuTimeoutStep);
    virtual SoundPlayer* getSoundPlayer();

    // Generated
    FlipperObjectFactory();
protected:
    FlipperObjectFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
