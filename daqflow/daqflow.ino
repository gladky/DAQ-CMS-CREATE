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

#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

                           
std::vector<uint32_t> result_leds(NUMPIXELS,0);

int BUTTON_LEVEL_1 = 2;
bool buttonL1State = false;
bool buttonL1StatePrev = false;

//Model *model;
FlipperGame *flipperGame;

void setup() {

  //BUTTONS
  pinMode(BUTTON_LEVEL_1, INPUT_PULLUP);

  
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


void loop() {

  int stateNow = digitalRead( BUTTON_LEVEL_1 );
  buttonL1State = stateNow == 0 && buttonL1StatePrev == 1;
  buttonL1StatePrev=stateNow;



  if(counter < 590){
    delay(100);

    
    Serial.print("step-");
    Serial.print(counter);
    Serial.print("---------------------------------------");
    Serial.print("step-");
    Serial.print(counter);
    Serial.print(", L1: ");
    Serial.print(stateNow);
    Serial.print(":");
    Serial.print(buttonL1State);
    Serial.println("--");

    if(counter % 6 == 0 && counter < 7) {
        flipperGame->generateNewFragments();
    }

    if(buttonL1State){
      flipperGame->pressButtonLevel1();
    }
    flipperGame->pressButtonHLT_L1();
    flipperGame->pressButtonHLT_L2();
    flipperGame->pressButtonHLT_L3();
    flipperGame->pressButtonHLT_R1();
    flipperGame->pressButtonHLT_R2();
    flipperGame->pressButtonHLT_R3();
    flipperGame->doStep();
  } else{
    delay(5000);
    Serial.println("Finished test run");

    Serial.println(flipperGame->getController()->observer->toString().c_str());
    //cout << "There should be x events in storage: " << flipperGame->getStorage()->getQueue()->size() << endl;
    Serial.println();
    Serial.println("-----------------------");
    delay(50000);

  }


  //strip.show();                     // Refresh strip

 
  counter++;

}

