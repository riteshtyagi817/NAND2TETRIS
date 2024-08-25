#include "SymbolTable.h"

SymbolTable::SymbolTable(){

	symTable["R0"] = 0;
	symTable["R1"] = 1; 
	symTable["R2"] = 2;
	symTable["R3"] = 3;
	symTable["R4"] = 4;
	symTable["R5"] = 5;
	symTable["R6"] = 6;
	symTable["R7"] = 7;
	symTable["R8"] = 8;
	symTable["R9"] = 9;
	symTable["R10"] = 10;
	symTable["R11"] = 11;
	symTable["R12"] = 12;
	symTable["R13"] = 13;
	symTable["R14"] = 14;
	symTable["R15"] = 15;
	symTable["SCREEN"] = 16384;
	symTable["KBD"] = 24576;
	symTable["SP"] = 0;
	symTable["LCL"] = 1;
	symTable["ARG"] = 2;
	symTable["THIS"] = 3;
	symTable["THAT"] = 4;
	

}

void SymbolTable::addEntry(string symbol, int address){
	symTable[symbol] = address;

}
bool SymbolTable::contains(string symbol){
	if(symTable.find(symbol) == symTable.end()) return false;
	else return true;

}
int SymbolTable::getAddress(string symbol){
	return symTable[symbol];

}
