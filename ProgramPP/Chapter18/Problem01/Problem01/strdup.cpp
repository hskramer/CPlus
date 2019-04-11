#include <iostream>


char* my_strdup(const char* s) {

	int n{ 0 };
	const char *p = s;
	while (*p++) n++; // get string length minus 1

	char *ch_p = new char [n+1]; // add 1 for c string termination \0 

	while (*s) 	*ch_p++ = *s++;  
	
	*ch_p++ = '\0'; // the while loops both end on \0 so the size increment and copy never occur
	ch_p -= (n + 1);

	return ch_p;
}

int main()
try {
	
	char ch[]{ "This is a test of strdup" };
	char *p = my_strdup(ch); // had to change name to avoid error posix require use of _strdup now

	while(*p)
		std::cout << *p++;

	return 0;
}
catch(std::exception& e){
	
	std::cerr << "error: " << e.what() << '\n';
	return 0;
}