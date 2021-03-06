#ifndef _LONGINT_H
#define _LONGINT_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "QueueAr.h"
#include "StackAr.h"

using namespace std;


class LongInt
{
	private:
		StackAr <int> intStack; 
		Queue <int> intQueue;
	

	public:
		LongInt();
		~LongInt();
		LongInt operator+(LongInt& toAdd); 
		//LongInt& operator=(LongInt toAssign);
		void addDigit(int);

		friend ostream& operator<<(ostream &out, LongInt& longout);
		friend istream& operator>>(istream &in, LongInt& longin);	   
};

#endif
