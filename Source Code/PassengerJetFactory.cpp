#include "PassengerJetFactory.h"
#include "PassengerJet.h"
#include <stddef.h>
using namespace std;

// Constructor
PassengerJetFactory::PassengerJetFactory() {

    
    
}

// Destructor
PassengerJetFactory::~PassengerJetFactory() {

    
    
}

// Singleton Pattern
PassengerJetFactory *PassengerJetFactory::getInstance() {
	static PassengerJetFactory *instance = NULL;
	if (instance == NULL)
	{
		instance = new PassengerJetFactory();
	}
	return instance;
}

// Returns aircraft product
Aircraft* PassengerJetFactory::createPlane() {
	return new PassengerJet;
}
