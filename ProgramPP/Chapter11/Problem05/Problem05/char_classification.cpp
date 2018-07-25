#include "../../std_lib_facilities.h"

void classify_char(char& ch)
{
	cout << ch; // this is really just a series of if type cout.
	if (isspace(ch))
		cout << " isspace";
	if (isalpha(ch))
		cout << " isalpha";
	if (islower(ch))
		cout << " islower";
	if (isupper(ch))
		cout << " isupper ";
	if (isdigit(ch))
		cout << " isdigit ";

	cout << '\n';
}

void parse_string(string& line)
{
	stringstream ss{ line };

	for (char& ch : line) {
		classify_char(ch);
	}
}

int main()
try {
	string str{ "" };
	cout << "Please enter a line of text with numbers and proper punctuation." << '\n';
	getline(cin, str);

	parse_string(str);

	return 0;
}
catch (exception& e) {
	cerr << "error occured " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkoen error occered " << '\n';
	return -2;
}