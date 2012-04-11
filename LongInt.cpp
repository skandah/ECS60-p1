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

ostream& operator<<(ostream &out, LongInt& longout)
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
	//char currChar;
	char curr;  
	in.width(1); 
	curr = cin.get();
	while (curr!='\n')
	{
		curr -= 48;
		longin.intStack->push(curr);
		longin.intQueue->enqueue(curr);
		curr = cin.get();
	}
	return in; 
}
