#include "../../std_lib_facilities.h"

bool is_whitespace(char ws)
{
	return (ws == ' ' || ws == '\t');
}

bool is_digit(char& ch)
{	// initially forgot single quotes around numbers replaced is_digit with isdigit and it worked so it had to be a problem with this.
	switch (ch) {
	case '0': case '1': case '2': case '3': case '4': 
	case '5':	case '6': case '7': case '8': case '9':
		return true;
	default:
		return false;
	}
}

void sum_ints()
{
	string file_name{ " " };
	cout << "Name of file " << endl;
	cin >> file_name;


	char ch{ 0 };
	int sum{ 0 }, i{ 0 };
	string s{ 0 };

	ifstream ifs{ file_name };
	if (!ifs) error("error opening file ", file_name);

	// ch can be one of three things whitespace a digit or a alpha character skip all but digits if its a digit putback and read entire integer and add
	while (ifs >> ch) {
		if (is_digit(ch)) { // first check for digit
			ifs.putback(ch); // if we find a digit putback and read entire integer
			if (ifs >> i) {
				if (ifs.get(ch) && is_whitespace(ch)) { // if its an integer followed by whitespace add to sum
					sum += i;
				}
				else { // if not a digit putback and read string
					ifs.putback(ch);
					ifs >> s;
				}
			}
			else {
				error("bad or corrupted file ");
			}
		}
		else {
			ifs.putback(ch);
			ifs >> s;
		}
	}	
	cout << "The sum is " << sum << endl;
}

int main()
try {
	
	sum_ints();

	return 0;
}
catch (exception& e) {
	cerr << "error occured " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured " << endl;
	return -2;
}