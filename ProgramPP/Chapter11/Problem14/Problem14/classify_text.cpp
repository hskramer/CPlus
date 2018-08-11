#include "../../std_lib_facilities.h"


void classify_char(const string& iname, const string oname)
{
	int sp{ 0 }, al{ 0 }, pu{ 0 }, di{ 0 };
	string line{ "" };
	char ch{ 0 };

	ifstream ifs{ iname.c_str() };
	if (!ifs) error("error opening file", iname);

	ofstream ofs{ oname.c_str() };
	if (!ofs) error("error opening file", oname);

//	while(ifs.get(ch)) this will also work

	while (getline(ifs, line)) {
		for (char& ch : line) {
			if (isspace(ch)) ++sp;
			if (isalpha(ch)) ++al;
			if (isdigit(ch))  ++di;
			if (ispunct(ch)) ++pu; 
			// could add more but this is sufficient to show that it works.
		}
	}
	 
	ofs << "Alpha: " << al << "\nSpaces: " << sp << "\nDigits: " << di << "\nPunctuation: "<<pu << '\n';

	cout << sp << '\n' << al << '\n';
}

int main()
try {

	string ifile{ "" }, ofile{ "" };

	cout << "Enter name of file to read" << '\n';
	cin >> ifile;

	cout << "Enter name of new file" << '\n';
	cin >> ofile;
	
	classify_char(ifile, ofile);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}