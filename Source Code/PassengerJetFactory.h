#pragma once
#include "AircraftFactory.h"
#include "Aircraft.h"

class PassengerJetFactory: public AircraftFactory
{
public:
    
	PassengerJetFactory();      // Constructor
	~PassengerJetFactory();     // Destructor
	PassengerJetFactory *getInstance();         // Singleton Pattern
	Aircraft* createPlane();    // Returns aircraft product

};

