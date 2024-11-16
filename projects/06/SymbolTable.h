#include<unordered_map>
#include<string>
using namespace std;
using namespace std;

class SymbolTable{

	public:
	SymbolTable();
	void addEntry(string symbol, string address);
	bool contains(string symbol);
	string getAddress(string symbol);
	
	private:
	unordered_map<string, string> symTable;

};
