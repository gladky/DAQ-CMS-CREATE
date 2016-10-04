/**
 * Project Untitled
 */


#include "Model.h"
#include "Link.h"


/**
 * Model implementation
 */

Model::Model()
{
     top1 = new Link(10,1,0,leds);
     top2 = new Link(10,1,10,leds);
     top3 = new Link(10,1,20,leds);
     top4 = new Link(10,1,30,leds);

}
