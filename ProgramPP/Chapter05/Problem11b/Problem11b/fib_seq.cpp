#include "../../std_lib_facilities.h"

// using long long integers will work upto the ninety-third fibonacci number

int main()
try {
	int n{ -1 };
	vector<long long int>fibsequence;
	// start with first two numbers in the fibonacci sequence
	fibsequence.push_back(0);
	fibsequence.push_back(1);

	cout << "Enter how many fibonacci numbers you want, note the forty-seventh is the largest I can print.\n";
	cin >> n;

	//if (n > 47)
	//	error("overflow");

	long long int fib1{ 1 }, fib2{ -1 }; // variable to hold intermediate values
	for (int i = 0; i < n; ++i) {
		fib1 = fibsequence[i];
		fib2 = fibsequence[i + 1];
		fibsequence.push_back(fib1 + fib2);
	}

	for (int j = 0; j < n; ++j)
		cout <<fibsequence[j] <<" ";

}
catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...)
{
	cerr << "unkown exception\n";
	return 2;
}