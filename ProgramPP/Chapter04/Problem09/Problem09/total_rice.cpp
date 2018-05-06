#include "../../std_lib_facilities.h"


int main(void)
{
	int total_rice{ 0 }, rice{ 1};
	double dbltotal_rice{ 0.0 }, dblrice{ 1.0 };

	for (int i = 1; i < 32; ++i)
	{
		total_rice += rice;	
		rice = rice * 2;
	}

	cout << "The largest a type int can hold " << total_rice << " this would be the thirty-first square\n";

	for (int i = 1; i < 63; ++i)
	{
		dbltotal_rice += dblrice;
		dblrice = dblrice * 2;
	}

	cout << "The lagest a type double can hold on a 64-bit machine are much larger then most practical problems require";
}