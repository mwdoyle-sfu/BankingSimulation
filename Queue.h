/*
 * Queue.h
 *
 * Class Definition: Queue uses a link-based data structure
 *
 * Author: Matthew Doyle
 *
 * Date: June 2017
 */

#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Node.h"
#pragma once

template <class ElementType>
class Queue {

private:

    int elementCount;           // Number of elements currently stored in the List.
    Node<ElementType> *head;    // Pointer to the first node in the Queue.
    Node<ElementType> *tail;    // Pointer to the last node in the Queue
public:

    // Description: Default constructor
    Queue();

    // Description: Destructor
    ~Queue();

/******* Public Interface - START - *******/

    // Description: Returns the number of elements in the Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);

    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();

    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

    // Description: Removes all elements from the Queue
    void removeAll();

    // Description: Prints the contents of the Queue from the first to the last element.
    void printList();

};

template <class ElementType>
Queue<ElementType>::Queue() {
    elementCount = 0;
    head = NULL;
}

template <class ElementType>
Queue<ElementType>::~Queue() {
    removeAll();
}

template <class ElementType>
int Queue<ElementType>::getElementCount() const {
    return elementCount;
}

template <class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return elementCount == 0;
}

template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement) {

    Node<ElementType>* newNodePtr = new Node<ElementType>(newElement);

    // Insert new node
    if (isEmpty())
        head = newNodePtr; // the queue was empty
    else
        tail->setNext(newNodePtr); // The queue was not empty
    tail = newNodePtr; // New node is at back

    elementCount++;
    return true;
}

template <class ElementType>
bool Queue<ElementType>::dequeue() {
    bool result = false;
    if (!isEmpty()) {
        // Queue is not empty, remove front
        Node<ElementType>* nodeToDeletePtr = head;
        if (head == tail) {
            // Special case: one node in the queue
            head = NULL;
            tail = NULL;
        } else
            head = head->getNext();

        // Return deleted node to system
        nodeToDeletePtr->setNext(NULL);
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;

        elementCount--;
        result = true;
    }

    return result;
}

template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    if(isEmpty())
        throw EmptyDataCollectionException("peek() called with empty queue.");

    // Queue is not empty return head
    return head->getItem();
}

template <class ElementType>
void Queue<ElementType>::removeAll() {
    Node<ElementType> *p = head;
    // Traverse the list deleting nodes
    while (p!= NULL){
        head = head->getNext(); // Mustn't "lose" the next node
        delete p; // De-allocate memory
        p = head; // Go to next node
    }
    head = NULL;
    elementCount = 0;
}

template <class ElementType>
void Queue<ElementType>::printList() {
    cout << "\nPrinting from Queue (bankQueue)from front = 0 to back = " << elementCount << endl;
    Node<ElementType> *p = head;
    // Traverse the list
    while (p != NULL){
        cout << p->getItem(); // Print data
        p = p->getNext(); // Go to next Node
        if (p != NULL){
            cout << "\n"; // Print a comma unless at the end of the list
        }
    }
    cout << "\n"; // Don't print a newline - it might not be wanted
}