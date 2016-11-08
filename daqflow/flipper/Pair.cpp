// Generated from /cms.flipper/src/main/java/Pair.java
#include <Pair.hpp>


Pair::Pair(sting left_, string right_) 
{
    left = left_;
    right = right_;
}

Pair* Pair::of(string left, string right)
{
    return new Pair(left, right);
}

string Pair::getLeft()
{
    return left;
}

string Pair::getRight()
{
    return right;
}

