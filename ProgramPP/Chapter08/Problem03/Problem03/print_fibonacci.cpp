#include "../../std_lib_facilities.h"

void print(const string& str, vector<int>& v)
{
	cout << "This is a list of " << str << " numbers" << endl;

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] <<endl;
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	if (n < 0) error("n must be a positive number", n);

	v.push_back(x); 	
	v.push_back(y);
	for (int i = 0; i < n; ++i) 	
		v.push_back(v[i] + v[i + 1]);	
}

int main()
try {
	vector<int>fib;

	fibonacci(1, 2, fib, 43);
	print("fibonacci", fib);

	return 1;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return 2;
}