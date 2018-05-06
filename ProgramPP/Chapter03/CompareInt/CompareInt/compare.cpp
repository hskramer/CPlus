#include "std_lib_facilities.h"

int main(void)
{
	int a{ 0 };
	int b{ 0 };
	int c{ 0 };
	int tmp{ 0 };

	cout << "Please enter three numbers\n";
	cin >> a >> b >> c;
	
	if (b < a)
	{ 
		tmp = b;
		b = a;
		a = tmp;
	}

	if (c < b)
	{
		tmp = c;
		c = b;
		b = tmp;
	}

	if (b < a)
	{
		tmp = b;
		b = a;
		a = tmp;
	}



		
	cout << " a, b, c in numerical order\n" << a << ", " << b << ", " << c;

	return 0;
	
}