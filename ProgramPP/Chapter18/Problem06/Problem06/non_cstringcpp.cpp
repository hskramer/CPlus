#include <iostream>
#include <string>

// Release build runs fine the compiler must be making changes

char* my_strdup(const char* s, int max_len = 64) {

	int n{ 0 };
	const char *p = s;
	while (*p++) n++; // get string length
	if (n > max_len)
		n = max_len;

	char *ch_p = new char[n + 1];

	while (*s) 	*ch_p++ = *s++;
	ch_p -= n;
	return ch_p;
}

int str_cmp(const char* s1, const char* s2, int max_len = 64) {
	while (*s1 && *s2) {
		if (*s1 < *s2)
			return -1;
		else if (*s2 < *s1)
			return 1;
		*++s1, *++s2;
	}
	return 0;
}

char* findx(const char* s, const char* x, int max_len = 64) {

	int n{ 0 }, l{ 0 };
	const char *p = s, *f = x;

	while (*s++) l++; 		// length of string used in for..loop
	if (l > max_len) l = max_len;
	s -= (l + 1);

	while (*f++) n++; 		// length of word so I can allocate memory and return a pointer to it for printing
	f -= (n + 1);
	char *ch = nullptr;

	for (int i = 0; i < l; ++i) {
		while (*s++ != *f) { 		 //this stops when the fist char matches
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
	return nullptr;
}


void test_one() {

	char* s1 = new char[12];
	char* s2 = new char[12];

	char st1[] = { 'n', 'o', 'n','-', 'C','-', 's', 't', 'r', 'i', 'n', 'g' };
	char st2[] = { 'n', 'o', 'n','-', 'C','-', 's', 't', 'r', 'i', 'n', 'g' };

	const char *s = new char[7];
	s = "non";

	int n{ 0 };
	while (n < 12) {
		s1[n] = st1[n];
		s2[n] = st2[n];
		++n;
	}

	char* dup = my_strdup(s1, 12);
	std::cout << "Original: " << s1 << "Duplicate: " << dup << std::endl; // prints string followed by garbage 

	char *p = findx(st1, s, 12); // It never matched a word so I made st1 null terminated to make sure it was working 									
	if (p == nullptr)			 // and it found the word every time
		std::cout << "word not found in the string" << std::endl;
	else
		std::cout << "Found word: " << s << " in string: " << st1 << std::endl;


	int cmp = str_cmp(s1, s2, 12);
	std::cout << "String compare: " << s1 << " " << s2 << "should be zero: " << cmp << std::endl; // prints garbage after each string

	delete[] s1;
	delete[] s2;
	//delete[] s; //can't delete heap coruption

}

void test_two() {


	char st1[] = { "non-C-string" };
	char st2[] = { "non-C-string" };
	char s[] = { "string" };

	char* dup = my_strdup(st1, 12);
	std::cout << "Original: " << st1 << "Duplicate: " << dup << std::endl;

	char *p = findx(st1, s, 12);
	if (p == nullptr)
		std::cout << "word not found in the string" << std::endl; // sometimes it finds the word other times not 
	else
		std::cout << "Found word: " << s << " in string: " << st1 << std::endl;

	int cmp = str_cmp(st1, st2, 12);
	std::cout << "String compare: " << st1 << " " << st2 << "should be zero: " << cmp << std::endl;

}

int main()
try {

	test_one();

	std::cout << "Start of test two\n";

	test_two();

	return 0;
}
catch (std::exception& e) {

	std::cout << "error: " << e.what() << '\n';
	return 1;
}