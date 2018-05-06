#include "../../std_lib_facilities.h"

vector<int>sieve;

void intialize_sieve(int m)
{
	for (int i = 0; i <= m; ++i)
		sieve.push_back(true);
}

void print_primes(int m)
{
	for (int i = 2; i <= m; ++i)
	{
		if (sieve[i])
			cout << i << '\n';
	}
}

// simple babylonian method for finding approximate sqrt
double approx_sqrt(double x)
{
	double rt = x;

	while((rt - x / rt) > 0.0001)
	{
		rt = (rt + x / rt) / 2;
	}
	return rt;

}

int main(void)
{
	int j{ 0 }, max{ 0 };
	int sqrt{ 0 };

	cout << "Enter the maxium number to check for primes\n";
	cin>>max;
	cout << "\n The list of primes below " << max << " is\n";

	intialize_sieve(max);
	sqrt = approx_sqrt(max); // loss of precision not important for this problem


	// only need to check numbers 2 through its square root
	for (int i = 2; i <= sqrt; ++i)
	{
		if (sieve[i])
		{
			for (int k = 0; k <= max /2; ++k)
			{
				j = i * i + k * i;
				if (j >= sieve.size())
					break;
				else
					sieve[j] = false;
			}
		}
	}

	print_primes(max);

	return EXIT_SUCCESS;

}