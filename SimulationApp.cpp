/*
 * SimulationApp.cpp
 *
 * Description: Simulates arrivals and departures at a bank
 *
 * Author: Matthew Doyle
 *
 * Date: June 2017
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

// Description: Simulates arrivals and departures at a bank
void simulation() {

    // Initialization list
    Queue<Event> *bankQueue = new Queue<Event>();
    PriorityQueue<Event> *eventListPQueue = new PriorityQueue<Event>();
    bool tellerAvailable = true;
    string aLine = "";
    int time = 0;
    int length = 0;
    Event *newArrivalEvent = NULL;
    double peopleProcessed = 0;

    cout << "Simulation begins" << endl;

    // Create and add arrival events to Queue
    while (getline(cin >> ws, aLine)) {   // while (there is data)
        stringstream ss(aLine);
        ss >> time >> length;
        newArrivalEvent = new Event();
        newArrivalEvent->setTime(time);
        newArrivalEvent->setLength(length);
        peopleProcessed++;
        if (!eventListPQueue->enPriorityQueue(*newArrivalEvent)) return;
        ss.str(string());
        delete newArrivalEvent;
    }

    // Variables required to calculate average wait time
    double departureMinusCurrent = 0;
    double transactionTime = 0;

    // Event loop
    while (!eventListPQueue->isEmpty()) {
        try {
            Event newEvent = eventListPQueue->peek();
            int currentTime = newEvent.getTime();
            int departureTime;

            if (newEvent.isArrival()) { // Process arrival event

                // Output the customer arrival event to the monitor
                cout << "Processing an arrival event at time: " <<  setw(6) << eventListPQueue->peek() << endl;

                // Dequeue and create customer
                eventListPQueue->dePriorityQueue();
                Event customer = newEvent;

                // If there is no one waiting and the teller is available
                // process the event
                if (bankQueue->isEmpty() && tellerAvailable) {
                    departureTime = currentTime + newEvent.getLength();
                    Event newDepartureEvent = Event('D', departureTime);
                    eventListPQueue->enPriorityQueue(newDepartureEvent);
                    tellerAvailable = false;

                    // Variables used for calculating wait time
                    departureMinusCurrent += (departureTime - newEvent.getTime());
                    transactionTime += (newEvent.getLength());

                    // If the teller is busy with another event
                    // enqueue the customer
                } else {
                    bankQueue->enqueue(customer);
                }
            } else { // Process departure event

                // Output the customer departure event to the monitor
                cout << "Processing a departure event at time: " << setw(5) << eventListPQueue->peek() << endl;

                // Process the departure event
                eventListPQueue->dePriorityQueue();
                if (!bankQueue->isEmpty()) {
                    // Customer at front of line begins transaction
                    Event customerD = bankQueue->peek();
                    bankQueue->dequeue();
                    departureTime = currentTime + customerD.getLength();
                    Event newDepartureEventD = Event('D', departureTime);
                    eventListPQueue->enPriorityQueue(newDepartureEventD);

                    // used for calculating wait time
                    departureMinusCurrent += (departureTime - customerD.getTime());
                    transactionTime += (customerD.getLength());

                } else { // If the bank queue is empty the teller is available
                    tellerAvailable = true;
                }
            }
        } catch (EmptyDataCollectionException &anException) {
            cout << "peeking() unsuccessful because " << anException.what() << endl;
        }
    }


    // Calculate the average wait time
    double waitTime = departureMinusCurrent - transactionTime;
    double avg = waitTime / peopleProcessed;

    // Output Final statistics to monitor
    cout << "Simulation Ends" << "\n\n";
    cout << "Final Statistics:" << endl;
    cout << setw(36) << "Total number of people processed: " << peopleProcessed << endl;
    cout << setw(40) << "Average amount of time spent waiting: " << avg << endl;

    delete bankQueue;
    delete eventListPQueue;

}

// Main
int main() {
    // Performs simulation of events
    simulation();
    return 0;
} // end of main