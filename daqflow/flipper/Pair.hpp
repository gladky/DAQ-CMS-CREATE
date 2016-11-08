// Generated from /cms.flipper/src/main/java/Pair.java

#pragma once



class Pair
{


private:
    string left;
    string right;

public:
    static Pair* of(string left, string right);
    virtual string getLeft();
    virtual string getRight();

    // Generated
    Pair(string left, string right);
};
