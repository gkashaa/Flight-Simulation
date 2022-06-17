#pragma once
class Flyweight
{
public:
    
	Flyweight();        // Constructor
	~Flyweight();       // Destructor

    // Creates one instance for each aircraft
	void createAircrafts(int i, char make[32], char desc[32], double &roc, double &wngs, double &len, double &cs, double &ca);
};

