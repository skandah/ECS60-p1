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

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		cout << action << endl;
		cout << data << endl;
	}
}

void RunCursorList(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		cout << action << endl;
		cout << data << endl;
	}
}

void RunStackAr(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		cout << action << endl;
		cout << data << endl;
	}
}

void RunStackLi(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		cout << action << endl;
		cout << data << endl;
	}
}

void RunQueueAr(ifstream &file)
{
	string command, action;
	int data;
	file.ignore(256, '\n');

	Queue<int> myQueue;

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

	while(file>>command)
	{
		action = command.substr(0,1);
		data = atoi(command.substr(1).c_str());

		cout << action << endl;
		cout << data << endl;
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
	} while(choice > 0);

	return 0; 
}