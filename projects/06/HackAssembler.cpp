#include<iostream>
#include<sstream>
using namespace std;
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

int main(int argc, char *argv[])
{
	// we will take the input file as the command line argument
	if(argc < 2){
		cerr << "Please provide the input in the format [exe] [inputfile.asm] " << endl;
		return 0;
	}
	Parser parser(argv[1]);
	if(parser.get_error_found()){
		cerr << "file " << argv[1] << " could not be opened successfully, so exiting.." << endl;
		return 0;
	}
	string out;
	while(parser.hasMoreLines()){

		parser.advance();
		instruction_type insType =  parser.instructionType();
		if((insType == A_INSTRUCTION) or (insType == L_INSTRUCTION)){
			out = parser.symbol();
		}
		else{
			
			out = parser.dest();

		}


	}
	return 0;


}










/* demo code 


 	string input = argv[1];
        ifstream in; 
        in.open(input);
        string line;
    
        while(getline(in,line)){
    
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
		if(!out.empty())
        		cout << out << endl;
	}

	return 0;
*/
