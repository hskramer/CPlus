#include "../../std_lib_facilities.h"

// found article that explains all my problems vs2017 Fundamental Types (C++) 11/03/2016
// char, signed char, unsigned char are promoted to type int. So on any win64 os that is 8 bytes.
// this explains why the size of my array was alway 8 plus num chars + \0 and why delete[] throws assertion errors 

char* extend(char* s, int n) {

	cout << "s size: " << sizeof(s) << '\n';
	int i{ 0 };
	while (s[i] != '\0')
		i++;

	char* ch_arr = new char[i + n + 1]; 
	for (int j = 0; s[j]; ++j) //number of chars 
		ch_arr[j] = s[j];
	ch_arr[i + n + 1] = '\0';
//	delete[] s;

	return ch_arr;
}

int main()
try {

	int i{ 0 };
	char* p = new char['\0']; char ch{ 0 };
	//*p = '\0';
	cout << "size of p" << sizeof(p) << '\n';
	cout << "p address: " << &p << '\n';
	cout << "Please input a string enter ! to stop" << '\n';
	// this should work if char is one byte.
	while (cin.get(ch) && ch != '!') {
		p = extend(p, 8);  // p hold 8 chars before needed to be increased it will then hold 8 more.
		++i;			  // if only increased by 1 delete throws error
		p[i-1] = ch;
	}
		
	int j{ 0 };
	while (p[j] != '\0') {
		cout << p[j];
		++j;
	}
	cout << '\n';
//	delete[] p;
	return 0;
}		
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}