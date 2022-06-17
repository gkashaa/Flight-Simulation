//========================================================
// UserInterface.h
// Interface file for the UserInterface class.
//========================================================

#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "FlightInfo.h"
#include <fstream>

using namespace std;

class UserInterface
{
	public:

		FlightInfo flight;									// FlightInfo object
		UserInterface();								// Constructor
		~UserInterface();								// Destructor
		void getUserInput(int &speed);					// Get the user input
		void storeAllData();							// Organize the city and flight data
		void display(int *hour, int *min, int &speed);  // Display flights
		


};

#endif