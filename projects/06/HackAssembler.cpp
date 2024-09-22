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
	//out += '0';
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
	string outfile;
	int idx = 0;
	char *temp = argv[1];
	while(temp[idx] != '.'){
		outfile += temp[idx++];
	}
	outfile += '.';
	outfile += string("hack");
	cout << " output file name " << outfile; 

	ofstream outPut(outfile);

	//outPut << "check";
	Parser parser(argv[1]);
	if(parser.get_error_found()){
		cerr << "file " << argv[1] << " could not be opened successfully, so exiting.." << endl;
		return 0;
	}
	Code code;
	string out;
	while(parser.hasMoreLines()){

		parser.advance();
		if(!parser.getInstruction().empty()){
			instruction_type insType =  parser.instructionType();
			if((insType == A_INSTRUCTION) or (insType == L_INSTRUCTION)){
				cout << " a instruction " << endl;
				out = parser.symbol();
				//cout << out << endl;
				uint16_t num = stoi(out);
				//cout << num << endl;
				out.clear();
				out = u16_to_binary(num);
				//cout << out << endl;
				outPut << out << endl;
			}
			else{
				cout << "c instruction " << endl;
				string whole_str;
				whole_str += string("111");
				out.clear();	
				out = parser.comp();
				cout << "comp " <<  out << endl;
				if(out.empty()){
					
				}
				else{
					out = code.comp(out);
				}
				cout << out << endl;
				whole_str += out;
				out.clear();
				out = parser.dest();
				cout << "final dest " << out << endl;
				if(out.empty()){
					out = string("000");
				}
				else{
					out = code.dest(out);
				}
				//out = code.dest(out);
				//cout << out << endl;
				whole_str += out;
				out.clear();
				out = parser.jump();
				cout << out << endl;
				out = code.jump(out);
				cout << out << endl;
				whole_str += out;
				while(whole_str.length() < 16){
					whole_str += '0';
				}

				outPut << whole_str << endl;



			}
		}


	}
	return 0;


}

