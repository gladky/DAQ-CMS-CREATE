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

    //  length | step | offset | event size
    top1 = new Link(6,1,8, 1,leds);
    top2 = new Link(6,1,16,4, leds);
    top3 = new Link(6,1,24,1,leds);
    top4 = new Link(6,1,60,4,leds);



    top1->successor = top2;
    //top2->successor = top3;
    top3->successor = top4;


    Serial.println("Initialization finished");
    
 
}

void Model::animate(){

    //Serial.println("Animation step");

    top1->animate();
    top2->animate();
    top3->animate();
    top4->animate();

}

void Model::insert(Event *e1){
    top1->insert(e1);
    top3->insert(e1);
    Serial.println("Inserted");
}

