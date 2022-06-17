#include "BusinessJetFactory.h"
#include "BusinessJet.h"
#include <stddef.h>
using namespace std;

// Constructor
BusinessJetFactory::BusinessJetFactory() {

    
    
}

// Destructor
BusinessJetFactory::~BusinessJetFactory() {

    
    
}

// Singleton Pattern
BusinessJetFactory *BusinessJetFactory::getInstance() {
	static BusinessJetFactory *instance = NULL;
	if (instance == NULL)
	{
		instance = new BusinessJetFactory();
	}
	return instance;
}

// Returns aircraft product
Aircraft* BusinessJetFactory::createPlane() {
	return new BusinessJet;
}
