#include "SymbolTable.h"

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
