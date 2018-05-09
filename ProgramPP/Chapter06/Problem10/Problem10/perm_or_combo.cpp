#include "../../std_lib_facilities.h"

long long int factorial(long long int d)
{
	long long int fac = d;

	if (fac < 0)
		error("factorial for negatives not defined");
	else if (fac > 21)
		error("number to large");
	else if (fac == 0)
		return 1;
	else {
		for (int i = 0; i < d - 1; ++i)
			fac *= (i + 1);
		return fac;
	}
}

long long int permutation(long long int a, long long int b)
{
	long long int p{ 0 };

	if ((a - b) < 0)
		error("a must be larger than b");

	p = factorial(a) / factorial(a - b);

	return p;
}

long long int combination(long long int a1, long long int b1)
{
	long long int p1{ 0 }, c{ 0 };

	p1 = permutation(a1, b1);

	c = p1 / factorial(b1);

	return c;
}

int main()
try {
	
	long long int p{ 0 }, c{ 0 }; // used in the calculations
	long long int x{ 0 }, y{ 0 }; // used for input
	char pc{ 0 };

	
	cout << "This program takes two numbers and computes either a permutation, combination or both its your choice.\n";
	cout << "Please enter your two numbers enter the largest number first.\n";
	cin >> x >> y;
	cout << "Please enter p for permutation, c for combination or b for both.\n";
	cin >> pc;

	switch (pc)
	{
	case 'p':
		p = permutation(x, y);
		cout << "The permutation of " << x << " and " << y << " is: " << p << "\n";
		break;
	case 'c':
		c = combination(x, y);
		cout << "The combination of " << x << " and " << y << " is: " << c << "\n";
		break;
	case 'b':
		p = permutation(x, y);
		cout << "The permutation of " << x << " and " << y << " is: " << p << "\n";
		c = combination(x, y);
		cout << "The combination of " << x << " and " << y << " is: " << c << "\n";
		break;
	default:
		cout << "Invalid input\n";
		break;
	}

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