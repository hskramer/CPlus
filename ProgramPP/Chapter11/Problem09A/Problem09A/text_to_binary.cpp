#include "../../std_lib_facilities.h"

void text_to_binary(const string& iname, const string& oname)
{
	ifstream ifs{ iname.c_str() };
	if (!ifs) error("can't open file", iname);

	ofstream ofs{ oname, ios_base::binary };
	if (!ofs) error("can't open file", oname);


	for(char ch; ifs.read(as_bytes(ch), sizeof(char));)
		ofs.write(as_bytes(ch), sizeof(char));

}

int main()
try {

	string name{ "" }, new_file{ "" };
	cout << "Enter input file name\n";
	cin >> name;

	cout << "Enter name of new binary file\n";
	cin >> new_file;

	text_to_binary(name, new_file);

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what()<< endl;
	return -1;
}
catch (...) {
	cerr << "unkown error" << endl;
}