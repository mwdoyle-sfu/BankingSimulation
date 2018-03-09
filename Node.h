/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Author: Matthew Doyle
 *
 * Date: June 2017
 */

#include <cstdio>  // Needed for NULL
#include "Event.h"
#pragma once

template <class ElementType>   // Indicates this is a template definition

class Node
{
private:
    ElementType data;     // The data in the node
    Node<ElementType>* next;   // Pointer to next node

public:

    // Constructor
    Node();

    // Parametrized constructors
    Node(const ElementType& theData);

    Node(const ElementType& theData, Node<ElementType>* nextNodePtr);

    // Setters
    void setItem(const ElementType& theData);

    void setNext(Node<ElementType>* nextNodePtr);

    // Getters
    ElementType getItem() const;

    Node<ElementType>* getNext() const;

};

template <class ElementType>
Node<ElementType>::Node() :next(NULL) {
}

template <class ElementType>
Node<ElementType>::Node(const ElementType& theData) : data(theData), next(NULL) {
}

template <class ElementType>
Node<ElementType>::Node(const ElementType& theData, Node<ElementType>* nextNodePtr) :
        data(theData), next(nextNodePtr) {
}

template <class ElementType>
void Node<ElementType>::setItem(const ElementType& theData) {
    data = theData;
}

template <class ElementType>
void Node<ElementType>::setNext(Node<ElementType>* nextNodePtr) {
    next = nextNodePtr;
}

template < class ElementType>
ElementType Node<ElementType>::getItem() const {
    return data;
}

template < class ElementType>
Node<ElementType>* Node<ElementType>::getNext() const {
    return next;
}