#include "SingleEngineJet.h"
#include <iostream>
using namespace std;

// Constructor
SingleEngineJet::SingleEngineJet() {

  
    
}

// Destructor
SingleEngineJet::~SingleEngineJet() {

    
    
}

//---------------------------------------------------
// Gets all of the Single Engine Jets
// Args:
//          make - Holds the name of the plane make
//          desc - Holds the description of the aircraft
//          roc - Holds the rate of climb in feet per minute.
//          wngspn - Holds the wing span in feet.
//          len - Holds the fuselage length in feet.
//          cspd - Holds the cruise speed in flight.
//          calt - Holds the cruise altitude.
//---------------------------------------------------
void SingleEngineJet::getJet(char make[32], char desc[32], double &roc, double &wngspn, double &len, double &cspd, double &calt) {
	
    // Open and read in Flight data file
    fdp->InitFlightData("AirlineFlightData02.xml");

    // Get the aircraft data
	fdp->getAircraftData(SINGLEENGINE, make, desc, &roc, &wngspn, &len, &cspd, &calt);
	
}
