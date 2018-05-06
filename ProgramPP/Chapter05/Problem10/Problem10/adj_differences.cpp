#include "../../std_lib_facilities.h"

void sum_to_n(vector<double> v, int m)
{
	double sum{ 0.0 };
	if (m > v.size())
		error("N is greater than the numbers you entered");

	for (int i = 0; i < m; ++i)	 sum += v[i];
	cout << "The sum of the first " << m << " elements is " << sum<<"\n";

	return;
}

void diff_adjacent(vector<double> v)
{
	vector<double> diffadj;	
	for (int i = 0; i < v.size() - 1; ++i)	 diffadj.push_back(v[i] - v[i + 1]);

	cout << "The difference between adjacent elements is\n";
	for (int j = 0; j < diffadj.size(); ++j)
		cout << diffadj[j] << "\n";

	return;
}

int main()
try {
	vector<double>vec;
	double a{ 0.0 };
	int n{ 0 };

	cout << "Enter the number of values to sum '|' to stop\n";
	cin >> n;

	while (cin >> a)  vec.push_back(a);

	sum_to_n(vec, n);

	diff_adjacent(vec);
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