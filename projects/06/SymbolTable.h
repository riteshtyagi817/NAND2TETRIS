#include<unordered_map>
#include<string>
using namespace std;
using namespace std;

class SymbolTable{

	public:
	SymbolTable();
	void addEntry(string symbol, int address);
	bool contains(string symbol);
	int getAddress(string symbol);
	
	private:
	unordered_map<string, int> symTable;

};
