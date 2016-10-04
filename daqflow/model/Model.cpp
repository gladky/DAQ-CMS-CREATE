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

    //  length | step | offset
    top2 = new Link(8,1,8,leds);

    top1 = new Link(8,1,16,leds);
    top1->successor = top2;

    top3 = new Link(10,1,20,leds);
    top4 = new Link(10,1,30,leds);

    Event* e1 = new Event();

    Serial.println("Initialization finished");
    
    top1->insert(e1);
    //top2->insert(e1);


    Serial.println("Inserted");
}

void Model::animate(){

    //Serial.println("Animation step");

    top1->animate();
    top2->animate();

}

