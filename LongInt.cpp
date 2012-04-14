#include "LongInt.h"

LongInt::LongInt()
{
	StackAr <int> newStack(1000001); 
	Queue <int> newQueue(1000001);
	intStack = newStack;
	intQueue = newQueue;
} 

LongInt::~LongInt()
{ 
}

void LongInt::addDigit(int digit)
{
	intStack.push(digit);
	intQueue.enqueue(digit);
}

LongInt LongInt::operator+(LongInt& int2)
{
	StackAr<int> stack1 = this->intStack;
	StackAr<int> stack2 = int2.intStack;
	StackAr<int> tempStack (1000001);
	LongInt newInt;
	int curr1;
	int curr2;
	int newDigit;
	int carry = 0;
		
	while (!stack1.isEmpty() && !stack2.isEmpty())
	{
		curr1 = stack1.top();
		stack1.pop();
		curr2 = stack2.top();
		stack2.pop();
		newDigit = curr1 + curr2 + carry;
		if (newDigit >= 10)
		{
			newDigit -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		tempStack.push(newDigit);
	}
	
	if (!stack1.isEmpty())
	{
		while (!stack1.isEmpty())
		{
			curr1 = stack1.top();
			stack1.pop();
			newDigit = curr1 + carry;
			if (newDigit >= 10)
			{
				newDigit -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			tempStack.push(newDigit);
		}
	}

	if (!stack2.isEmpty())
	{
		while (!stack2.isEmpty())
		{
			curr2 = stack2.top();
			stack2.pop();
			newDigit = curr2 + carry;
			if (newDigit >= 10)
			{
				newDigit -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			tempStack.push(newDigit);
		}
	}
	
	while (!tempStack.isEmpty())
	{
		newDigit = tempStack.top();
		tempStack.pop();
		newInt.addDigit(newDigit);
	}	
	return newInt;
}

ostream& operator<<(ostream &out, LongInt& longout)
{
	Queue<int> tempQueue = longout.intQueue;
	while(!tempQueue.isEmpty())
	{
		out << tempQueue.dequeue(); 
	}

	return out; 
}   


istream& operator>>(istream &in, LongInt& longin)
{
	char curr;  
	in.width(1); 
	curr = cin.get();
	while (curr!='\n')
	{
		curr -= 48;
		//longin.intStack->push(curr);
		//longin.intQueue->enqueue(curr);
		longin.addDigit(curr);
		curr = cin.get();
	}
	return in; 
}
