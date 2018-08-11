#include "../../std_lib_facilities.h"

void binary_to_text(const string& iname, const string& oname)
{
	ifstream ifs{ iname, ios_base::binary };
	if (!ifs) error("can't open file", iname);

	ofstream ofs{ oname.c_str(),  ios_base::out};
	if (!ofs) error("can't open file", oname);


	for (char ch; ifs.read(as_bytes(ch), sizeof(char));)
		ofs << ch;

}

int main()
try {

	string name{ "" }, new_file{ "" };
	cout << "Enter input file name\n";
	cin >> name;

	cout << "Enter name of new binary file\n";
	cin >> new_file;

	binary_to_text(name, new_file);

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error" << endl;
	return -2;
}