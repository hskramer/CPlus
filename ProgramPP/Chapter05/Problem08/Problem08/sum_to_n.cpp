#include "../../std_lib_facilities.h"

vector<int>vec;

void sum_to_n(int n)
{
	int sum{ 0 };
	if (n > vec.size())
		error("N is greater than the number of integers entered");

	for (int i = 0; i < n; ++i) 	sum += vec[i];

	cout << "The sum of the first " << n << " integers is " << sum << "\n";	
}

int main()
try {
	int a{ 0 }, N{ 0 };

	cout<< "Enter the number of values you want to sum ?\n";
	cin >> N;

	if (N < 0)
		error("negative value entered");

	cout << "Enter some integers press '|' to stop\n";
	while (cin >> a)	vec.push_back(a);

	sum_to_n(N);
}
catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}