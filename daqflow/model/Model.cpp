/**
 * Project Untitled
 */


#include "Model.h"
#include "Link.h"
#include <vector>


/**
 * Model implementation
 */

Model::Model(std::vector<uint32_t> &leds)
{
    //leds = leds;

    Serial.println("Initializing model");

    top1 = new Link(10,1,0,leds);
    top2 = new Link(10,1,10,leds);
    top3 = new Link(10,1,20,leds);
    top4 = new Link(10,1,30,leds);

}

void Model::animate(){

    //Serial.println("Animation step");

    top1->animate();

}
