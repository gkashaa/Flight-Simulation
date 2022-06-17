#pragma once
#include "Aircraft.h"
#include "FlightDataParser.h"
class BusinessJet : public Aircraft
{
public:
    
    BusinessJet();     // Constructor
    ~BusinessJet();    // Destructor
	FlightDataParser *fdp = FlightDataParser::getInstance();        // Instance of the FlightDataParser class
    
    // Gets all of the aircrafts with the type BUSINESSJET
	void getJet(char make[32], char desc[32], double &roc, double &wngspn, double &len, double &cspd, double &calt);
};
