#pragma once
#include "Aircraft.h"
#include "FlightDataParser.h"
class SingleEngineJet : public Aircraft
{
public:
    
    SingleEngineJet();      // Constructor
    ~SingleEngineJet();     // Destructor
	FlightDataParser *fdp = FlightDataParser::getInstance();    // Instance of the FlightDataParser class
    
    // Gets all of the aircrafts with the type SINGLEENGINEJET
	void getJet(char make[32], char desc[32], double &roc, double &wngspn, double &len, double &cspd, double &calt);
};
