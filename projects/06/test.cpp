#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[])
{
	string input = argv[1];
	
	ifstream in;
	in.open(input);
	string line;
	
	getline(in,line);
	
	stringstream ss(line);
	
	string word;
	string out;
	while(ss)
	{
		ss >> word;
		if(word == "//")
			break;
		out = word;

	}
	
	cout << out << endl;
	return 0;

}
