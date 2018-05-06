#include "../../std_lib_facilities.h"

int main(void)
{
	vector<string>numbers{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string digit;

	cout << "Spell any digit between 'zero' and 'nine' (crtl-z to quit)\n";

	while (cin >> digit)
	{
		for (int i = 0; i < numbers.size(); i++)
		if (numbers[i] == digit)
				cout << i << '\n';
	}

}