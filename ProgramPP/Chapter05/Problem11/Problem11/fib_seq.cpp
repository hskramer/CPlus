#include "../../std_lib_facilities.h"

// Simple non recursive program to print the fibonacci sequence. According to Wikipedia starting with 0 is the modern starting term


int main()
try {
	int n{ -1 };
	vector<int>fibsequence;
	// start with first two numbers in the fibonacci sequence
	fibsequence.push_back(0);
	fibsequence.push_back(1);

	cout << "Enter how many fibonacci numbers you want, note the forty-seventh is the largest I can print.\n";
	cin >> n;

	if (n > 47)
		error("overflow");

	int fib1{ -1 }, fib2{ -1 }; // variable to hold intermediate values
	for (int i = 0; i < n; ++i) {
		fib1 = fibsequence[i];
		fib2 = fibsequence[i + 1];
		fibsequence.push_back(fib1 + fib2);
	}
	
	for (int j = 0; j < n; ++j)
		cout << fibsequence[j] << " ";


}
catch (exception& e)
{
	cerr << "error: " << e.what() <<"\n";
	return 1;
}
catch (...)
{
	cerr << "unkown exception\n";
	return 2;
}