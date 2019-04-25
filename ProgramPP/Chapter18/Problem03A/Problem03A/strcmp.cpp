#include <iostream>
#include <string>

 // wrote a version B that takes capitals into account even though strcmp does not

int strcmp2(const char* s1, const char* s2) {

	while (*s1 && *s2) {
		if (*s1 < *s2)
			return -1;
		else if (*s2 < *s1)
			return 1;
		*++s1, *++s2;
	}	
	return 0;
}

int main() // they return same values tried many different variations 
try {
	 
	int cmp{ 0 };
	char st1[]{ "Test of plexigraphical order" }, st2[]{ "test of lexigraphical order" };

	cmp = strcmp2(st1, st2);

	if (cmp < 0)
		std::cout << "string 1" << std::endl;
	else if (cmp > 0)
		std::cout << "string 2" << std::endl;
	else
		std::cout << "same string" << std::endl;

	cmp = strcmp(st1, st2);
	if (cmp < 0)
		std::cout << "string 1" << std::endl;
	else if (cmp > 0)
		std::cout << "string 2" << std::endl;
	else
		std::cout << "same string" << std::endl;

		
	return 0;
}
catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
}