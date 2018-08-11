#include "../../std_lib_facilities.h"

void reverse_char(const string& iname, const string& oname)
{
	vector<char>vchar;
	string line{ "" };
	
	ifstream ifs{ iname.c_str() };
	if (!ifs) error("error opening file", iname);

	ofstream ofs{ oname.c_str() };
	if (!ofs) error("error writing to file", oname);

	while (getline(ifs, line)) {
		for (char& ch : line)
			vchar.push_back(ch);
	}

	reverse(vchar.begin(), vchar.end());

	for (char ch : vchar)
		ofs << ch;
}

int main()
try{

	string ifile{ "" }, ofile{ "" };

	cout << "Enter the name of the file to read." << '\n';
	cin >> ifile;

	cout << "Enter the name of the new file" << '\n';
	cin >> ofile;

	reverse_char(ifile, ofile);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error" << '\n';
	return -2;
}
