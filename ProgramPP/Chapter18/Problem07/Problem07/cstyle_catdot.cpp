#include "../../std_lib_facilities.h"

int str_len(const char* str) {

	int l{ 0 };
	const char* p{ str };
	while (*p) {
		++l;
		++p;
	}
	return l;
}

char* cat_dot(const char* s1, const char* s2, const char* s3) {

	int l1{ 0 }, l2{ 0 }, l3{ 0 };
	int cnt{ 0 }, len{ 0 };

	const char *p;
	
	l1 = str_len(s1);  l2 = str_len(s2); l3 = str_len(s3);
	char* c = new char( l1 + l2 + l3 + 1 );        //direct initialization introduced in C++11; 													        
	p = s1; 	p + l1; 	p = s2;   p + l2;	p = s3; // copy string jump to end and repeat
	
	char* cp = c; // need to save start address of c
	while (*p) *c++ = *p++;
	*c++ = '\0';

	return cp;
}

int main()
try {

	char st1[] = "Quantum entanglement";
	char st2[] = " and ";
	char st3[] = "the holographic universe";

	char* p = cat_dot(st1, st2, st3);

	cout <<p<< endl;

	delete[] p;

	return 0;
}
catch (exception& e) {

	cerr << "error: " << e.what() << '\n';
	return 1;
}