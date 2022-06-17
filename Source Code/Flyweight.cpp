#include "Flyweight.h"
#include "PassengerJetFactory.h"
#include "BusinessJetFactory.h"
#include "SingleEngineJetFactory.h"

// Constructor
Flyweight::Flyweight() {

    

}

// Destructor
Flyweight::~Flyweight() {

    

}

//---------------------------------------------------
// Creates one instance for each aircraft
// Args:
//          i - index of the FlightInfo::storeAirPlaneData
//          make - Holds the name of the plane make
//          desc - Holds the description of the aircraft
//          roc - Holds the rate of climb in feet per minute.
//          wngs - Holds the wing span in feet.
//          len - Holds the fuselage length in feet.
//          cs - Holds the cruise speed in flight.
//          ca - Holds the cruise altitude.
//---------------------------------------------------
void Flyweight::createAircrafts(int i, char make[32], char desc[32], double &roc, double &wngs, double &len, double &cs, double &ca) {

        // Creates the three passenger jets
		if (i < 3) {
			PassengerJetFactory *factory = new PassengerJetFactory;
			Aircraft *s = factory->createPlane();
			s->getJet(make, desc, roc, wngs, len, cs, ca);
		}

        // Creates three business jets
		if (i >= 3 && i < 6) {
			BusinessJetFactory *factory = new BusinessJetFactory;
			Aircraft *s = factory->createPlane();
			s->getJet(make, desc, roc, wngs, len, cs, ca);
		}

        // Creates the three single engine jets
		if (i >= 6 && i < 9) {
			SingleEngineJetFactory *factory = new SingleEngineJetFactory;
			Aircraft *s = factory->createPlane();
			s->getJet(make, desc, roc, wngs, len, cs, ca);
		}

}


