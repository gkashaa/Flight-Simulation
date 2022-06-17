#pragma once
#include "AircraftFactory.h"
#include "Aircraft.h"

class BusinessJetFactory : public AircraftFactory
{
public:

	BusinessJetFactory();       // Constructor
	~BusinessJetFactory();      // Destructor
	BusinessJetFactory *getInstance();      // Singleton Pattern
	Aircraft* createPlane();    // Returns aircraft product

};

