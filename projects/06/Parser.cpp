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
	if(in_file.eof()) return false;
	else return true;

}
void Parser::advance()
{
	string out = "";
	do{
		string line;
		getline(in_file, line);
        	stringstream ss(line);
		while(ss)
		{
			string temp;
			ss >> temp;
			if(temp == "//")
				break;
			out = temp;

		}
		
	}while(out == "");
	current_instruction = out;
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
		while(ss)
		{
			ss >> c;
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
	while(ss)
	{
		ss >> c;
		if(c == '=') break;
		out += c;
	}
	return out;


}
string Parser::comp()
{
	string temp = current_instruction;
	stringstream ss(temp);
	char c;
	string out;
	bool flag = false;
	while(ss)
	{
		if(flag == true and c != ';')
		{
			out += c;
		}
		ss >> c;
		if(c == '=')
			flag = true;
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
	while(ss)
	{
		if(flag == true)
		{
			out += c;

		}
		ss >>  c;
		if(c == ';')flag = true;
	}

	return out;

}




