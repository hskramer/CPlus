#include "../../std_lib_facilities.h"


void remove_punct()
{
	bool is_quote{ false };
	string line{ "" };
	char ch{ 0 };
	
	while (getline(cin, line)) {
		is_quote = false;
		for (char ch : line) {
			if (ch == '"') {
				is_quote = true;
			}
			else if (!is_quote && ispunct(ch)) {
				ch = ' ';
				cout << ch;
			}
			
			cout << ch;
		}
		cout << '\n';
	}
}


int main()
try {
	// this will remove all puncuation you enter unless surrounded by double quotes

	remove_punct();

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