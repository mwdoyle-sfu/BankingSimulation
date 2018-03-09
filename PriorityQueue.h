/*
 * PriorityQueue.h
 *
 * Class Definition: Priority Queue uses an array-based underlying data structure
 *
 * Class invariant: The elements stored in this Priority Queue are always sorted
 *
 * Author: Matthew Doyle
 *
 * Date: June 2017
 */

#include "EmptyDataCollectionException.h"
#include "Event.h"
#pragma once

template <class ElementType>
class PriorityQueue {

private:

    static const int CAPACITY = 100;

    Event elements[CAPACITY]; // Array of PriorityQueue items
    int front;                  // Index to front of PriorityQueue
    int back;                   // Index to back of PriorityQueue
    int elementCount;           // Number of elements currently in the PriorityQueue

public:

    // Constructor
    PriorityQueue();

    // Copy constructor and destructor supplied by compiler

/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Priority Queue.
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enPriorityQueue(Event newElement);

    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dePriorityQueue();

    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

    // Description: Prints the content of "this".
    void printPriorityQueue() const;

};

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() : front(0), back(CAPACITY - 1), elementCount(0) {
}

template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const {
    return elementCount;
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enPriorityQueue(Event newElement) {
    bool result = false;
    if (elementCount < CAPACITY) {
        //PriorityQueue has room for another item
        back = (back + 1) % CAPACITY;
        elements[back] = newElement;
        elementCount++;

        // Sort the list
        if (elementCount <= 1) {
            // do nothing
        } else {
            // swap elements
            for(int i = front; i <= back; i++) {
                for (int j = i + 1; j <= back; j++) {
                    if (elements[i] < elements[j]) {
                        // do nothing
                    } else {
                        Event temp = elements[j];
                        elements[j] = elements[i];
                        elements[i] = temp;
                    }
                }
            }
        }
        result = true;
    }

    return result;
}

template <class ElementType>
bool PriorityQueue<ElementType>::dePriorityQueue() {
    bool result = false;
    if(!isEmpty()) {
        front = (front + 1) % CAPACITY;
        result = true;
    }
    elementCount--;
    return result;
} 

template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    // Enforce precondition
    if (isEmpty()) {
        throw EmptyDataCollectionException("peek() called with empty PriorityQueue");
    }
    // PriorityQueue is not empty: return front
    return elements[front];
}

template <class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue() const {
    cout << "\nPrinting the PriorityQueue (eventListPQueue) from front = " << front << " to back = " << back+1 << endl;
    for ( int i = front; i <= back; i++) {
        cout << elements[i];
        cout << endl;
    }
}