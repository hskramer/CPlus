#include "../../std_lib_facilities.h"



int main(void)
{
	int n{ 0 }, count{ 0 }, c{ 0 }, i{ 3 };

	cout << "Enter the a number of prime numbers you want.\n";
	cin >> n;
	
	cout << "The first " << n << " primes are: ";
	cout << "2";

	for (count = 2; count <= n;)
	{
		for (c = 2; c <= i - 1; ++c)
		{
			if (i % c == 0)
				break;
		}
		if (c == i)
		{
			cout << ", "<<i;
			++count;
		}
		++i;
	}

	return EXIT_SUCCESS;

}