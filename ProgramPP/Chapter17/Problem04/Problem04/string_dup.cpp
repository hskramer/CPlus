#include "../../std_lib_facilities.h"

char* _strdup_rm(const char* cp) {
	char* dup = const_cast<char*>(cp); // easy if we remove the const
	return dup;	
}


char* _strdup(const char* cp) {

	int i{ 0 };	
	while (cp[i])
		++i;
	char* d = new char [i + 1];

	for (int j = 0; j < i; ++j)
		d[j] = cp[j];

	d[i] = '\0';

	return d;
}


int main()
try {

	char original[]{ "Duplicate this string" };
	cout << original << '\n';

//	char* dup = _strdup(original); 
//	cout << dup << '\n';

	char* dup = _strdup(original);
	cout << dup << endl;
	
	delete[] dup;

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}