#include "../../std_lib_facilities.h"

void print(string str, vector<int>& v)
{
	cout << "This is a list of " << str <<" number"<< endl;
	
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}

int main()
try {

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return 2;
}