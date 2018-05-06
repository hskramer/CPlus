#include "../../std_lib_facilities.h"

vector<int> primes = { 2 };   

void is_prime(int x)   // never thought of returning a bool
{
	for (int i = 0; i < primes.size(); ++i)
		if (x % primes[i] == 0)
			return;
		
	primes.push_back(x);
	return;	
}

int main(void)
{
	

	for (int i = 3; i < 100; ++i)
		is_prime(i);

	cout << "List of prime from two through one-hundred\n";
	for (int& p : primes)
	{
		cout << p << "\n";
	}
	
	return EXIT_SUCCESS;
}
	