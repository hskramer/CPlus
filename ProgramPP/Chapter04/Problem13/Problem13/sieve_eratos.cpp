#include "../../std_lib_facilities.h"

vector<int>sieve;

void intialize_sieve()
{
	for (int i = 0; i <= 100; ++i)
		sieve.push_back(true);
}

void print_primes()
{
	for (int i = 2; i <= 100; ++i)
	{
		if (sieve[i])
			cout << i << '\n';
	}
}

int main(void)
{
	int j{ 0 };
	intialize_sieve();

	for (int i = 2; i <= 10; ++i)
	{		
		if (sieve[i])
		{			
			for (int k = 0; k <= 50; ++k)
			{
				j = i * i + k * i;
				if (j >= sieve.size())
					break;
				else
					sieve[j] = false;
			}
		}
	}

	print_primes();

	return EXIT_SUCCESS;		
}