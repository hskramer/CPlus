#include "../../std_lib_facilities.h"

char* findx(const char* s, const char* x) {
	
	int i{ 0 }; 
	while (x[i]) {
		if (s[0] == x[i]) {
			int j{ 1 };
			while (s[j]) {
				if (s[j] == x[i+j]) {
					++j;
					if (s[j + 1] == '\0') {
						char* fx = new char[j + 1];
						for (int k = 0; k <= j + 1; ++k)
							fx[k] = s[k];
						return fx;					
					}
				}
				else
					break;
			}
		}
		++i;
	}
	return nullptr;	
}

int main()
try {

	char s1[] { "find the first string in this string." };
	char find[] { "fir" };

	int i{ 0 };
	while (find[i]) {
		++i;
	}
	char* f = new char[i + 1];

	 f = findx(find, s1);
	 if (!f)
		 cout << "String not found" << endl;
	 else
		 cout << "Found the first occurance of: " << f << endl;
	//delete f; throws assertion error. 

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}