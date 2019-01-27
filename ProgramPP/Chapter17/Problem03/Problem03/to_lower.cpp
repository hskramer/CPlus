#include "../../std_lib_facilities.h"

void to_lower(char* s) {

	if (*s > 64 && *s < 91)
		*s += 32;
}

int main()
try {

	char lower [] = "Hello World!" ;

	cout << "String befor to_lower()" <<endl;
	cout << lower << endl;

	char* cp = new char; int i{ 0 };
	while(lower[i]){ // one way
		cp = &lower[i];
		to_lower(cp);
		++i;
	}
//	to_lower(lower);  better way
	cout << "String after to_lower()" << endl;
	cout << lower << endl;

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}