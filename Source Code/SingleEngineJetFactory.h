#pragma once
#include "AircraftFactory.h"
#include "Aircraft.h"

class SingleEngineJetFactory : public AircraftFactory
{
public:

    SingleEngineJetFactory();       // Constructor
	~SingleEngineJetFactory();      // Destructor
	SingleEngineJetFactory *getInstance();      // Singleton Pattern
	Aircraft* createPlane();        // Returns aircraft product

};


