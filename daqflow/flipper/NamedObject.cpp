// Generated from /cms.flipper/src/main/java/NamedObject.java
#include <NamedObject.hpp>


NamedObject::NamedObject(string name_) 
{
	name = name_;
}

string NamedObject::getName()
{
    return name;
}

string NamedObject::toString()
{
    return name;
}


