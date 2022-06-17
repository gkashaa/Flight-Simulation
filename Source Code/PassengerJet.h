#pragma once
#include "Aircraft.h"
#include "FlightDataParser.h"
class PassengerJet : public Aircraft
{
public:
    
	PassengerJet();     // Constructor
	~PassengerJet();    // Destructor
	FlightDataParser *fdp = FlightDataParser::getInstance();        // Instance of the FlightDataParser class
    
    // Gets all of the aircrafts with the type PASSENGERJET
	void getJet(char make[32], char desc[32], double &roc, double &wngspn, double &len, double &cspd, double &calt);

};

