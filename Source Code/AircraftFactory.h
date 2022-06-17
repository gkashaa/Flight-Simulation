#pragma once
#include "Aircraft.h"
class AircraftFactory
{
public:
    
	AircraftFactory();      // Constructor
	~AircraftFactory();     // Destructor
	virtual Aircraft *createPlane() = 0;    // Returns aircraft product
};

