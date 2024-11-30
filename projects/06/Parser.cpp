#include<iostream>
#include<sstream>
#include"Parser.h"
using namespace std;

Parser::Parser(string input_file_name)
{
	in_file.open(input_file_name);	
	error_found = false;
	if(!in_file)
	{
		cout << "File could not be opened successful\n";
		error_found = true;
	}
}
bool Parser::hasMoreLines()
{
#ifdef DEBUG
	cout << __func__ << " starts"  << endl;
#endif
	if(in_file.eof()) return false;
	else return true;
#ifdef DEBUG
	cout << __func__ << " ends"  << endl;
#endif

}
void Parser::advance()
{
#ifdef DEBUG
	cout << __func__ << " starts"  << endl;
#endif
	string out;
	string line;
	
	getline(in_file, line);
	//cout << "line " << line << endl;
	if(line.empty())
	{
	//	cout << "line is empty " << endl;
		current_instruction.clear();
		return;
	}
        stringstream ss(line);
		
	string temp;
	while(ss >> temp){

		if(temp == "//") break;
		else{
			out = temp;
			break;

		}

	}	
	if(!out.empty()){
	//	cout << out << endl;
		current_instruction = out;
	}
#ifdef DEBUG
	cout << __func__ << " ends"  << endl;
#endif
        return;	
}
instruction_type Parser::instructionType()
{
	string temp = current_instruction;
	stringstream ss(temp);
	char c;
	ss >> c;
	if(c == '@')
		return A_INSTRUCTION;
	else if(c == '(')
		return L_INSTRUCTION;
	else return C_INSTRUCTION;

}
string Parser::symbol()
{
	// handling for label first;
	string temp = current_instruction;
	char c;
	stringstream ss(temp);
	ss >> c;
	string out;
	if(c == '(')
	{
		while(ss)
		{
			ss >> c;
			if(c == ')') break;
			out += c;
		}

	}
	else if(c == '@')
	{
		while(ss >> c)
		{
			out += c;
	
		}
		
		
	}
	return out;

}
string Parser::dest()
{
	string temp = current_instruction;
	stringstream ss(temp);
	char c;
	string out;
	bool flag = false;
	bool isD = false;
	while(ss >> c)
	{
		//cout << "dest " << c << endl;
		if(c == '=' ) {
			isD = true;
			break;
		}
		if( c == ';') break;
		out += c;
	//	cout << " out in dest " << out << endl;

	}
	if(isD){
		return out;
	}
	else{
		out.clear();
		return out;
	}


}
string Parser::comp()
{
	string temp = current_instruction;
	stringstream ss(temp);
	char c;
	string out;
	bool flag = false;
	while(ss >> c)
	{
	//	cout << "char in comp " << c << endl;
		if(c != ';')
		{
			out += c;
		}
		if( c == '='){

			out.clear();
		}
		//ss >> c;
		
		if(c == ';') break;
	}
	

	return out;
}
string Parser::jump()
{
	string temp = current_instruction;
	stringstream ss(temp);
	char c;
	string out;
	bool flag = false;
	while(ss >> c)
	{
		if(flag == true)
		{
			out += c;

		}
		//ss >>  c;
		if(c == ';')flag = true;
	}

	return out;

}
bool Parser::get_error_found(){
	return error_found;
}
Parser::~Parser(){

}


