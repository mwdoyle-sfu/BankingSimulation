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

#include <iostream>
#pragma once

using namespace std;

class Event {

private:
    static const char ARRIVAL = 'A';
    static const char DEPARTURE = 'D';

    char type;
    int time;
    int length;

public:

    // Constructor
    Event();
    Event(char type, int time);
    Event(char type, int time, int length);

    // Getters
    char getType() const;
    int getTime() const;
    int getLength() const;

    // Setters
    void setType( char aType );
    void setTime( int aTime );
    void setLength( int aLength );

    // Description: Return true if this event is an arrival event, false otherwise.
    bool isArrival();

    // Overloaded Operators
    // Description: Returns "true" if "this" < "rhs", "false" otherwise.
    bool operator<(const Event& rhs);

    // Description: Prints the content of "this".
    friend ostream& operator<<(ostream & os, const Event& rhs);

};

