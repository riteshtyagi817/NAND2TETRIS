#include<unordered_map>
#include<string>
using std::string;
using std::unordered_map;
class Code
{
	private:
	unordered_map<string,string> dest_map;
	unordered_map<string,string> comp_map;
	unordered_map<string,string> jump_map;
	public:
	Code();
	string dest(string input);
	string comp(string input);
	string jump(string input);
	void form_dest_map();
	void form_comp_map();
	void form_jump_map();
	
};
