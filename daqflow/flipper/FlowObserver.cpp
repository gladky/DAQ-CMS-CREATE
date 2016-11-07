// Generated from /cms.flipper/src/main/java/FlowObserver.java
#include <FlowObserver.hpp>

#include <BUFU.hpp>
#include <Buffer.hpp>
#include <Button.hpp>
#include <Data.hpp>
#include <Dispatcher.hpp>
#include <FlipperGame.hpp>
#include <FlipperObject.hpp>
#include <Link.hpp>
#include <NamedObject.hpp>
#include <Pair.hpp>
#include <SimpleFifoQueue.hpp>
#include <Sound.hpp>
#include <SoundPlayer.hpp>
#include <Storage.hpp>
#include <Switch.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedHashMap.hpp>
#include <java/util/List.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <ObjectArray.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

FlowObserver::FlowObserver(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

FlowObserver::FlowObserver(FlipperGame* flipperGame, int32_t minWidth, int32_t width, int32_t switchWidth, int32_t storageWidth, int32_t soundWidth, int32_t bufferWidth) 
    : FlowObserver(*static_cast< ::default_init_tag* >(0))
{
    ctor(flipperGame,minWidth,width,switchWidth,storageWidth,soundWidth,bufferWidth);
}

java::lang::String*& FlowObserver::empty()
{
    clinit();
    return empty_;
}
java::lang::String* FlowObserver::empty_;

void FlowObserver::ctor(FlipperGame* flipperGame, int32_t minWidth, int32_t width, int32_t switchWidth, int32_t storageWidth, int32_t soundWidth, int32_t bufferWidth)
{
    super::ctor();
    this->MIN_WIDTH = minWidth;
    this->WIDTH = width;
    this->SWITCH_WIDTH = switchWidth;
    this->STORAGE_WIDTH = storageWidth;
    this->SOUND_WIDTH = soundWidth;
    this->BUFFER_WIDTH = bufferWidth;
    this->states = new ::java::util::ArrayList();
    this->observedObjects = new ::java::util::ArrayList();
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link11));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link12));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link13));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link14));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBuffer1()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBuffer2()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBuffer3()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBuffer4()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->dispatcher));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonL1));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link21));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link22));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link23));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link24));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getSwitch()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link31));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link32));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link33));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link34));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link35));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link36));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuL1()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_L1));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuL2()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_L2));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuL3()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_L3));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuR1()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_R1));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuR2()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_R2));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getBufuR3()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->buttonHLT_R3));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link41));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link42));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link43));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link44));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link45));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link46));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link47));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->link48));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getStorage()));
    npc(observedObjects)->add(static_cast< ::java::lang::Object* >(npc(flipperGame)->getSoundPlayer()));
    lengths = new ::java::util::HashMap();
    for (auto i = int32_t(0); i < npc(observedObjects)->size(); i++) {
        ::java::lang::Object* object = java_cast< NamedObject* >(npc(observedObjects)->get(i));
        if(dynamic_cast< FlipperObject* >(object) != nullptr) {
            if(dynamic_cast< Storage* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(STORAGE_WIDTH));
            } else if(dynamic_cast< Switch* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(SWITCH_WIDTH));
            } else if(dynamic_cast< Link* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(MIN_WIDTH));
            } else if(dynamic_cast< Buffer* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(BUFFER_WIDTH));
            } else {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(WIDTH));
            }
        } else {
            if(dynamic_cast< Button* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(MIN_WIDTH));
            } else if(dynamic_cast< SoundPlayer* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(SOUND_WIDTH));
            } else {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(WIDTH));
            }
        }
    }
}

java::lang::String* FlowObserver::getState(Switch* switch_)
{
    if(npc(java_cast< ::java::util::List* >(npc(npc(switch_)->getQueue())->queue))->size() == 0) {
        return u""_j;
    } else {
        return ::java::lang::StringBuilder().append(npc(java_cast< Data* >(npc(java_cast< ::java::util::List* >(npc(npc(switch_)->getQueue())->queue))->get(3)))->getName())->append(u"-"_j)
            ->append(npc(java_cast< Data* >(npc(java_cast< ::java::util::List* >(npc(npc(switch_)->getQueue())->queue))->get(0)))->getName())->toString();
    }
}

Pair* FlowObserver::getState(FlipperObject* observedObject)
{
    ::java::lang::String* data;
    if(dynamic_cast< Link* >(observedObject) != nullptr) {
        data = getState(java_cast< Link* >(observedObject));
    } else if(dynamic_cast< Buffer* >(observedObject) != nullptr) {
        data = getState(java_cast< Buffer* >(observedObject));
    } else if(dynamic_cast< BUFU* >(observedObject) != nullptr) {
        data = getState(java_cast< BUFU* >(observedObject));
    } else if(dynamic_cast< Storage* >(observedObject) != nullptr) {
        data = getState(java_cast< Storage* >(observedObject));
    } else if(dynamic_cast< Switch* >(observedObject) != nullptr) {
        data = getState(java_cast< Switch* >(observedObject));
    } else {
        data = u"???"_j;
    }
    return Pair::of(npc(observedObject)->getName(), data);
}

Pair* FlowObserver::getState(Button* observedButtonObject)
{
    auto name = npc(observedButtonObject)->getName();
    auto enabled = npc(observedButtonObject)->isEnabled() ? u"E"_j : u" "_j;
    auto pressed = npc(observedButtonObject)->isPressed() ? u"P"_j : u" "_j;
    return Pair::of(name, ::java::lang::StringBuilder().append(enabled)->append(pressed)->toString());
}

void FlowObserver::persist()
{
    ::java::util::Map* currentState = new ::java::util::LinkedHashMap();
    for (auto _i = npc(observedObjects)->iterator(); _i->hasNext(); ) {
        NamedObject* observedObject = java_cast< NamedObject* >(_i->next());
        {
            Pair* result = nullptr;
            if(dynamic_cast< FlipperObject* >(observedObject) != nullptr) {
                auto observedFlipperObject = java_cast< FlipperObject* >(observedObject);
                result = getState(observedFlipperObject);
            } else if(dynamic_cast< Button* >(observedObject) != nullptr) {
                auto observedButtonObject = java_cast< Button* >(observedObject);
                result = getState(observedButtonObject);
            } else if(dynamic_cast< Dispatcher* >(observedObject) != nullptr) {
                auto dispatcher = java_cast< Dispatcher* >(observedObject);
                auto target = npc(dispatcher)->getResult();
                auto data = u""_j;
                if(target != -int32_t(1)) {
                    data = ::java::lang::StringBuilder(data).append(target)->toString();
                }
                if(npc(dispatcher)->isBackpressure()) {
                    data = ::java::lang::StringBuilder(data).append(u"BP"_j)->toString();
                }
                result = Pair::of(npc(dispatcher)->getName(), data);
            } else if(dynamic_cast< SoundPlayer* >(observedObject) != nullptr) {
                auto soundPlayer = java_cast< SoundPlayer* >(observedObject);
                auto data = u""_j;
                for (auto i = int32_t(0); i < npc(npc(soundPlayer)->getSounds())->size(); i++) {
                    if(i != 0) {
                        data = ::java::lang::StringBuilder(data).append(u","_j)->toString();
                    }
                    data = ::java::lang::StringBuilder(data).append(npc(Sound::getById((npc(java_cast< ::java::lang::Integer* >(npc(npc(soundPlayer)->getSounds())->get(i))))->intValue()))->getId())->toString();
                }
                result = Pair::of(npc(soundPlayer)->getName(), data);
            } else {
                result = Pair::of(u"X"_j, u"?"_j);
            }
            npc(currentState)->put(npc(result)->getLeft(), npc(result)->getRight());
        }
    }
    npc(states)->add(static_cast< ::java::lang::Object* >(currentState));
}

java::lang::String* FlowObserver::toString()
{
    auto sb = new ::java::lang::StringBuilder();
    auto stepHeading = fixedLengthString(u"step"_j, WIDTH);
    npc(sb)->append(u"|"_j);
    npc(sb)->append(stepHeading);
    npc(sb)->append(u"|"_j);
    auto h = int32_t(0);
    for (auto _i = npc(observedObjects)->iterator(); _i->hasNext(); ) {
        NamedObject* object = java_cast< NamedObject* >(_i->next());
        {
            auto heading = fixedLengthString(npc(object)->getName(), (npc(java_cast< ::java::lang::Integer* >(npc(lengths)->get(::java::lang::Integer::valueOf(h)))))->intValue());
            npc(sb)->append(heading);
            npc(sb)->append(u"|"_j);
            h++;
        }
    }
    npc(sb)->append(u"\n"_j);
    auto i = int32_t(0);
    for (auto _i = npc(states)->iterator(); _i->hasNext(); ) {
        ::java::util::Map* state = java_cast< ::java::util::Map* >(_i->next());
        {
            auto step = fixedLengthString(::java::lang::StringBuilder().append(i)->append(u""_j)->toString(), WIDTH);
            npc(sb)->append(u"|"_j);
            npc(sb)->append(step);
            npc(sb)->append(toString(state));
            npc(sb)->append(u"\n"_j);
            i++;
        }
    }
    return npc(sb)->toString();
}

java::lang::String* FlowObserver::toString(::java::util::Map* row)
{
    auto sb = new ::java::lang::StringBuilder();
    npc(sb)->append(u"|"_j);
    auto i = int32_t(0);
    for (auto _i = npc(npc(row)->entrySet())->iterator(); _i->hasNext(); ) {
        ::java::util::Map_Entry* entry = java_cast< ::java::util::Map_Entry* >(_i->next());
        {
            auto curr = fixedLengthString(java_cast< ::java::lang::String* >(npc(entry)->getValue()), (npc(java_cast< ::java::lang::Integer* >(npc(lengths)->get(::java::lang::Integer::valueOf(i)))))->intValue());
            npc(sb)->append(curr);
            npc(sb)->append(u"|"_j);
            i++;
        }
    }
    return npc(sb)->toString();
}

java::lang::String* FlowObserver::fixedLengthString(::java::lang::String* string, int32_t length)
{
    clinit();
    if(npc(string)->length() > length) {
        string = npc(string)->substring(0, length - int32_t(1));
        string = ::java::lang::StringBuilder(string).append(u"*"_j)->toString();
    }
    return ::java::lang::String::format(::java::lang::StringBuilder().append(u"%1$"_j)->append(length)
        ->append(u"s"_j)->toString(), new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(string)}));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* FlowObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"FlowObserver", 12);
    return c;
}

void FlowObserver::clinit()
{
struct string_init_ {
    string_init_() {
    empty_ = u""_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* FlowObserver::getClass0()
{
    return class_();
}

