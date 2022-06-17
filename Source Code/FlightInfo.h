//========================================================
// FlightInfo.h
// Interface file for the FlightInfo class.
//========================================================

#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H

#include <fstream>
#include "CityDataParser.h"
#include "FlightDataParser.h"
#include "Calculations.h"

using namespace std;


class FlightInfo
{
	public:
		int hour[1];                 // Start hour
		int min[1];                  // Start minute
		CityDataParser *city = CityDataParser::getInstance();         // CityDataParser object
		FlightDataParser *flight = FlightDataParser::getInstance();     // FlightDataParser object
		Calculations cal;			 // Calculations object

		FlightInfo();                // Constructor
		~FlightInfo();               // Destructors

		
		void getTime();             // Get the starting time of simulator
        void storeCityDate();       // Store city data
		void storeAirPlaneData();   // Store the airplane data
		void storeFlightData();     // Store the flight data
        
        // Get current flight
		void getCurrentFlight(int *currentHour, int *currentMin, int n);
    
        // Get additional information for the flight
		void getAdditonalInfo(int &g, int &h, int &i, int n, double &distance, int &aH, int &aM);
    
        // Display departure flights
		void departFlights(int &g, int &h, int &i, int n, double &distance);
    
        // Display en route flights
		void enRouteFlights(int &g, int &h, int &i, int n, double &distance);
    
        // Display arriving flights
		void arrFlights(int &g, int &h, int &i, int n, double &distance);


};

#endif
