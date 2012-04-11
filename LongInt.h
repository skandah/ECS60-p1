#ifndef _LONGINT_H
#define _LONGINT_H

#include <iostream>
#include <fstream>
#include "QueueAr.h"
#include "StackAr.h"


// LongInt class
//
// CONSTRUCTION:
//
// ******************PUBLIC OPERATIONS*********************
//
// ******************ERRORS********************************

class LongInt
{
private:
	int i; 
	StackAr <int> intStack(1000001); 
	QueueAr <int> intQueue(1000001);
	

public:
	

	LongInt()
	{
		//this->intStack = new StackAr<int>(1000001); 
		//this->intQueue = new QueueAr<int>(1000001); 
	} 
	~LongInt()
	{
		delete intStack; 
		delete intQueue; 
	}
	//LongInt operator+(LongInt toAdd); 

	//ostream& operator>>(ostream &out, LongInt& longout);
	//istream& operator>>(istream &in, LongInt& longin);
	   
};

#endif
