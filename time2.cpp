#include <iostream>
#include <fstream>
#include <stdio.h>

#include "CPUTimer.h"
//clude "LinkedList.cpp"
//clude "StackAr.cpp"
//#include "dsexceptions.h"
//clude "CursorList2.cpp"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList2.h"
//clude "QueueAr.cpp"
//clude "StackLi.cpp"
//clude "vector.cpp"
#include "QueueAr.h"
#include "StackLi.h"
//#include "vector.h"
#include "SkipList.h"
//#include "SkipList.cpp"
using namespace std; 
vector<CursorNode <int> > cursorSpace; 


void RunList(FILE *file)
{
	char command[1000];
	int i = -1; 
	//char temp;  
	do
	{
		i++; 
		fscanf(file, "%c", &command[i]); 
		cout << command[i] << endl; 

	}while(command[i] != EOF);

}



void RunCursorList(FILE *file){
	cout << " ";
}  
void RunStackAr(FILE *file){
	cout << " ";
}  
void RunStackLi(FILE *file){
	cout << " ";
}  
void RunQueueAr(FILE *file){
	cout << " ";
} 
void RunSkipList(FILE *file){
	cout << " ";
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
	FILE *file; 
	string filename; 

	cout << "Filename >> "; 
	cin >> filename;

	file = fopen(filename.c_str(), "r"); 


	//ifstream file();
	

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
	fclose(file); 
	return 0; 

}