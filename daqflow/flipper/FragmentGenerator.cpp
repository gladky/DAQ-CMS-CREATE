// Generated from /cms.flipper/src/main/java/FragmentGenerator.java


#include "FragmentGenerator.hpp"

#include "FlipperObject.hpp"
#include "Fragment.hpp"



FragmentGenerator::FragmentGenerator(FlipperObject* link1_, FlipperObject* link2_, FlipperObject* link3_, FlipperObject* link4_) 
{
    link1 = link1_;
    link2 = link2_;
    link3 = link3_;
    link4 = link4_;
    val = false;
}

void FragmentGenerator::generateAndInsertFragments()
{
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

