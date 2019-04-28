#include "../../std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2, const string& s3) {

	return s1  + s2  + s3;
}

int main()
try {

	string st1{ "Quantum entanglement " };	string st2{ "saved" }; string st3{ " thanks to two quasars" };

	string catdot = cat_dot(st1, st2, st3);
	cout << catdot << endl;

	return 0;
}
catch (exception& e) {

	cerr << "error: " << e.what() << '\n';
	return 1;
}