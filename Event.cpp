/*
 * Event.h
 *
 * Description: Models arrival or departure event.
 *
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 *
 * Author: Matthew Doyle
 *
 * Date: June 2017
 */

#include "Event.h"
#include <iomanip>

// Constructor
Event::Event() {
    type = 'A';
    time = 0;
    length = 0;
}

// Parametrized constructor
Event::Event(char aType, int aTime) {
    type = aType;
    time = aTime;
    length = 0;
}

// Parametrized constructor
Event::Event(char aType, int aTime, int aLength) {
    type = aType;
    time = aTime;
    length = aLength;
}

// Getters
char Event::getType() const {
    return type;
}

int Event::getTime() const {
    return time;
}

int Event::getLength() const {
    return length;
}

// Setters
void Event::setType(char aType) {
    type = aType;
}

void Event::setTime(int aTime) {
    time = aTime;
}

void Event::setLength(int aLength) {
    if (type == ARRIVAL)
        length = aLength;
    else
        length = 0;
}

// Description: Return true if this event is an arrival event, false otherwise.
bool Event::isArrival() {
    return type == ARRIVAL;
}

// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" object with "rhs" object.
bool Event::operator<(const Event &rhs) {

    // Compare both Event objects
    if (time == rhs.getTime()) {
        if (type == ARRIVAL && rhs.type == DEPARTURE) {
            return true;
        } else {
            return false;
        }
    }else {
        if (time < rhs.getTime()) {
            return true;
        } else {
            return false;
        }
    }
}

// Description: Prints the content of "this".
ostream &operator<<(ostream &os, const Event &rhs) {
    os << rhs.time;
    return os;
}