#include <Adafruit_DotStar.h>
#include <SPI.h>

#include "model/AnimatedObject.cpp"
#include "model/AnimatedObject.h"

#include "model/Link.cpp"
#include "model/Link.h"

#include "model/Model.cpp"
#include "model/Model.h"
#include <vector>

#define NUMPIXELS 10

#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

                           
std::vector<uint32_t> result_leds(NUMPIXELS,0);
Model *model;

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  
  Serial.begin(9600);
  delay(4000);

  model = new Model(result_leds);
  Serial.println(model->top1->length);

  
  printModel();

  //model->start();
}

void printModel(){

  Serial.println("####### CURRENT MODEL ########");
  for(int i = 0; i<result_leds.size(); i++){
    
      strip.setPixelColor(i,result_leds[i]); // 'On' pixel at head
      Serial.print(result_leds[i]);
      Serial.print(",");
  }
  Serial.println("");
  Serial.println("############");
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)


void loop() {


  model->animate();

  printModel();

  //strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(2000);                        // Pause 20 milliseconds (~50 FPS)

  if (++head >= NUMPIXELS) {        // Increment head index.  Off end of strip?
    head = 0;                       //  Yes, reset head index to start
    if ((color >>= 8) == 0)         //  Next color (R->G->B) ... past blue now?
      color = 0xFF0000;             //   Yes, reset to red
  }
  if (++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
}
