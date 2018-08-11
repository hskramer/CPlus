#include "../../std_lib_facilities.h"

void process_file(const string& input_file)
{
	ifstream ifs{ input_file };
	
	if (!ifs) error("error with file name", input_file);

	vector<char>vc;
	char ch{ 0 };

	while (ifs.get(ch)) {
		if (isupper(ch)) 
			ch = tolower(ch);		
		vc.push_back(ch);
	}
	
	string oname{ "" };
	cout << "Name of new file" << '\n';
	cin >> oname;

	ofstream ofs{ oname };

	if (!ofs) error("error with file name", oname);

	for (char ch : vc)
		ofs << ch;
}

int main()
try {
	string iname{ "" };

	cout << "Name of file to convert" << '\n';
	cin >> iname;

	process_file(iname);

	return 0;
}
catch (exception& e) {
	cerr << "error occurred " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error occurred" << '\n';
	return -2;
}