// Generated from /cms.flipper/src/main/java/FlowObserver.java

#pragma once


struct default_init_tag;

class FlowObserver
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t MIN_WIDTH {  };
    int32_t WIDTH {  };
    int32_t SWITCH_WIDTH {  };
    int32_t STORAGE_WIDTH {  };
    int32_t SOUND_WIDTH {  };
    int32_t BUFFER_WIDTH {  };
    static ::java::lang::String* empty_;
    ::java::util::List* observedObjects {  };
    ::java::util::List* states {  };
    ::java::util::Map* lengths {  };
protected:
    void ctor(FlipperGame* flipperGame, int32_t minWidth, int32_t width, int32_t switchWidth, int32_t storageWidth, int32_t soundWidth, int32_t bufferWidth);

public: /* protected */
    virtual ::java::lang::String* getState(Link* link) = 0;
    virtual ::java::lang::String* getState(BUFU* bufu) = 0;
    virtual ::java::lang::String* getState(Buffer* buffer) = 0;
    virtual ::java::lang::String* getState(Storage* storage) = 0;
    virtual ::java::lang::String* getState(Switch* switch_);

private:
    Pair* getState(FlipperObject* observedObject);
    Pair* getState(Button* observedButtonObject);

public:
    virtual void persist();
    ::java::lang::String* toString() override;

private:
    ::java::lang::String* toString(::java::util::Map* row);

public:
    static ::java::lang::String* fixedLengthString(::java::lang::String* string, int32_t length);

    // Generated
    FlowObserver(FlipperGame* flipperGame, int32_t minWidth, int32_t width, int32_t switchWidth, int32_t storageWidth, int32_t soundWidth, int32_t bufferWidth);
protected:
    FlowObserver(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* protected */
    static ::java::lang::String*& empty();

private:
    virtual ::java::lang::Class* getClass0();
};
