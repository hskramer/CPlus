#include "../../std_lib_facilities.h"

bool is_vowel(char& ch)
{
	ch = tolower(ch);

	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void disemvowel(const string& file_name)
{
	ifstream ifs{ file_name.c_str() };
	string oname{ "" }, line{ "" };

	cout << "Name of file to write to" << '\n';
	cin >> oname;

	ofstream ofs{ oname.c_str() };

//	char ch{ 0 };
	
	while (getline(ifs, line)) {
		stringstream ss{ line };
		for (char& ch : line) {
			if (is_vowel(ch)) {
				ch = ' ';    // had to use space otherwise compile error empty character constant quoted should contain at least one character
				ofs << ch;
			}
			else if (ch == '\r')
				ofs << '\r';
			ofs << ch;					
		}
	}
}

int main()
try {

	string name{ "" };

	cout << "Name of file" << '\n';
	cin >> name;

	disemvowel(name);

	return 0;
}
catch (exception& e) {
	cerr << "error occured " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkoen errir occured" << '\n';
	return -2;
}