//========================================================
// Calculations.cpp
// Implementation file for the Calculations class.
//========================================================

#include "Calculations.h"
#include <cmath>

//----------------------------------------
// Constructor
//----------------------------------------
Calculations::Calculations() {

}


//----------------------------------------
// Destructor
//----------------------------------------
Calculations::~Calculations() {

}


//-----------------------------------------------
// Calculate the total trip time for each flight
//-----------------------------------------------
void Calculations::tripTime(double &tripT, double &distance, double &speed) {

	tripT = (distance / speed) * 60;

}


//-------------------------------------------------------------
// Calculate the estimated time arrival time for each flight
//-------------------------------------------------------------
void Calculations::ETA(double &tripT, double depTimeMin, double &arrTimeMin, int &arrHour, int &arrMin) {

	arrTimeMin = depTimeMin + tripT;        // Arrival time for flight (in min)

	arrHour = arrTimeMin / 60;              // Arrival hour
	arrMin = fmod(arrTimeMin, 60);          // Arrival minute


}


//--------------------------------------------------------------------------------------------
// Calculate the distance from the depature city and the distance from the destination city
//--------------------------------------------------------------------------------------------
void Calculations::distFromDepandDest(double &ET, double &distDepart, double &distDest, double &distance, double &speed, double &tripT, double curTimeMin, double depTimeMin) {
	
    ET = (curTimeMin - depTimeMin);                 // Elpased time
	distDepart = (ET / tripT) * distance;
	distDest = distance - distDepart;
    
}


//--------------------------------------------------------------
// Calculate the current latitude and longitude for each flight
//--------------------------------------------------------------
void Calculations::currLatandLong(double &cLat, double &cLon, double dlat, double dlon, double alat, double alon, double &ET, double &TT) {
	
    cLat = dlat + (alat - dlat) * (ET / TT);        // Current latitude
	cLon = dlon + (alon - dlon) * (ET / TT);        // Current longitude
}


//------------------------------------------------
// Calculate the cruise altitude for each flight
//------------------------------------------------
void Calculations::currAlt(int &cA, double arrTimeMin, double currTimeMin, double &ET, double roc, double cs) {


	int csInFeetMin = (cs / 60) * 5280;             // Cruise speed (in feet/min)
	int MACA = cA / roc;                            // Minutes to achieve cruise altitude
	int DACA = (MACA * csInFeetMin) / 5280;         // Distance to achieve cruise altitude

	int distoAD = DACA * sqrt(3);                   // Distance to ascend to cruise altitude
	int timeAD = (distoAD / cs) * 60;               // Time to ascend to cruise altitude

    
    // Calculate the cruise altitude
	if (currTimeMin == MACA)
		cA = MACA * roc;
		
	else
		cA = ET * roc;

}
