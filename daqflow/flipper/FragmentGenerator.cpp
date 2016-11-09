// Generated from /cms.flipper/src/main/java/FragmentGenerator.java


#include "FragmentGenerator.hpp"

#include "FlipperObject.hpp"
#include "Fragment.hpp"



FragmentGenerator::FragmentGenerator(Link* link1_, Link* link2_, Link* link3_, Link* link4_) 
{
    link1 = link1_;
    link2 = link2_;
    link3 = link3_;
    link4 = link4_;
    val = false;
}

void FragmentGenerator::generateAndInsertFragments()
{

    Serial.println("FragmentGenerator: Generating new fragments");
    Data* f1 = new Fragment(true);
    Data* f2 = new Fragment(true);
    Data* f3 = new Fragment(true);
    Data* f4 = new Fragment(val);
    val = !val;
    link1->insert(f1);
    link2->insert(f2);
    link3->insert(f3);
    link4->insert(f4);
}

