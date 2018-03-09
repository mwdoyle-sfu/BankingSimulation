/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from Frank M. Carrano and Tim Henry Data Abstraction and problem solving with C++.
 */
 
#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class EmptyDataCollectionException : public logic_error {
public:
   EmptyDataCollectionException(const string& message = "");
   
};