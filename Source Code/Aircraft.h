#pragma once
class Aircraft
{
public:
	Aircraft();     // Constructor
    ~Aircraft();    // Destructor
    
    // Gets the aircraft needed for each TYPE
	virtual void getJet(char make[32], char desc[32], double &roc, double &wngspn, double &len, double &cspd, double &calt) = 0;
};

