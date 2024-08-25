#include<fstream>
#include<string>
using namespace std;
typedef enum insType{
	A_INSTRUCTION, C_INSTRUCTION, L_INSTRUCTION

}instruction_type;
class Parser
{	
	private:
	ifstream in_file;
	bool error_found;
	string current_instruction;
	public:
	Parser(string input_file_name);
	bool hasMoreLines();
	void advance();
	instruction_type instructionType(); 	
	string symbol();
	string dest();
	string comp();
	string jump();
	bool get_error_found();
	~Parser();	
};
