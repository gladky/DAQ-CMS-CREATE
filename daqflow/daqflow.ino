#include <Adafruit_DotStar.h>
#include <SPI.h>

#include "flipper/FlipperGame.cpp"
#include <vector>

#define NUMPIXELS 100

#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
                           NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

                           
std::vector<uint32_t> result_leds(NUMPIXELS,0);


//Model *model;

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  
  Serial.begin(9600);
  delay(100);

  //model = new Model(result_leds);

  
  //printModel();

  //model->start();
}

int counter = 0;


void loop() {


  //model->animate();

  //printModel();

  //strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(50);                        // Pause 20 milliseconds (~50 FPS)

 
  if(counter%40 == 0){
    
    //Event* e1 = new Event();
    //model->insert(e1);
  }
  counter++;

}
