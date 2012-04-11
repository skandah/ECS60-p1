#include <iostream>
#include <fstream>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList2.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"
using namespace std; 
vector<CursorNode <int> > cursorSpace; 

void RunList(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	List<int> myList;
	ListItr<int> myItr = myList.zeroth();
	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		if (action == "i")
		{
			myList.insert(data, myItr);
		}

		if (action == "d")
		{
			myList.remove(data);
		}
	}
}

void RunCursorList(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	CursorList<int> myCursorList(cursorSpace); 
	CursorListItr<int> myCursorItr = myCursorList.zeroth();
	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		if (action == "i")
		{
			myCursorList.insert(data, myCursorItr);
		}

		if (action == "d")
		{
			myCursorList.remove(data);
		}
	}
}

void RunStackAr(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	StackAr<int> myStackAr(1000001);

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		if (action == "i")
		{
			myStackAr.push(data);
		}

		if (action == "d")
		{
			myStackAr.pop();
		}
	}
}

void RunStackLi(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	StackLi<int> myStackLi;

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());
		
		if (action == "i")
		{
			myStackLi.push(data);
		}

		if (action == "d")
		{
			myStackLi.pop();
		}

		
	}
}

//Has error: terminate called after throwing an instance of 'Overflow'
void RunQueueAr(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	Queue<int> myQueue(1000001);

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		if (action == "i")
		{
			myQueue.enqueue(data);
		}

		if (action == "d")
		{
			myQueue.dequeue();
		}
	}
}

void RunSkipList(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');
	
	file >> command;
	action = command.substr(0,1);
	data = atoi(command.substr(1).c_str());

	SkipList<int> mySkip(data, 1000001);
	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());
		if (action == "i")
		{
			mySkip.insert(data);
		}

		if (action == "d")
		{
			mySkip.deleteNode(data);
		}
		
	}
}

int getChoice()
{
	int choice; 

	cout << "ADT Menu" << endl;
	cout << "0. Quit" << endl; 
	cout << "1. LinkedList" << endl;
	cout << "2. CursorList" << endl;
	cout << "3. StackAr" << endl;
	cout << "4. StackLi" << endl;
	cout << "5. QueueAr" << endl;
	cout << "6. SkipList" << endl;
	cout << "Your choice >> "; 
	cin >> choice; 

	return choice; 
}


int main()
{
	int choice = 0; 
	CPUTimer ct; 
	string filename; 

	//Get file with list of instructions
	cout << "Filename >> "; 
	cin >> filename;
	ifstream file(filename.c_str(), ifstream::in);
	
	//Main action
	do
	{
		choice = getChoice();
		ct.reset();

 		switch (choice)
   		{
			case 1: RunList(file); break;
	       	case 2: RunCursorList(file); break;
	       	case 3: RunStackAr(file); break;
	       	case 4: RunStackLi(file); break;
	       	case 5: RunQueueAr(file); break;
	       	case 6: RunSkipList(file); break;
     	}
     	cout << "CPU time: " << ct.cur_CPUTime() << endl;
     	file.clear();
     	file.seekg(0, ios::beg);
	} while(choice > 0);

	return 0; 
}
