#include <Adafruit_DotStar.h>
#include <SPI.h>

#include "flipper/FlipperGame.hpp"
#include "flipper/FlipperGame.cpp"


#include "flipper/FragmentGenerator.hpp"
#include "flipper/FragmentGenerator.cpp"

#include "flipper/Data.hpp"
#include "flipper/Data.cpp"

#include "flipper/Fragment.hpp"
#include "flipper/Fragment.cpp"


#include "flipper/FlowObserver.hpp"
#include "flipper/FlowObserver.cpp"

#include "flipper/DataObserver.hpp"
#include "flipper/DataObserver.cpp"

#include "flipper/NamedObject.hpp"
#include "flipper/NamedObject.cpp"

#include "flipper/FlipperObject.hpp"
#include "flipper/FlipperObject.cpp"

#include "flipper/IndividualPogressObject.hpp"
#include "flipper/IndividualPogressObject.cpp"


#include <vector>

#define NUMPIXELS 100

#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

                           
std::vector<uint32_t> result_leds(NUMPIXELS,0);


//Model *model;
FlipperGame *flipperGame;

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  
  Serial.begin(9600);
  delay(100);

  //model = new Model(result_leds);

  flipperGame = new FlipperGame();

  
  //printModel();

  //model->start();
}

int counter = 0;


void loop() {


  if(counter < 400){

    if(counter % 4 == 0 && counter < 200) {
        flipperGame->generateNewFragments();
    }
    /*flipperGame->pressButtonLevel1();
    flipperGame->pressButtonHLT_L1();
    flipperGame->pressButtonHLT_L2();
    flipperGame->pressButtonHLT_L3();
    flipperGame->pressButtonHLT_R1();
    flipperGame->pressButtonHLT_R2();
    flipperGame->pressButtonHLT_R3();*/
    flipperGame->doStep();
  } else{

    //cout << flipperGame->getController()->observer->toString() << endl;
    //cout << "There should be x events in storage: " << flipperGame->getStorage()->getQueue()->size() << endl;

  }


  //strip.show();                     // Refresh strip

 
  counter++;

}
