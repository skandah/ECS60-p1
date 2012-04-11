#include "LongInt.h"

LongInt::LongInt()
{
	intStack = new StackAr<int>(1000001); 
	intQueue = new Queue<int>(1000001); 
} 

LongInt::~LongInt()
{
	delete intStack; 
	delete intQueue; 
}

LongInt LongInt::operator+(LongInt)
{



}

ostream& operator>>(ostream &out, LongInt& longout)
{
	Queue<int> tempQueue = *(longout.intQueue);
	while(!tempQueue.isEmpty())
	{
		out << tempQueue.dequeue(); 
	}

	return out; 
}   


istream& operator>>(istream &in, LongInt& longin)
{
	char currChar;
	int curr;  
	currChar = in.get();  
	while (in.good())
	{
		curr = currChar-48; 
		longin.intStack->push(curr); 
		currChar = in.get(); 
	}

	return in; 
}
