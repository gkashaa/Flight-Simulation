//========================================================
// Calculations.h
// Interface file for the Calculations class.
//========================================================


#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <fstream>

using namespace std;

class Calculations
{
	public:
	
		Calculations();     // Constructor
		~Calculations();    // Destructor
    
        // Calculate the total trip time for each flight
		void tripTime(double &tripT, double &distance, double &speed);
    
        // Calculate the estimated time arrival time for each flight
		void ETA(double &tripT, double depTimeMin, double &arrTimeMin, int &arrHour, int &arrMin);
    
        // Calculate the distance from the depature city and the distance from the destination city
		void distFromDepandDest(double &ET, double &distDepart, double &distDest, double &distance, double &speed, double &tripT, double curTimeMin, double depTimeMin);
        
        // Calculate the current latitude and longitude for each flight
		void currLatandLong(double &cLat, double &cLon, double dlat, double dlon, double alat, double alon, double &ET, double &TT);
    
        // Calculate the cruise altitude for each flight
		void currAlt(int &cA, double arrTimeMin, double currTimeMin, double &ET, double roc, double cs);
};

#endif