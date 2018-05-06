#include "../../std_lib_facilities.h"

int main(void)
{
	vector<int>num;
	vector<int>counts;
	int n{ 0 }, mode{ 0 }, a{ 1 };

	cout << "Enter several numbers ctrl-z to stop\n";

	while (cin >> n)
	{
		num.push_back(n);
	}

	if (num.empty())
	{
		cout << "Error you didn't enter any numbers\n";
		return EXIT_SUCCESS;
	}

	sort(num);

	for (int i = 0; i < num.size() - 1; ++i)
	{
		if (num[i] == num[i + 1])
			++a;
		else
		{
			counts.push_back(a);
			a = 1;
		}
	}

	
	for (int j = 1; j < counts.size(); ++j)
	{		
		if (counts[mode] < counts[j])
			mode = j;	
	}

	cout << "The mode is "<<mode + 1;
	 
	return EXIT_SUCCESS;
}
