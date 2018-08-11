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
	vector<char>vchar;
	char ch{ 0 };

	cout << "Name of file to write to" << '\n';
	cin >> oname;

	ofstream ofs{ oname.c_str() };

	while (ifs.get(ch)) {
		if (!is_vowel(ch)) {
		   vchar.push_back(ch);
		}			
	}

	for(char& ch: vchar)
		ofs<<ch;
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
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "Unknown error occurred" << '\n';
	return -2;
}
