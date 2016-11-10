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

#define NUMPIXELS 100

#define DATAPIN    11 //from 4
#define CLOCKPIN   13 //from 5
Adafruit_DotStar strip = Adafruit_DotStar(
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
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP

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

      if (counter % 6 == 0 && counter < max_generating_cycles) {
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




    //strip.show(); // Refresh strip

    delay(mainDelay);
    counter++;
  }

}

