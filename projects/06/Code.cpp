#include "Code.h"
#include<iostream>
using std::cout;
using std::endl;

string Code::dest(string in){
	
	string out;
	if(dest_map.find(in) != dest_map.end()){
		out = dest_map[in];
		//cout << "check" << endl;
	}
	return out;
}
string Code::comp(string in){
	
	string out;
	if(comp_map.find(in) != comp_map.end()){
		out = comp_map[in];
		//cout << "check" << endl;
	}
	return out;
}

string Code::jump(string in){
	
	string out;
	if(jump_map.find(in) != jump_map.end()){
		out = jump_map[in];
		//cout << "check" << endl;
	}
	return out;
}



Code::Code()
{
	form_dest_map();
	form_comp_map();
	form_jump_map();

}
void Code::form_dest_map()
{
	dest_map[""] = "000";		
	dest_map["M"] = "001";	
	dest_map["D"] = "010";	
	dest_map["DM"] = "011";	
	dest_map["A"] = "100";	
	dest_map["AM"] = "101";	
	dest_map["AD"] = "110";	
	dest_map["ADM"] = "111";

	return;
}
void Code::form_comp_map()
{
	comp_map["0"] = "0101010";
	comp_map["1"] = "0111111";
	comp_map["-1"] = "0111010";
	comp_map["D"] = "0001100";
	comp_map["A"] = "0110000";
	comp_map["M"] = "1110000";
	comp_map["!D"] = "0001101";
	comp_map["!A"] = "0110001";
	comp_map["-D"] = "0001111";
	comp_map["-A"] = "0110011";
	comp_map["D+1"] = "0011111";
	comp_map["A+1"] = "0110111";
	comp_map["D-1"] = "0001110";
	comp_map["A-1"] = "0110010";
	comp_map["D+A"] = "0000010";
	comp_map["D-A"] = "0010011";
	comp_map["A-D"] = "0000111";
	comp_map["D&A"] = "0000000";
	comp_map["D|A"] = "0010101";
	comp_map["M"] = "1110000";
	comp_map["!M"] = "1110001";
	comp_map["M+1"] = "1110111";
	comp_map["M-1"] = "1110010";
	comp_map["D+M"] = "1000010";
	comp_map["D-M"] = "1010011";
	comp_map["M-D"] = "1000111";
	comp_map["D&M"] = "1000000";
	comp_map["D|M"] = "1010101";


	return;
}
void Code::form_jump_map(){

	jump_map[""] = "000";
	jump_map["JGT"] = "001";
	jump_map["JEQ"] = "010";
	jump_map["JGE"] = "011";
	jump_map["JLT"] = "100";
	jump_map["JNE"] = "101";
	jump_map["JLE"] = "110";
	jump_map["JMP"] = "111";

	return;

}
