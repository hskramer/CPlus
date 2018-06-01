#include "../../std_lib_facilities.h"

void reverse_vs1(const vector<string>& vs) {
	
	vector<string>rev_str;

	for (int i = vs.size() - 1; i >= 0; --i)
		rev_str.push_back(vs[i]);

	for(int j = 0; j < rev_str.size(); ++j)
		cout << rev_str[j]<<endl;
}

void reverse_vs2(vector<string>& vs2) {

	for (int i = 0; i < vs2.size() / 2; ++i)
		swap(vs2[i], vs2[vs2.size() - 1 - i]);

	for (int j = 0; j < vs2.size(); ++j)
		cout << vs2[j]<<endl;
}

int main()
try {

	vector<string>str;
	str.push_back("The"); str.push_back("house"); str.push_back("is"); str.push_back("red");

	reverse_vs1(str);
	reverse_vs2(str);
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}