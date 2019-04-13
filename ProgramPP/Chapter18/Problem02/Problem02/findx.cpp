#include <iostream>

// must be an easier way to do this but I just wanted to make this work

char* findx(const char* s, const char* x) {

	int n{ 0 }, l{ 0 };
	const char *p = s, *f = x;

	while (*s++) l++; 		// length of string used in for..loop
	s -= (l + 1);

	while (*f++) n++; 		// length of word see I can create memory and return a pointer to it for printing/ Help match
	f -= (n + 1);
	char *ch = nullptr;

	for (int i = 0; i < l; ++i) {
		while (*s++ != *f) { 		 //this stops when the fist char matches not the string so
			if (*s == '\0') return ch;
			++l;             			// keep track of where we are in the string		
		}

		*s--;			// move s back to match f
		int m{ 0 };
		while (*s++ == *f++ && m <= l) { 		// this continues checking for a word match when the above loop stops on fisrt char match
			++m;
			if (m == n) {					 // first char already matched
				ch = const_cast<char*>(x);
				return ch;
			}
		}
	}
}

int main()
try {

	char st[]{ "Is there a the book in this string?" };
	char fnd[]{ "book" };

	char *p = findx(st, fnd);
	if (p == nullptr)
		std::cout << "word not found in the string" << std::endl;
	else
		std::cout << "Found word: " << fnd << " in string: " << st << std::endl;

	return 0;
}
catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
}