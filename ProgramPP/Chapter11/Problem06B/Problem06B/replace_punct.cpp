#include "../../std_lib_facilities.h"


void remove_punct(const string& name)
{
	// this one will remove all punctuation in file except characters within double quotes

	bool is_quote{ false };
	string oname{ "" }, line{ "" };
	vector<char>vchar; 

	cout << "Name of file to write to?" << '\n';
	cin >> oname;

	ifstream ifs{ name.c_str() };
	ofstream ofs{ oname.c_str() };

	while (getline(ifs, line)){
		for (char& ch : line) {
			if (ch == '"') {
				is_quote = true;
			}
			else if (!is_quote && ispunct(ch)) {
				ch = ' ';
				vchar.push_back(ch);
			}		
			vchar.push_back(ch);			
		}
		is_quote = false;
		vchar.push_back('\n');// see problem 8 for a simple function that removes punctuation and hyphenated words also removes quotes 	
	}						  
		
	for (char ch : vchar)
		ofs << ch;
}

int main()
try {

	string iname{ "" };

	cout << "Name of file?" << '\n';
	cin >> iname;

	remove_punct(iname);

	return 0;
}
catch (exception& e) {
	cerr << "error occurred " << e.what() << '\n';
	return - 1;
}
catch (...) {
	cerr << "unkown error occurred" << '\n';
	return -2;
}