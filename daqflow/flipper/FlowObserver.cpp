// Generated from /cms.flipper/src/main/java/FlowObserver.java


/*
This class is reduced, uncomment
*/

#include "FlowObserver.hpp"

//#include <BUFU.hpp>
//#include <Buffer.hpp>
//#include <Button.hpp>
#include "Data.hpp"
//#include "Dispatcher.hpp"
#include "FlipperGame.hpp"
#include "FlipperObject.hpp"
#include "Link.hpp"
#include "NamedObject.hpp"
#include "SimpleFifoQueue.hpp"
#include "Sound.hpp"
//#include <SoundPlayer.hpp>
#include "Storage.hpp"
//#include <Switch.hpp>

#include <typeinfo>
#include <string>
#include <iostream>


using namespace std;



FlowObserver::FlowObserver(FlipperGame* flipperGame, int minWidth, int width, int switchWidth, int storageWidth, int soundWidth, int bufferWidth) 
{
    MIN_WIDTH = minWidth;
    WIDTH = width;
    SWITCH_WIDTH = switchWidth;
    STORAGE_WIDTH = storageWidth;
    SOUND_WIDTH = soundWidth;
    BUFFER_WIDTH = bufferWidth;

    //states = //should be initialized automatically
    //observedObjects = // should be initialized automatically

    observedObjects.push_back(flipperGame->link11);
    observedObjects.push_back(flipperGame->link12);
    observedObjects.push_back(flipperGame->link13);
    observedObjects.push_back(flipperGame->link14);
    /*observedObjects.push_back(flipperGame->getBuffer1());
    observedObjects.push_back(flipperGame->getBuffer2());
    observedObjects.push_back(flipperGame->getBuffer3());
    observedObjects.push_back(flipperGame->getBuffer4());
    observedObjects.push_back(flipperGame->dispatcher);
    observedObjects.push_back(flipperGame->buttonL1);
    observedObjects.push_back(flipperGame->link21);
    observedObjects.push_back(flipperGame->link22);
    observedObjects.push_back(flipperGame->link23);
    observedObjects.push_back(flipperGame->link24);
    observedObjects.push_back(flipperGame->getSwitch());
    observedObjects.push_back(flipperGame->link31);
    observedObjects.push_back(flipperGame->link32);
    observedObjects.push_back(flipperGame->link33);
    observedObjects.push_back(flipperGame->link34);
    observedObjects.push_back(flipperGame->link35);
    observedObjects.push_back(flipperGame->link36);
    observedObjects.push_back(flipperGame->getBufuL1());
    observedObjects.push_back(flipperGame->buttonHLT_L1);
    observedObjects.push_back(flipperGame->getBufuL2());
    observedObjects.push_back(flipperGame->buttonHLT_L2);
    observedObjects.push_back(flipperGame->getBufuL3());
    observedObjects.push_back(flipperGame->buttonHLT_L3);
    observedObjects.push_back(flipperGame->getBufuR1());
    observedObjects.push_back(flipperGame->buttonHLT_R1);
    observedObjects.push_back(flipperGame->getBufuR2());
    observedObjects.push_back(flipperGame->buttonHLT_R2);
    observedObjects.push_back(flipperGame->getBufuR3());
    observedObjects.push_back(flipperGame->buttonHLT_R3);
    observedObjects.push_back(flipperGame->link41);
    observedObjects.push_back(flipperGame->link42);
    observedObjects.push_back(flipperGame->link43);
    observedObjects.push_back(flipperGame->link44);
    observedObjects.push_back(flipperGame->link45);
    observedObjects.push_back(flipperGame->link46);
    observedObjects.push_back(flipperGame->link47);
    observedObjects.push_back(flipperGame->link48);

*/
    observedObjects.push_back(flipperGame->getStorage());
    observedObjects.push_back(flipperGame->getSoundPlayer());

    //lengths = //should be initialized automatically
    for (int i = 0; i < observedObjects.size(); i++) {
        NamedObject* object = observedObjects[i];
            if(Storage* v = dynamic_cast<Storage*>(object)) {
           	Serial.println("Observed object is a Storage");
                lengths.push_back(STORAGE_WIDTH);
            }/* else if(dynamic_cast< Switch* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(SWITCH_WIDTH));
            } else */

	    else if(Link* v = dynamic_cast<Link*>(object)) {
           	Serial.println("Observed object is a Link");
                lengths.push_back( MIN_WIDTH); // was with the i
            }
            /*else if(dynamic_cast< Buffer* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(BUFFER_WIDTH));
            }*/
            /*else if(dynamic_cast< Button* >(object) != nullptr) {
                npc(lengths)->put(::java::lang::Integer::valueOf(i), ::java::lang::Integer::valueOf(MIN_WIDTH));
            } */
            else if(SoundPlayer* v = dynamic_cast< SoundPlayer* >(object)) {
           	Serial.println("Observed object is a SoundPlayer");
                lengths.push_back( SOUND_WIDTH); 
            } else {
                lengths.push_back(WIDTH);
            }
    }
}
/*

string FlowObserver::getState(Switch* switch_)
{
    if(switch_->getQueue()->queue->size() == 0) {
        return "";
    } else {

	string result = "";
	result.append(switch_->getQueue()->queue)->get(3)->getName());
	result.append("-");
	result.append(switch_->getQueue()->queue)->get(0)->getName());
        return result;
    }
}
*/

string FlowObserver::getState(FlipperObject* observedObject)
{
    string data;
    if(Link *linkObject = dynamic_cast<Link*>(observedObject)) {
        data = getState(linkObject);
    } else if(SoundPlayer* v = dynamic_cast< SoundPlayer* >(observedObject)) {
        FlipperObject* f = dynamic_cast< FlipperObject* >(observedObject);
        data = getState(f);
    }
    /*else if(dynamic_cast< Buffer* >(observedObject) != nullptr) {
        data = getState(java_cast< Buffer* >(observedObject));
    } else if(dynamic_cast< BUFU* >(observedObject) != nullptr) {
        data = getState(java_cast< BUFU* >(observedObject));
    }*/ 
    else if(Storage* storageObject = dynamic_cast< Storage* >(observedObject)) {
        data = getState(storageObject);
    } 
    /*else if(dynamic_cast< Switch* >(observedObject) != nullptr) {
        data = getState(java_cast< Switch* >(observedObject));
    } */else {
        data = "???";
    }
    return data;
}

/*
Pair* FlowObserver::getState(Button* observedButtonObject)
{
    auto name = npc(observedButtonObject)->getName();
    auto enabled = npc(observedButtonObject)->isEnabled() ? u"E"_j : u" "_j;
    auto pressed = npc(observedButtonObject)->isPressed() ? u"P"_j : u" "_j;
    return Pair::of(name, ::java::lang::StringBuilder().append(enabled)->append(pressed)->toString());
}*/

void FlowObserver::persist()
{
    vector<string> currentState;//= new ::java::util::LinkedHashMap();
    for (int i = 0; i< observedObjects.size(); i++ ) {
        NamedObject* observedObject = observedObjects[i];
        {
            string result;
            if( FlipperObject* observedFlipperObject = dynamic_cast<FlipperObject*>(observedObject)) {
                result = getState(observedFlipperObject);
            } 

            /*else if(dynamic_cast< Button* >(observedObject) != nullptr) {
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
            }*/

            else if(SoundPlayer* soundPlayer = dynamic_cast< SoundPlayer* >(observedObject)) {
                string data = "";
                for (int i = 0; i < soundPlayer->getSounds().size(); i++) {
                    if(i != 0) {
                        data.append(",");
                    }

		    int soundInt = soundPlayer->getSounds()[i];
                    data.append(toString(soundInt));
                }
                result = data;
            }  else {
                result = "?";
            }
            //currentState.push_back(result->getLeft(), result->getRight()); // it used to be a map, maybe now the pair not necessary
            currentState.push_back( result);
        }
    }
    states.push_back(currentState);
}

string FlowObserver::toString()
{
    string sb = "";
    string stepHeading = fixedLengthString("step", WIDTH);
    sb.append("|");
    sb.append(stepHeading);
    sb.append("|");
    int h = 0;

    for (int i = 0; i < observedObjects.size(); i++) {
        NamedObject* object = observedObjects[i];
        {
            string heading = fixedLengthString(object->getName(), lengths[h]);
            sb.append(heading);
            sb.append("|");
            h++;
        }
    }
    sb.append("\n");
    int stepNumber = 0;
    for (int i =0; i< states.size(); i++ ) {
        vector<string> state = states[i];
        {

		

            string step = fixedLengthString(toString(stepNumber), WIDTH);
            sb.append("|");
            sb.append(step);
            sb.append(toString(state));
            sb.append("\n");
            stepNumber++;
        }
    }
    return sb;
}

string FlowObserver::toString(vector<string> row)
{
    string sb = "";
    sb.append("|");
    int i = 0;

    /* DEBUGGING
    Serial.println("To string the row: ");
    for(int l = 0; l<row.size(); l++){
        Serial.print(row[l].c_str());
	Serial.print(", ");
    } EOD
    */

    for (int it = 0 ; it < row.size(); it++ ) {
        {
            string curr = fixedLengthString(row[it].c_str(), lengths[i]);
            sb.append(curr);
            sb.append("|");
            i++;
        }
    }
    return sb;
}

string FlowObserver::fixedLengthString(string text, int length)
{
    //Serial.print("Text before: ");
    //Serial.println(text.c_str());
    if(text.length() > length) {
        text = text.substr(0, length - 1);
        text.append("*");
    }
    else if(text.length() < length){
        int diff = length - text.length();
        for(int i = 0; i< diff; i++){
	     text.insert(0," ");
        }
    }
    //Serial.print("Text after: ");
    //Serial.println(text.c_str());
    return text;
}

string FlowObserver::toString(int i){
	sprintf(numstr, "%d", i);
	string numberString =  numstr;
	return numberString;
}

