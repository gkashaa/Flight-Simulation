//========================================================
// UserInterface.cpp
// Implementation file for the UserInterface class.
//========================================================

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>
#include "UserInterface.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;


//----------------------------------------
// Constructor
//----------------------------------------
UserInterface::UserInterface() {

}

//----------------------------------------
// Destructor
//----------------------------------------
UserInterface::~UserInterface() {

}

//----------------------------------------
// Get user input
//----------------------------------------
void UserInterface::getUserInput(int &speed) {
	
	char datafile[16];	// User input of the datafile to be opened
	ifstream myFile;
	char FlightSim[] = "FlightSim02.txt";	// Desired datafile

	cout << "-------------Welcome to the Flight Simulation!-------------" << endl;
	cout << "Enter in file: "; 
	cin >> datafile;

	myFile.open(datafile);	// Open the file

	// If my file does not open or the file entered in by the user does not match the desired datafile
	if (!myFile || strcmp(FlightSim, datafile) != 0)	 
	{
		cout << "Failed to open file.\nProgram terminating...\n";
		exit(0);
	}
	
	// Prompt user to enter in speed for the simulator
	cout << "Enter in choice of speed (1x, 2x, 3x): ";
	cin >> speed;

}


//------------------------------------------
// Organize all of the city and flight data
//-------------------------------------------
void UserInterface::storeAllData() {

	flight.storeFlightData();
	flight.storeAirPlaneData();
	flight.storeCityDate();

}

//----------------------------------------
// Display flights to user
//----------------------------------------
void UserInterface::display(int *hour, int *min, int &speed) {


	int startHour = *hour;				// Starting hour of the flight simulator
	int endHour = 9;					// Ending hour of the flight simulator

	for (int i = startHour; i <= endHour; i++) {

		// Display flight information every 5 seconds
		while (*min < 60) {

            // Display current clock time at the beginning of each report
			cout << endl << endl << "==============================================================" << endl;
			cout << "Current Clock Time: " << *hour << ":" << setfill('0') << setw(2) << *min << endl;
			cout << "==============================================================" << endl << endl;

			flight.getCurrentFlight(hour, min, 7);	// Get current flight
			cout << endl;

            // Increment clock
			*min = *min + (5 * speed);	

            // Use thread to control the speed of the simulator
			this_thread::sleep_for(chrono::seconds((5)));


		}

        // Increment clock to the next hour
		*min = 0;
		*hour = *hour + 1;

	}

	cout << "End of the simulation. Goodbye!" << endl;

}




