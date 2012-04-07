#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string filename;
	cout<<"Filename >> ";
	cin>>filename;
	ifstream file(filename.c_str(), ifstream::in);
	char output[256];
	while (!file.eof())
	{
		file>>output;
		cout<<output;
	}
	file.close();
	return 0;
}
