//========================================================
// FlightInfo.cpp
// Implementation file for the FlightInfo class.
//========================================================

#pragma warning(disable : 4996)

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "FlightInfo.h"
#include "Flyweight.h"

// Data for the city info
vector <string> name_info, state_info, symbol_info;
vector <double> lat_info, lon_info;
vector<vector<char>> symbol_array;
vector<vector<int>> dist_array;


// Data for the flight info
vector <string> airline_info, plane_info, departCity_info, destCity_info;
vector <int> flNum_info, depHr_info, depMin_info;

// Data for the airflight info
vector <string> make_info, desc_info;
vector <double> roc_info, wngs_info, len_info, cs_info, ca_info;


// Variables for the symbol array and the distance array

char *sym = new char[16];               // Pointers for the city symbol array
char **symb = &sym;

double *dist = new double[16];          // Pointer for the city diatance array
int row = 0;                            // Row of the city distance array
int col = 0;                            // Col of the city distance array
    
// Variables for the times
double currentTimeMin = 0;              // Current time of the simulation (in min)
double arrTimeMin = 0;                  // Arrival time (in min)
double depTimeMin = 0;                  // Depature time (in min)
double tripTime = 0;                    // Trip time (in min)
double elapsedTime = 0;                 // Elapsed time (in min)
int arrivalHour = 0;                    // Arrival hour
int arrivalMin = 0;                     // Arrival min

// Variables for the distances
double distFromDepart = 0;              // Distance from the departure city
double distFromDest = 0;				// Distance from the desitnation city

// Variables for 
double cLat = 0;                        // Current latitude
double cLon = 0;                        // Current longitude
int cruiseAlt = 0;                      // Current altitude


//----------------------------------------
// Constructor
//----------------------------------------
FlightInfo::FlightInfo()
{
	
}


//----------------------------------------
// Destructor
//----------------------------------------
FlightInfo::~FlightInfo()
{

}

//-----------------------------------------------
// Calculate the total trip time for each flight
//-----------------------------------------------
void FlightInfo::getTime() {
	flight->InitFlightData("AirlineFlightData02.xml");
	flight->getStartTime(hour, min);
}


//-----------------------------------------------
// Store the city data
//-----------------------------------------------
void FlightInfo::storeCityDate() {

	// Declare and define variables for the CityData functions
	char name[30] = "";
	char state[30] = "";
	char symbol[30] = "";
	double lat[30] = { 0 };
	double lon[30] = { 0 };

	
	// Call InitCityData function to read in the file
	city->InitCityData("CityData02.xml");



	// Get the city data function and store each data in its own vector
	for (int i = 0; i < 15; i++) {
		city->getCityData(name, state, symbol, lat, lon);
		city->getCitySymbolsArray(&symb);
		city->getDistTable(&dist);
		
			
		name_info.push_back(name);			// Vector for the city names
		state_info.push_back(state);		// Vector fot the city states
		symbol_info.push_back(symbol);      // Vector for the symbols of each city
		lat_info.push_back(*lat);           // Vector for the latitude for each city
		lon_info.push_back(*lon);           // Vector for the longitude for each city
	}

}


//-----------------------------------------------
// Store the airplane data
//-----------------------------------------------
void FlightInfo::storeAirPlaneData() {

    
    // Declare and define variables for the FlightData functions
	char make[30] = " ";
	char desc[30] = " ";
	double roc = 0;
	double wngs = 0;
	double len = 0;
	double cs = 0;
	double ca = 0;
	

    // Call InitFlightData function to read in the file
	flight->InitFlightData("AirlineFlightData02.xml");

    
    // Create instance of Flyweight class
	Flyweight *fly = new Flyweight;
    
    
    // Get the aircraft data function and store each data in its own vector
	for (int i = 0; i < 9; i++) {

		// Create one instance for each aircraft 
		fly->createAircrafts(i, make, desc, roc, wngs, len, cs, ca);
		
        
		make_info.push_back(make);         // Vector for the make of the airplane
		desc_info.push_back(desc);         // Vector for the description of the airplane
		roc_info.push_back(roc);          // Vector for the rate of climb
		wngs_info.push_back(wngs);        // Vector for the wings
		len_info.push_back(len);          // Vector for the length
        cs_info.push_back(cs);            // Vector for the cruise speed
		ca_info.push_back(ca);            // Vector for the cruise altitude
	}

}


//-----------------------------------------------
// Store the flight data
//-----------------------------------------------
void FlightInfo::storeFlightData() {

    
    // Declare and define variables for the FlightData functions
	char airline[30] = "";
	char plane[30] = "";
	int flNum[30] = { 0 };
	char departCity[30] = "";
	int depHr[30] = { 0 };
	int depMin[30] = { 0 };
	char destCity[30] = "";
	

    // Call InitFlightData function to read in the file
	flight->InitFlightData("AirlineFlightData02.xml");


    // Get the flight data function and store each data in its own vector
	for (int i = 0; i < 22; i++) {
		flight->getFlightData(airline, plane, flNum, departCity, depHr, depMin, destCity);
		// getPlane(plane)
        
		airline_info.push_back(airline);            // Vector for the airline of each flight
		plane_info.push_back(plane);                // Vector for the plane of each flight
		flNum_info.push_back(*flNum);               // Vector for the flight information of each flight
		departCity_info.push_back(departCity);      // Vector for the depature cities
		depHr_info.push_back(*depHr);               // Vector for the depature hours
		depMin_info.push_back(*depMin);             // Vector for the depature minutes
		destCity_info.push_back(destCity);          // Vector for the destination cities
	}

}


//-----------------------------------------------
// Get the current flight
//-----------------------------------------------
void FlightInfo::getCurrentFlight(int *currentHour, int *currentMin, int n) {


	int idxDP = 0;			// Index of the information for the departure city
	int idxDT = 0;			// Index of the information for the destination city
	int idxA = 0;			// Index of the information for the current aircraft
	int idxF = 0;			// Index of the information for the current flight
	double dist = 0;		// Distance between two cities


	for (idxF = 0; idxF < 22; idxF++) {								/// Run for each flight in file

		// The current time of the flight simulation (in minutes)
		currentTimeMin = (*currentHour * 60) + *currentMin;  

		// The depature time of the current flight
		depTimeMin = (depHr_info.at(idxF) * 60) + depMin_info.at(idxF);

		// Get the additional information needed to display each flight
		getAdditonalInfo(idxDP, idxDT, idxA, idxF, dist, arrivalHour, arrivalMin);                       



        // Display en route flight if the current time is in between the flight's depature and arrival time
		if (currentTimeMin > depTimeMin && currentTimeMin < arrTimeMin) {
			
			enRouteFlights(idxDP, idxDT, idxA, idxF, dist);
			
		}

        // Display depature flight if the current flight's depature time is equal to the current time
		if (currentTimeMin == depTimeMin) {
			
			departFlights(idxDP, idxDT, idxA, idxF, dist);
			

		}

        // Display arrival flight if the current flight's arrival time is equal to the current time
		if (currentTimeMin == arrTimeMin) {
			arrFlights(idxDP, idxDT, idxA, idxF, dist);
			
		}

		else {
		}
		

	}
}


//-----------------------------------------------
// Get the additional information for each flight (including latitude, longitude, etc.)
//-----------------------------------------------
void FlightInfo::getAdditonalInfo(int &idxDP, int &idxDT, int &idxA, int idxF, double &distance, int &aH, int &aM) {

			for (int a = 0; a < 15; a++) {                                                  // Run for each city in city data

				if (departCity_info.at(idxF) == symbol_info.at(a)) {                           // Find the symbol for the depature city
					idxDP = a;

					if (symbol_info.at(idxDP) == symb[a]) {                                     // Find the depature symbol in the city symbol array
						row = a;

						for (int b = 0; b < 15; b++) {

							if (destCity_info.at(idxF) == symbol_info.at(b)) {                 // Find the symbol for the destination city
								idxDT = b;

								if (symbol_info.at(idxDT) == symb[b]) {                         // Find the destination symbol in the city symbol array
									col = b;
								}
							}
						}
					}
				}

			}

	
		for (int p = 0; p < 9; p++) {                                                       // Run for each plane in flight data
			if (plane_info.at(idxF) == make_info.at(p))                                        // Find the make for the current plane
				idxA = p;
		}
    
		distance = dist[row * 15 + col];                                                                            // Find the distance between the two cities
		cal.tripTime(tripTime, distance, cs_info.at(idxA));                                                                 // Find the trip time of each flight
		cal.ETA(tripTime, depTimeMin, arrTimeMin, arrivalHour, arrivalMin);                                                           // Find the ETA of each flight
    
		cal.distFromDepandDest(elapsedTime, distFromDepart, distFromDest, distance, cs_info.at(idxA), tripTime, currentTimeMin, depTimeMin);          // Find the distance from the depature city
										                                                                                                             // and the distance from the destination city
		
        cal.currLatandLong(cLat, cLon, lat_info.at(idxDP), lon_info.at(idxDP), lat_info.at(idxDT), lon_info.at(idxDT), elapsedTime, tripTime);    // Find the current latitude and longitude
		cal.currAlt(cruiseAlt, arrTimeMin, currentTimeMin, elapsedTime, roc_info.at(idxA), cs_info.at(idxA));                         // Find the current altitude
    
	}

//-----------------------------------------------
// Display the flights that are departing
//-----------------------------------------------
void FlightInfo::departFlights(int &idxDP, int &idxDT, int &idxA, int idxF, double &distance) {

		cout << "Now departing: " << airline_info.at(idxF) << " flight " << flNum_info.at(idxF)
			<< " - " << plane_info.at(idxF) << endl;

		cout << "From: " << name_info.at(idxDP) << ", " << state_info.at(idxDP)
			<< " enroute to " << name_info.at(idxDT) << ", " << state_info.at(idxDT) << endl;

		cout << "ETA: " << arrivalHour << ":" <<  arrivalMin << endl << endl;


	}


//-----------------------------------------------
// Display the flights that are en route
//-----------------------------------------------
void FlightInfo::enRouteFlights(int &idxDP, int &idxDT, int &idxA, int idxF, double &distance) {

		cout << "En route: " << airline_info.at(idxF) << " flight " << flNum_info.at(idxF) << " - " << plane_info.at(idxF) << endl;

		cout << "Departs: " << symbol_info.at(idxDP) << " (" << lat_info.at(idxDP) << ", " << lon_info.at(idxDP) << ") at " <<
			depHr_info.at(idxF) << ":" << depMin_info.at(idxF) << endl;

		cout << "Arrives: " << symbol_info.at(idxDT) << " (" << lat_info.at(idxDT) << ", " << lon_info.at(idxDT) << ") at " <<
			arrivalHour << ":" << arrivalMin << endl;

		cout << "Current location: (" << cLat << ", " << cLon << ")" << endl;
		cout << distFromDepart << " miles from " << symbol_info.at(idxDP) << ", " << distFromDest << " miles from " << symbol_info.at(idxDT) << endl;

		cout << "Current speed: " << cs_info.at(idxA) << " mph" << endl;
		cout << "Current altitude: " << cruiseAlt << " feet" << endl << endl;

	}


//-----------------------------------------------
// Display the flights that are arriving
//-----------------------------------------------
void FlightInfo::arrFlights(int &idxDP, int &idxDT, int &idxA, int idxF, double &distance) {

		cout << "Now arriving: " << airline_info.at(idxF) << " flight " << flNum_info.at(idxF) 
				<< " - " << plane_info.at(idxF) << endl;

		cout << "To: " << name_info.at(idxDT) << ", " << state_info.at(idxDT) << " from " 
				<< name_info.at(idxDP) << ", " << state_info.at(idxDP) << endl;

	
	}
