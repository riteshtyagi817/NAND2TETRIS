#include<iostream>
#include<sstream>
using namespace std;
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"



string u16_to_binary(uint16_t num){

	string out;
	uint8_t count = 16;
	while(count--){

		if(num & 1) out += '1';
		else out += '0';
		num >>= 1;

	}
	out += '0';
	reverse(out.begin(), out.end());
	return out;

}
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
	Code code;
	string out;
	while(parser.hasMoreLines()){

		parser.advance();
		instruction_type insType =  parser.instructionType();
		if((insType == A_INSTRUCTION) or (insType == L_INSTRUCTION)){
			out = parser.symbol();
			//cout << out << endl;
			uint16_t num = stoi(out);
			cout << num << endl;
			out.clear();
			out = u16_to_binary(num);
			cout << out << endl;
		}
		else{
			out.clear();	
			out = parser.dest();
			cout << out << endl;
			out = code.dest(out);
			cout << out << endl;
			

		}


	}
	return 0;


}

