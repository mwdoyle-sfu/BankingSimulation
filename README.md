# BankingSimulation

Models of real-world systems often use queues. This program is an event-driven simulation to model a line of customers at a bank. The Queue represents a line at a bank. Arrival events and departure events are maintained using the priority queue and sorted by the time of the event using a link-based implementation.

The input is a text file of arrival and transaction times. The program keeps track of the amount of customers and the cumulative waiting time. This allows for a calculation of average wait time after the last event has been processed. A trace of the events executed and the summary of statistics is then displayed.

How to run the program:
1. In terminal, make the project using `make`
2. Choose an input file and run the program. Example: `./sApp < simulationShuffled1.in`
