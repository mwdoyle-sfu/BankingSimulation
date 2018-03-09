/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from Frank M. Carrano and Tim Henry Data Abstraction and problem solving with C++.
 */
 

#include "EmptyDataCollectionException.h"  

EmptyDataCollectionException::EmptyDataCollectionException(const string& message): 
logic_error("Empty Data Collection ADT Class Exception: " + message) {
}
