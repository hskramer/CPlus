#include "../../std_lib_facilities.h"

int fact1(int n) { return n > 1 ? n * fact1(n - 1) : 1; }

int fact2(int n) {

	int r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}

int main()
try {

	cout << "Factorial recursive results" << endl;
	for (int i = 0; i <= 20; ++i) {
		cout << fact1(i) << endl;
	}

	cout << "Factorial iterative results" << endl;
	for (int j = 0; j <= 20; ++j) {
		cout << fact2(j) << endl;
	}

	return 0; 

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}