#include "../../std_lib_facilities.h"

int main(void)
{
	vector<string>numbers{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int digit;

	cout << "Enter any digit between 0 and 9 (crtl-z to quit)\n";

	while (cin >> digit)
	{
		switch (digit)
		{
		case 0:
			cout << numbers[digit] << '\n';
			break;
		case 1:
			cout << numbers[digit] << '\n';
			break;
		case 2:
			cout << numbers[digit] << '\n';
			break;
		case 3:
			cout << numbers[digit] << '\n';
			break;
		case 4:
			cout << numbers[digit] << '\n';
			break;
		case 5:
			cout << numbers[digit] << '\n';
			break;
		case 6:
			cout << numbers[digit] << '\n';
			break;
		case 7:
			cout << numbers[digit] << '\n';
			break;
		case 8:
			cout << numbers[digit] << '\n';
			break;
		case 9:
			cout << numbers[digit] << '\n';
			break;
		default: cout << "Sorry I'm not familiar with that digit\n";
			break;
		}
	}

	return 0;
}