#include "../../std_lib_facilities.h"

void list_lines(const string& iname)
{
	ifstream ifs{ iname };
	string line{ "" }, word{ "" };
	int line_num{ 0 };
	
	cout << "Word you are looking for ?" << '\n';
	cin >> word;

	while (getline(ifs, line)) {
		++line_num;
		stringstream ss{ line };
		for (string s; ss >> s;) {
			if (s == word)
				cout << line << " line number: " << line_num << '\n';
		}
	}
}

int main()
try {
	string name{ "" };

	cout << "Name of file" << '\n';
	cin >> name;

	list_lines(name.c_str());
}
catch (exception& e) {
	cerr << "error occurred " << e.what() << '\n';
	return - 1;
}
catch (...) {
	cerr << "unkown error ocurred" << '\n';
	return -2;
}