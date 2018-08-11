#include "../../std_lib_facilities.h"

vector<string> split(const string& s)
{
	istringstream is{ s };
	
	vector<string>substr;
	string ss{ "" };

	while (is >> ss) 
		substr.push_back(ss);	

	return substr;
}

void print_vec(vector<string>& str)
{
	for (int i = 0; i < str.size(); ++i)
		cout << str[i] << '\n';
	cout << endl;
}

int main()
try {

	vector<string> st;
	string str{ "" };
	cout << "Enter a line of text\n";

	while (getline(cin, str)) {
			st = split(str);
			print_vec(st);
			cout << "Enter another line:\n";
	}

	

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkkown error\n";
	return -2;
}