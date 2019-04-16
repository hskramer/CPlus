#include <iostream>
#include <string>

// couldn't find any information on how strcmp handle caps so I decided to write two version one that works with caps one that doesn't
// problem03B

int cmp_cap(const char* c1, const char* c2) {
	
	if (*c1 < 91) {
		const_cast<char*>(c1);
		if (*c1 + 32 < *c2)
			return -1;
	}
	else if (*c2 < 91) {
		const_cast<char*>(c2);
		if (*c2 + 32 < *c1)
			return 1;
	}
	return 0;
}

int strcmp2(const char* s1, const char* s2) {

	int x{ 0 };

	while (*s1++ && *s2++) {
		if ((*s1 < 91 || *s2 < 91) && (*s1 != 32) && (*s2 != 32)) { // check for capitals and ignore spaces
			x = cmp_cap(s1, s2);
			if (x < 0)
				return -1;
			else if (x > 0)
				return 1;
			else
				continue;
		}
		if (*s1 < *s2) 
			return -1;
		else if(*s2 < *s1)
			return 1;		
	}
	return 0;
}

int main()
try {
	 
	int cmp{ 0 };
	char st1[]{ "test of lexigraphical order" }, st2[]{ "test of Zlexigraphical order" };

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