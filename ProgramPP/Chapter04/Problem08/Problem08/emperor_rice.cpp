#include "../../std_lib_facilities.h"

int main(void)
{
	int square{0}, total_rice{0}, rice{1};
	int amount{ 0 };

	cout << "Enter the total grains of rice and I'll calulate the minimum number of squares required\n";
	cin>> amount;

	for (int i = 1; i < 65; ++i)
	{
		total_rice += rice;
		rice = rice * 2;
		++square;
		if (rice >= amount)
			break;
	}


	cout << "The total number of rice grains is " << total_rice <<" on square " << square;

}