#include "../../std_lib_facilities.h"

vector<int> primes = { 2 };

void is_prime(int x) 
{
	for (int i = 0; i < primes.size(); ++i)
		if (x % primes[i] == 0)
			return;

	primes.push_back(x);
	return;
}

int main(void)
{
	int p{ 0 };
	cout << "Enter the maximum value for checking primes\n";
	cin >> p;

	for (int i = 3; i < p; ++i)
		is_prime(i);

	cout << "List of prime from two through one-hundred\n";
	for (int& p : primes)
	{
		cout << p << "\n";
	}

	return EXIT_SUCCESS;
}