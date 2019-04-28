#include "../../std_lib_facilities.h"

std::string cat_dot(const string& s1, const string& s2) {

	return s1 + '.' + s2;
}

int main()
try {

	string st1{ "Niels" }, st2{ "Bohr" };

	string s = cat_dot(st1, st2);

	cout <<"New string: "<<s<< endl;	

	return 0;
}
catch (std::exception& e) {

	std::cerr << "error: " << e.what() << '\n';
	return 1;
}