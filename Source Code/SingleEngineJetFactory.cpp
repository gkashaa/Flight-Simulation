#include "SingleEngineJetFactory.h"
#include "SingleEngineJet.h"
#include <stddef.h>
using namespace std;

// Constructor
SingleEngineJetFactory::SingleEngineJetFactory() {

    
    
}

// Destructor
SingleEngineJetFactory::~SingleEngineJetFactory() {

    
    
}

// Singleton Pattern
SingleEngineJetFactory *SingleEngineJetFactory::getInstance() {
	static SingleEngineJetFactory *instance = NULL;
	if (instance == NULL)
	{
		instance = new SingleEngineJetFactory();
	}
	return instance;
}

// Returns aircraft product
Aircraft* SingleEngineJetFactory::createPlane() {
	return new SingleEngineJet;
}
