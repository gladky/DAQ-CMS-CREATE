// Generated from /cms.flipper/src/main/java/Data.java

#include "Data.hpp"

#include "FlipperObject.hpp"

#include <iostream>

Data::Data(string name_, bool isFragment, bool isInteresting) 
{
    isFragment_ = isFragment;
    isInteresting_ = isInteresting;
    name = name_;

    if(isInteresting_ == true && isFragment == true){
        name = "F";
    }

    if(isInteresting_ == true && isFragment == false){
        name = "E";
    }

    //name.append(toString(id++));
    dispatched = false;
}

string Data::getName()
{
    return name;
}

/*string Data::toString()
{
    return name
}*/

FlipperObject* Data::getTarget()
{
    return target;
}

void Data::setTarget(FlipperObject* target_)
{
    target = target_;
}

bool Data::isDispatched()
{
    return dispatched;
}

void Data::setDispatched(bool dispatched_)
{
    dispatched = dispatched_;
}

int Data::getProgress()
{
    return progress;
}

void Data::setProgress(int progress_)
{
    progress = progress_;
}

bool Data::isInteresting()
{
    return isInteresting_;
}

bool Data::isFragment()
{
    return isFragment_;
}

int Data::getTimeOutProgress()
{
    return timeOutProgress;
}

void Data::setTimeOutProgress(int timeOutProgress_)
{
    timeOutProgress = timeOutProgress_;
}

int Data::getTargetIndex()
{
    return targetIndex;
}

void Data::setTargetIndex(int targetIndex_)
{
    targetIndex = targetIndex_;
}

char Data::numstr[6];
int Data::id=0;

string Data::toString(int i){
	sprintf(Data::numstr, "%d", i);
	string numberString =  numstr;
	return numberString;
}

