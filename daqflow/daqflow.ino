#include <Adafruit_DotStar.h>
#include <SPI.h>

#include "flipper/FlipperGame.hpp"
#include "flipper/FlipperGame.cpp"

#include "flipper/GameController.hpp"
#include "flipper/GameController.cpp"

#include "flipper/Sound.hpp"
#include "flipper/SoundPlayer.hpp"
#include "flipper/SoundPlayer.cpp"


#include "flipper/FragmentGenerator.hpp"
#include "flipper/FragmentGenerator.cpp"

#include "flipper/Data.hpp"
#include "flipper/Data.cpp"

#include "flipper/Fragment.hpp"
#include "flipper/Fragment.cpp"

#include "flipper/Event.hpp"
#include "flipper/Event.cpp"


#include "flipper/FlowObserver.hpp"
#include "flipper/FlowObserver.cpp"

#include "flipper/DataObserver.hpp"
#include "flipper/DataObserver.cpp"

#include "flipper/NamedObject.hpp"
#include "flipper/NamedObject.cpp"

#include "flipper/FlipperObject.hpp"
#include "flipper/FlipperObject.cpp"

#include "flipper/FlipperObjectFactory.hpp"
#include "flipper/FlipperObjectFactory.cpp"

#include "flipper/IndividualPogressObject.hpp"
#include "flipper/IndividualPogressObject.cpp"

#include "flipper/SinglePogressObject.hpp"
#include "flipper/SinglePogressObject.cpp"

#include "flipper/Storage.hpp"
#include "flipper/Storage.cpp"

#include "flipper/Link.hpp"
#include "flipper/Link.cpp"

#include "flipper/Clickable.hpp"
#include "flipper/Clickable.cpp"

#include "flipper/Buffer.hpp"
#include "flipper/Buffer.cpp"

#include "flipper/BUFU.hpp"
#include "flipper/BUFU.cpp"

#include "flipper/Button.hpp"
#include "flipper/Button.cpp"

#include "flipper/Dispatcher.hpp"
#include "flipper/Dispatcher.cpp"

#include "flipper/Switch.hpp"
#include "flipper/Switch.cpp"


#include "flipper/SimpleFifoQueue.hpp"
#include "flipper/SimpleFifoQueue.cpp"




#include <vector>

#define NUMPIXELS 672

#define DATAPIN    11 //from 4
#define CLOCKPIN   13 //from 5
Adafruit_DotStar strip1 = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


std::vector<uint32_t> result_leds(NUMPIXELS, 0);

int BUTTON_START = 3;

int BUTTON_LEVEL_1 = 2;

int BUTTON_HLT_L1 = 4;
int BUTTON_HLT_L2 = 5;
int BUTTON_HLT_L3 = 6;

int BUTTON_HLT_R1 = 9;
int BUTTON_HLT_R2 = 8;
int BUTTON_HLT_R3 = 7;

bool buttonStartState = false;
bool buttonL1State = false;
bool buttonHltL1State = false;
bool buttonHltL2State = false;
bool buttonHltL3State = false;
bool buttonHltR1State = false;
bool buttonHltR2State = false;
bool buttonHltR3State = false;

bool buttonStartStatePrev = false;
bool buttonL1StatePrev = false;
bool buttonHltL1StatePrev = false;
bool buttonHltL2StatePrev = false;
bool buttonHltL3StatePrev = false;
bool buttonHltR1StatePrev = false;
bool buttonHltR2StatePrev = false;
bool buttonHltR3StatePrev = false;

//Model *model;
FlipperGame *flipperGame;



/* VISUALIZER */


//VISUALISATION PRE-STORED BITMAPS DEFINITIONS AND INSTANTIATION

/*Helper objects that hold pre-defined states that are applied onto some LED components. Not all components need this.
*/

//improve:remove repeating state definitions by introducing translation map
struct bufuStates {
  bool arr[29][8];
};

//bitmap of leds light-up, where ordering is linked to the overlay pixel map, not to the electrical line
//these pre-stored states include an input visualization, as well as 3 full processing circles
struct bufuStates getAllBufuStates() {
  struct bufuStates thing = {
    {
      {0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0},
      {1, 1, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 1, 1, 1},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 1, 1, 1},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 1, 1, 1},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 0, 0, 0, 0}
    }
  };

  return thing;
}


//VISUALISATION COMPONENT OBJECT DEFINITIONS

/*There is a struct for each LED component we would like to generate displays for.
    Each component offers a constructor, which also initializes fields (offset of first LED in strip, link length where applicable etc.)
  and a visualize(...) public method that sets the values of each individually addressible LED, according to the input (events and progress of events on the component).

    Note 1: The visualize(...) method of any component can technically set the value of any LED in the strip. But it should ONLY set values within the scope of the component, as defined by the offset of its first LED and its number of LEDS.
    Note 2: A call to the visualize(...) method of any component will flush the whole previous display and will generate a brand new visualization for the entire length of the component.
    Note 3: The visualize(...) methods only set LED values, but they do not actually call the strip.show() method. This is a controller's job.
*/

struct T_bufu {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip


  //constructor
  T_bufu(int in): inLed(in) {
    //Serial.print("Constructed T_bufu visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_bufu
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) { //add T_event events[], despite in bufu we only need one event, stored in index 0 of the passed arrays

    
    //input args
    int numEvents = progresses_vec.size();

    if(numEvents == 0){
      return;
    }
    int progresses[numEvents];
    Data* events[numEvents];

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      //Serial.print(progresses_vec[i]);
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];
    }
    //Serial.println();



    int pixelMap[] = {inLed + 5, inLed + 6, inLed + 7, inLed + 8, inLed + 3, inLed + 2, inLed + 1, inLed + 0}; //map with indices of the circular path on bufu
    int pixelInTheMiddle = inLed + 4;

    int progress = progresses[0];

    //if progress is equal or larger than 99, then the progress for an event has ended and an ACCEPT_TIME light up should occur, instead of the ordinary visualization
    if (progress >= 99) {
      uint32_t colorFinishProgress = 0x0000FF; //blue for good event

      //if not interesting event, retain red color and override blue for good event
      if (!events[0]->isInteresting()) {
        colorFinishProgress = 0x00FF00;
      }

      for (int i = 0; i < 8; i++) {
        //Serial.println(progress);
        int led = pixelMap[i];
        strip1.setPixelColor(led, colorFinishProgress);

      }
      strip1.setPixelColor(pixelInTheMiddle, colorFinishProgress);
      return;
    }

    int steps = 28;
    int state = (int) (progress * (steps + 1) / 100.0);
    if (state > 28) {
      state = 28;
    }

    struct bufuStates states = getAllBufuStates(); //hardcoded bufu states (an empty one plus 28 more)

    //iterate over the 8 circular leds state and light up accordingly (choses one state out of 29 from the struct, based on the progress, after mapping from 99 to 28)
    for (int i = 0; i < 8; i++) {
      uint32_t color = 0x000000; //no color by default
      if (states.arr[state][i]) {
        color = 0x00FF00; //change color to something, if this led has to be light up, this should be
      }
      int led = pixelMap[i];

      strip1.setPixelColor(led, color);
      //Serial.print(states.arr[state][i]);
    }
    strip1.setPixelColor(pixelInTheMiddle, 0x000000); //keep led in the middle off, during progress visualization

    //Serial.print(" : ");
    //Serial.println(state);
  }
};

struct T_tier0 {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip


  //constructor
  T_tier0(int in): inLed(in) {
    //Serial.print("Constructed T_tier0 visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_tier0
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) { //add T_event events[]


    //input args
    int numEvents = events_vec.size();
    int progresses[numEvents];
    Data* events[numEvents];

    if(numEvents == 0){
      return;
    }

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];
    }


    //progress is not relevant for tier0, it is only included for interface reasons...only numEvents is used and events list for parameterization

    //int progress = progresses[0]; //to fill tier0, it's enough to know one progress indicator which corresponds to the number of events in storage (but color should be defined by inspecting the event properties in aligned map also passed as arg)

    //prod version pixelmap

    int pixelMap[] = {    inLed + 7 , inLed + 8 , inLed + 23 , inLed + 24 , inLed + 39 ,
                          inLed + 6 , inLed + 9 , inLed + 22 , inLed + 25 , inLed + 38 ,
                          inLed + 5 , inLed + 10 , inLed + 21 , inLed + 26 , inLed + 37 ,
                          inLed + 4 , inLed + 11 , inLed + 20 , inLed + 27 , inLed + 36 ,
                          inLed + 3 , inLed + 12 , inLed + 19 , inLed + 28 , inLed + 35 ,
                          inLed + 2 , inLed + 13 , inLed + 18 , inLed + 29 , inLed + 34 ,
                          inLed + 1 , inLed + 14 , inLed + 17 , inLed + 30 , inLed + 33 ,
                          inLed + 0 , inLed + 15 , inLed + 16 , inLed + 31 , inLed + 32
                     }; //map with indices of the tier 0 filling scheme*/


    //int steps = 40;
    //int state = (int) (progress * (steps + 1) / 100.0);
    if (numEvents > 40) {
      numEvents = 40;
    }

    //by default 40 leds off
    bool arr [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //if numEvents is not zero, then light up some leds by updating bitmap
    if (numEvents) {
      for (int i = 0; i < 40; i++) {
        if (i < numEvents) {
          arr[i] = 1;
        } else {
          break;  //no need to update further than the maximum indicated by state var, since leds are off  by default
        }
      }
    }

    for (int i = 0; i < 40; i++) {
      uint32_t color = 0x000000; //no color by default
      if (arr[i]) {

        if (events[i]->isInteresting()) {
          color = 0x0000FF; //change color to something, if this led has to be light up (this should be indicated from the event interestingness rather than being hardcoded, check position i at events list)
        } else {
          color = 0x00FF00;
        }

      }
      int led = pixelMap[i];

      strip1.setPixelColor(led, color);
    }

    //Serial.print(" : ");
    //Serial.println(state);
  }

};


struct T_protonbottle {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip


  //constructor
  T_protonbottle(int in): inLed(in) {
    //Serial.print("Constructed T_protonbottle visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_protonbottle
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) {  //maybe also add T_event events[] for reasons of generality of the interface



    //input args
    int numEvents = progresses_vec.size();
    int progresses[numEvents];
    Data* events[numEvents];

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];
    }



    int progress = progresses[0];

    int pixelMap[] = {inLed + 32 , inLed + 33 , inLed + 34 , inLed + 35 , inLed + 36 , inLed + 37 , inLed + 38 , inLed + 39 ,
                      inLed + 31 , inLed + 30 , inLed + 29 , inLed + 28 , inLed + 27 , inLed + 26 , inLed + 25 , inLed + 24 ,
                      inLed + 16 , inLed + 17 , inLed + 18 , inLed + 19 , inLed + 20 , inLed + 21 , inLed + 22 , inLed + 23 ,
                      inLed + 15 , inLed + 14 , inLed + 13 , inLed + 12 , inLed + 11 , inLed + 10 , inLed + 9 , inLed + 8 ,
                      inLed + 0 , inLed + 1 , inLed + 2 , inLed + 3 , inLed + 4 , inLed + 5 , inLed + 6 , inLed + 7
                     };

    int steps = 40;
    int state = (int) (progress * (steps + 1) / 100.0);
    if (state > 40) {
      state = 40;
    }
    if (state < 0) {
      state = 0; //needed because this component's visualiser can also  be called from high to low progress, to illustrate an emptying proton bottle
    }

    //by default 40 leds off
    bool arr [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //if state is not zero, then light up some leds by updating bitmap
    if (state) {
      for (int i = 0; i < 40; i++) {
        if (i <= state) {
          arr[i] = 1;
        } else {
          break;  //no need to update further than the maximum indicated by state variable, since leds are off by default
        }
      }
    }

    for (int i = 0; i < 40; i++) {
      uint32_t color = 0x000000; //no color by default
      if (arr[i]) {

        color = 0xFFFF00; //change color to something, if this led has to be light up (this should be indicated from an external parameter maybe)

      }
      int led = pixelMap[i];

      strip1.setPixelColor(led, color);
    }

    //Serial.print(" : ");
    //Serial.println(state);
  }

};


struct T_link {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip
  int len; //length of link expressed in number of LEDs present
  bool isMasked; //should link reveal an interesting event by changing its colour? mask false if yes
  bool isLhc;

  //constructor
  T_link(int in, int l, bool mask, bool lhc): inLed(in), len(l), isMasked(mask), isLhc(lhc) {
    //Serial.print("Constructed T_link visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_link
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) { //add T_event events[]
    //vizLink

    //input args
    int numEvents = progresses_vec.size();
    int progresses[numEvents];
    Data* events[numEvents];

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];
    }

    //bitmap-style map, but containing actual color codes in the place of ones
    uint32_t enhancedBitmap[len];

    //by default switch off every LED in the link
    for (int k = 0; k < len; k++) {
      enhancedBitmap[k] = 0;
      // Serial.println(k);
    }

    //scan all events with their progress in argument array and update the enhanced bitmap

    //Serial.print("sizeof: ");
    //Serial.println(numEvents);

    for (int times = 0; times < numEvents; times++) {

      int progress = progresses[times];

      int state = (int) (progress * (len + 1) / 100.0);


      //Serial.print("progress: ");
      //Serial.println(progress);
      //Serial.print("state: ");
      //Serial.println(state);
      //Serial.print("led: ");
      //Serial.println(inLed + state - 1);


      uint32_t color = 0x00FF00; //red by default

      //color for links used at lhc
      if (isLhc) {
        color = 0xFFFF00;
      }


      //if fragment, visualizer should not be called with over 99 progress, as this will keep the highest LED on
      //if event, visualizer makes sense to be called with over 99 progress, as there is special provision for smooth exit visualization of a 4-LED event (details below)
      bool isFragment = events[times]->isFragment();


      //if event and interesting and link is after bufu (in first use case), light up blue, otherwise hide interestingess of carried event
      if ((!isFragment) && events[times]->isInteresting() && (!isMasked)) {
        color = 0x0000FF; //blue
      }


      /*
         This variable is used to control the event exiting visualization from the link. For a full and smooth exit visualization, five  calls with progress 100,101,102,103,104 must be done to this visualizer.
         If caller wants to preserve their own step, smooth  exit is not guaranteed, but also not desired either (e.g. if event jumps by two LEDs in normal visualization, it should also exit in steps of 2).
         In any case, for an exiting visualization (smooth or not) to occur, a number of calls with progress over 99 must be done. This number is relative to the step of caller (the highest step, the fewer calls are needed to exit) and is between 1 and 5.
      */
      int linkOverflow = 0;

      if (state > len) {
        linkOverflow = state - len;
        state = len;
      }

      //if state is not zero, then light up some leds
      if (state) {

        //notice: while state is one-indexed (meaning the very first visualization needs a progress of at least 1), the link LEDs are zero-indexed. Therefore, in a simplest case, progress 1 would light up LED 0 (local component index)

        //Should not call link visualizer for a fragment data with over 99 progress. Exit is instantaneous for 1-led visualisations (there is no special handling of exit viz) and calls with higher progresses will keep the last LED on
        if (isFragment) {
          //if fragment, light up one LED only, the head

          enhancedBitmap[state - 1] = color;
          //strip1.setPixelColor(inLed + state - 1, color);

        } else {
          //if event, light up head LED and three LEDs behind (without touching LEDs before the start of this component!)

          if (linkOverflow > 0) {
            //handle the exiting of an event (4-LED data instance needs special treatment, while fragment case is more trivial)

            /*
              overflow of link end: for an overflow larger than the maximum size of event in LEDs (the whole event has left the link), no visualization will be done
              these cases assume that an event consists of 4 LEDs and must be reduced or increases if this param changes (and so must the event input visualization right after below)
            */
            if (linkOverflow == 1) {
              //light up 4-1 = 3 last LEDs of this link component

              enhancedBitmap[state - 1] = color;
              enhancedBitmap[state - 1 - 1] = color;
              enhancedBitmap[state - 2 - 1] = color;
            } else if (linkOverflow == 2) {

              enhancedBitmap[state - 1] = color;
              enhancedBitmap[state - 1 - 1] = color;
            } else if (linkOverflow == 3) {

              enhancedBitmap[state - 1] = color;
            }

          } else {
            if (state == 1) {
              //event insert mode
              enhancedBitmap[state - 1] = color;  //only head is in component
            } else if (state == 2) {
              //event insert mode
              enhancedBitmap[state - 1] = color;
              enhancedBitmap[state - 1 - 1] = color;
            } else if (state == 3) {
              //event insert mode
              enhancedBitmap[state - 1] = color;
              enhancedBitmap[state - 1 - 1] = color;
              enhancedBitmap[state - 2 - 1] = color;
            } else {
              //all event in, normal mode
              enhancedBitmap[state - 1] = color;
              enhancedBitmap[state - 1 - 1] = color;
              enhancedBitmap[state - 2 - 1] = color;
              enhancedBitmap[state - 3 - 1] = color;
            }
          }
        }
      }

      //Serial.print(" : ");
      //Serial.println(state);

    }//for array of progresses

    //Serial.println("-----------------------------");
    //write out values to strip
    for (int k = 0; k < len; k++) {
      strip1.setPixelColor(inLed + k, enhancedBitmap[k]);

      //Serial.print(k);
      //Serial.print(": ");
      //Serial.println(enhancedBitmap[k]);
    }

  }

};


//buffer-only structures
struct T_buffer {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip

  //constructor
  T_buffer(int in): inLed(in) {
    //Serial.print("Constructed T_link visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_buffer
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) { //add T_event events[]


    //input args
    int numEvents = progresses_vec.size();
    int progresses[numEvents];
    Data* events[numEvents];

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];
    }


    uint32_t colorForInterestingIndicator = 0x0000FF; //lights up last LED if interesting, in master buffer (maybe should be constant field)

    //bitmap-style map, but containing actual color codes in the place of ones (contains two columns of buffer, as well as the interestingness indicator)
    uint32_t enhancedBitmap[15];

    //by default switch off every LED
    for (int k = 0; k < 15; k++) {
      enhancedBitmap[k] = 0;
      // Serial.println(k);
    }

    //scan all events with their progress in argument array and update the enhanced bitmap

    //Serial.print("sizeof: ");
    //Serial.println(numEvents);

    for (int times = 0; times < numEvents; times++) {

      int progress = progresses[times];

      int state = (int) (progress * (15 + 1) / 100.0);  //15 because progress has 15 physical steps in this component, while the second column only repeats visualization


      //Serial.println(times);
      //Serial.print("state: ");
      //Serial.println(state);


      uint32_t color = 0x00FF00; //should be inferred from event passed as arg?


      if (state > 15) {
        state = 15;
      }

      //if state is not zero, then light up some leds
      if (state) {

        //notice: while state is one-indexed (meaning the very first visualization needs a progress of at least 1), the link LEDs are zero-indexed. Therefore, in a simplest case, progress 1 would light up LED 0 (local component index)

        enhancedBitmap[state - 1] = color;    //left column

      }

      //Serial.print(" : ");
      //Serial.println(state);

    }//for array of progresses

    //write out values to strip
    for (int k = 0; k < 15; k++) {
      strip1.setPixelColor(inLed + k, enhancedBitmap[k]);

      //Serial.print(k);
      //Serial.print(": ");
      //Serial.println(enhancedBitmap[k]);
    }

  }

};

struct T_trigger {

  //object fields
  int inLed; //offset of first LED of this component in respect to the first LED of the strip
  bool isMaster; //if master trigger, then the last LED will light up in a color for interesting event

  //constructor
  T_trigger(int in, bool isMst): inLed(in), isMaster(isMst) {
    //Serial.print("Constructed T_link visualizer for component starting at offset ");
    //Serial.println(in);
  }

  //visualization method for T_buffer
  void visualize(vector<int> progresses_vec, vector<Data*> events_vec) {


    //input args
    int numEvents = progresses_vec.size();
    int progresses[numEvents];
    Data* events[numEvents];

    //fill arrays from vector
    for (int i = 0; i < numEvents; i++) {
      progresses[i] = progresses_vec[i];
      events[i] = events_vec[i];      //bool isInteresting = events[times].isInteresting; //should be inferred from event passed as arg
    }


    uint32_t colorForInterestingIndicator = 0x0000FF; //lights up last LED if interesting, in master buffer (maybe should be constant field)

    //bitmap-style map, but containing actual color codes in the place of ones (contains two columns of buffer, as well as the interestingness indicator)
    uint32_t enhancedBitmap[34];

    //by default switch off every LED
    for (int k = 0; k < 34; k++) {
      enhancedBitmap[k] = 0;
      // Serial.println(k);
    }

    //scan all events with their progress in argument array and update the enhanced bitmap

    //Serial.print("sizeof: ");
    //Serial.println(numEvents);

    for (int times = 0; times < numEvents; times++) {

      int progress = progresses[times];

      int state = (int) (progress * (15 + 1) / 100.0);  //15 because progress has 15 physical steps in this component, while the second column only repeats visualization


      //Serial.println(times);
      //Serial.print("state: ");
      //Serial.println(state);


      uint32_t color = 0x00FF00; //should be inferred from event passed as arg?

      bool isInteresting = events[times]->isInteresting(); //should be inferred from event passed as arg


      if (state > 15) {
        state = 15;
      }

      //if state is not zero, then light up some leds
      if (state) {

        //notice: while state is one-indexed (meaning the very first visualization needs a progress of at least 1), the link LEDs are zero-indexed. Therefore, in a simplest case, progress 1 would light up LED 0 (local component index)

        enhancedBitmap[state - 1] = color;    //left column
        enhancedBitmap[state - 1 + 17] = color; //right column counterpart LED

        //checks interestingness of the bottom-most event in buffer and sets extra LED accordingly
        if (isMaster && isInteresting && (state == 15)) {
          enhancedBitmap[16] = colorForInterestingIndicator;
          enhancedBitmap[33] = colorForInterestingIndicator;
        }
      }

      //enhancedBitmap[15] = 0;//use if needed
      //enhancedBitmap[32] = 0;//use if needed

      //Serial.print(" : ");
      //Serial.println(state);

    }//for array of progresses

    //write out values to strip
    for (int k = 0; k < 34; k++) {
      strip1.setPixelColor(inLed + k, enhancedBitmap[k]);

      //Serial.print(k);
      //Serial.print(": ");
      //Serial.println(enhancedBitmap[k]);
    }

  }

};


////////////////////VISUALIZER COMPONENT INSTANTIATION////////////////////////

//first level links (masked, notLHC)
T_link link11(0, 22, true, false);
T_link link12(161, 20, true, false);
T_link link13(323, 20, true, false);
T_link link14(417, 22, true, false);

//buffers and trigger-buffers (master triggers)
T_buffer buf1(22);
T_buffer buf2(181);

T_trigger buf3(343, true);
T_trigger buf4(439, true);

//second level links (masked, notLHC)
T_link link21(37, 16, true, false);
T_link link22(196, 11, true, false);
T_link link23(377, 10, true, false);
T_link link24(473, 15, true, false);

//third level links (masked, notLHC)
T_link link31(53, 11, true, false);
T_link link32(207, 17, true, false);
T_link link33(237, 34, true, false);
T_link link34(488, 11, true, false);
T_link link35(387, 17, true, false);
T_link link36(280, 34, true, false);

//bufus
T_bufu bufuL1(64);
T_bufu bufuL2(224);
T_bufu bufuL3(271);
T_bufu bufuR1(499);
T_bufu bufuR2(404);
T_bufu bufuR3(314);

//fourth level links (unmasked, notLHC)
T_link link41(73, 10, false, false);
T_link link43(83, 12, false, false);
T_link link44(95, 26, false, false);

T_link link45(508, 10, false, false);
T_link link47(518, 12, false, false);
T_link link48(530, 26, false, false);

T_link link42(233, 4, false, false);
T_link link46(413, 4, false, false);

//LHC links (masked, LHC)
T_link lhc1(582, 6, true, true);
T_link lhc2(576, 6, true, true);
T_link lhc3(606, 6, true, true);
T_link lhc4(600, 6, true, true);
T_link lhc5(594, 6, true, true);
T_link lhc6(588, 6, true, true);

T_link lhcL(612, 20, true, true);
T_link lhcR(556, 20, true, true);


//others
T_tier0 tierZero(121);
T_protonbottle protonBottle(632);


/* END OF VISU */


void setup() {

  //BUTTONS
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_LEVEL_1, INPUT_PULLUP);
  pinMode(BUTTON_HLT_L1, INPUT_PULLUP);
  pinMode(BUTTON_HLT_L2, INPUT_PULLUP);
  pinMode(BUTTON_HLT_L3, INPUT_PULLUP);
  pinMode(BUTTON_HLT_R1, INPUT_PULLUP);
  pinMode(BUTTON_HLT_R2, INPUT_PULLUP);
  pinMode(BUTTON_HLT_R3, INPUT_PULLUP);


#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif
  strip1.begin(); // Initialize pins for output
  strip1.show();  // Turn all LEDs off ASAP

  Serial.begin(9600);
  delay(2000);

  Serial.flush();

  Serial.println("Initializing model");
  //model = new Model(result_leds);

  flipperGame = new FlipperGame();


  //printModel();

  //model->start();

  Serial.println("Model initialized");
}

int counter = 0;
int max_cycles = 100;
int max_generating_cycles = 800;
int mainDelay = 20;

bool started = false;
bool finished = false;

void loop() {

  int stateNow;
  stateNow = digitalRead( BUTTON_START ); buttonStartState = stateNow == 0 && buttonStartStatePrev == 1; buttonStartStatePrev = stateNow;
  stateNow = digitalRead( BUTTON_LEVEL_1 ); buttonL1State = stateNow == 0 && buttonL1StatePrev == 1; buttonL1StatePrev = stateNow;

  stateNow = digitalRead( BUTTON_HLT_L1 ); buttonHltL1State = stateNow == 0 && buttonHltL1StatePrev == 1; buttonHltL1StatePrev = stateNow;
  stateNow = digitalRead( BUTTON_HLT_L2 ); buttonHltL2State = stateNow == 0 && buttonHltL2StatePrev == 1; buttonHltL2StatePrev = stateNow;
  stateNow = digitalRead( BUTTON_HLT_L3 ); buttonHltL3State = stateNow == 0 && buttonHltL3StatePrev == 1; buttonHltL3StatePrev = stateNow;

  stateNow = digitalRead( BUTTON_HLT_R1 ); buttonHltR1State = stateNow == 0 && buttonHltR1StatePrev == 1; buttonHltR1StatePrev = stateNow;
  stateNow = digitalRead( BUTTON_HLT_R2 ); buttonHltR2State = stateNow == 0 && buttonHltR2StatePrev == 1; buttonHltR2StatePrev = stateNow;
  stateNow = digitalRead( BUTTON_HLT_R3 ); buttonHltR3State = stateNow == 0 && buttonHltR3StatePrev == 1; buttonHltR3StatePrev = stateNow;

  if (started || buttonStartState) {

    if(started == false){
        Serial.println("Game started!");
        started = true;
        finished = false;
    }
    
    if (counter < max_cycles) {

      /*
        Serial.print("step-");
        Serial.print(counter);
        Serial.print("---------------------------------------");
        Serial.print("step-");
        Serial.print(counter);
        Serial.print(", L1: ");
        Serial.print(stateNow);
        Serial.print(":");
        Serial.print(buttonL1State);
        Serial.println("--");*/

      if (counter % 20 == 0 && counter < max_generating_cycles) {
        flipperGame->generateNewFragments();
      }

      if (buttonL1State) {
        flipperGame->pressButtonLevel1();
      }
      if (buttonHltL1State) {
        flipperGame->pressButtonHLT_L1();
      }
      if (buttonHltL2State) {
        flipperGame->pressButtonHLT_L2();
      }
      if (buttonHltL3State) {
        flipperGame->pressButtonHLT_L3();
      }
      if (buttonHltR1State) {
        flipperGame->pressButtonHLT_R1();
      }
      if (buttonHltR2State) {
        flipperGame->pressButtonHLT_R2();
      }
      if (buttonHltR3State) {
        flipperGame->pressButtonHLT_R3();
      }
      flipperGame->doStep();


      //Serial.println(flipperGame->link11->getProgress());
      //Serial.printnl(flipperGame->link11->getQueue()->queue);


      /* LINKS */
      link11.visualize(flipperGame->link11->getProgress(),flipperGame->link11->getQueue()->queue);
      link12.visualize(flipperGame->link12->getProgress(),flipperGame->link12->getQueue()->queue);
      link13.visualize(flipperGame->link13->getProgress(),flipperGame->link13->getQueue()->queue);
      link14.visualize(flipperGame->link14->getProgress(),flipperGame->link14->getQueue()->queue);

      
      link21.visualize(flipperGame->link21->getProgress(),flipperGame->link21->getQueue()->queue);
      link22.visualize(flipperGame->link22->getProgress(),flipperGame->link22->getQueue()->queue);
      link23.visualize(flipperGame->link23->getProgress(),flipperGame->link23->getQueue()->queue);
      link24.visualize(flipperGame->link24->getProgress(),flipperGame->link24->getQueue()->queue);

      
      link31.visualize(flipperGame->link31->getProgress(),flipperGame->link31->getQueue()->queue);
      link32.visualize(flipperGame->link32->getProgress(),flipperGame->link32->getQueue()->queue);
      link33.visualize(flipperGame->link33->getProgress(),flipperGame->link33->getQueue()->queue);
      link34.visualize(flipperGame->link34->getProgress(),flipperGame->link34->getQueue()->queue);
      link35.visualize(flipperGame->link35->getProgress(),flipperGame->link35->getQueue()->queue);
      link36.visualize(flipperGame->link36->getProgress(),flipperGame->link36->getQueue()->queue);

      
      
      link41.visualize(flipperGame->link41->getProgress(),flipperGame->link41->getQueue()->queue);
      link42.visualize(flipperGame->link42->getProgress(),flipperGame->link42->getQueue()->queue);
      link43.visualize(flipperGame->link43->getProgress(),flipperGame->link43->getQueue()->queue);
      link44.visualize(flipperGame->link44->getProgress(),flipperGame->link44->getQueue()->queue);
      link45.visualize(flipperGame->link45->getProgress(),flipperGame->link45->getQueue()->queue);
      link46.visualize(flipperGame->link46->getProgress(),flipperGame->link46->getQueue()->queue);
      link47.visualize(flipperGame->link47->getProgress(),flipperGame->link47->getQueue()->queue);
      link48.visualize(flipperGame->link48->getProgress(),flipperGame->link48->getQueue()->queue);

      /* BUFFERS */
      buf1.visualize(flipperGame->getBuffer1()->getProgress(),flipperGame->getBuffer1()->getQueue()->queue);
      buf2.visualize(flipperGame->getBuffer2()->getProgress(),flipperGame->getBuffer2()->getQueue()->queue);
      buf3.visualize(flipperGame->getBuffer3()->getProgress(),flipperGame->getBuffer3()->getQueue()->queue);
      buf4.visualize(flipperGame->getBuffer4()->getProgress(),flipperGame->getBuffer4()->getQueue()->queue);

      /* BUFUS */
      bufuL1.visualize(flipperGame->getBufuL1()->getProgress(),flipperGame->getBufuL1()->getQueue()->queue);
      bufuL2.visualize(flipperGame->getBufuL2()->getProgress(),flipperGame->getBufuL2()->getQueue()->queue);
      bufuL3.visualize(flipperGame->getBufuL3()->getProgress(),flipperGame->getBufuL3()->getQueue()->queue);

      bufuR1.visualize(flipperGame->getBufuR1()->getProgress(),flipperGame->getBufuR1()->getQueue()->queue);
      bufuR2.visualize(flipperGame->getBufuR2()->getProgress(),flipperGame->getBufuR2()->getQueue()->queue);
      bufuR3.visualize(flipperGame->getBufuR3()->getProgress(),flipperGame->getBufuR3()->getQueue()->queue);

      
      tierZero.visualize(flipperGame->getStorage()->getProgress(),flipperGame->getStorage()->getQueue()->queue);

    } else{
      
      Serial.println("Game finished!");
      for(int i = 0; i<20; i++){
          flipperGame->doStep();
          delay(mainDelay);
      }
      finished = true;
      started = false;
      counter = 0;
      //flipperGame->
    }

    Serial.print(flipperGame->getController()->observer->toString().c_str());




    strip1.show(); // Refresh strip

    delay(mainDelay);
    counter++;
  }

}

