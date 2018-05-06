#include "std_lib_facilities.h"


int main(void)
{
	float	miles{ 0 };
	float	km{ 0 };

	cout << "Enter miles \n";
	cin >> miles;
	km = miles * 1.609;
	cout << "That is eqaul to " << km << " kilometers\n";

	return 0;

}