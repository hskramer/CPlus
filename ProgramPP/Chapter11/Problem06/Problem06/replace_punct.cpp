#include "../../std_lib_facilities.h"

bool is_punct(char& ch)
{
	switch (ch) {
	case '.': case ';': case ',': case '?': case '-': case '\'':
		return true;
	}

	return false;
}

void open_file(const string& name)
{
	string oname{ "" }, line{ "" };
	vector<char>vc;

	cout << "Name of file to write to?" << '\n';
	cin >> oname;

	ifstream ifs{ name.c_str() };
	ofstream ofs{ oname.c_str() };

	while (getline(ifs, line)) {
		stringstream ss{ line };
		for (char& ch : line)
			if (is_punct(ch)) {
				ch = ' ';
				vc.push_back(ch);
			}
			else
				ofs << ch;
			
	}	
}

int main()
try {

	string iname{ "" };

	cout << "Name of file" << '\n';
	cin >> iname;

	open_file(iname);

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