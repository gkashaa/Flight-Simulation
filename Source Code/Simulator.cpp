#include "FlightInfo.h"
#include "UserInterface.h"
#include <iomanip>
#include <iostream>

int main(void) {

		FlightInfo flight;					// Create a FlightInfo object
		UserInterface user;					// Create a UserInterface object

		int simSpeed = 0;									// Speed of the simulator

		user.getUserInput(simSpeed);						// Get the user input from the User Interface object
		flight.getTime();									// Get the start hour and min from the FlightInfo object
		user.storeAllData();								// Store the city and flight data
		user.display(flight.hour, flight.min, simSpeed);	// Display each flight 
		

		system("pause");
        return 0;


		

}



