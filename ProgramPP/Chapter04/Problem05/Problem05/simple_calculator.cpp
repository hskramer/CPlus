#include "../../std_lib_facilities.h"

int main(void)
{
	double val1{ 0.0 }, val2{ 0.0 };
	char op{ 0 };

	cout << "This is a simple calculator enter two numbers followed by an operation (+, -, *, /, ctrl-z to quit) \n";

	while (cin >> val1 >> val2 >> op)
	{

		switch (op)
		{
		case '+':
			cout <<"the sum is : "<< val1 + val2<<"\n";
			break;
		case '-':
			cout <<"the difference is : "<< val1 - val2<<"\n";
			break;
		case'*':
			cout <<"the product is : "<< val1 * val2<<"\n";
			break;
		case '/':
			if (val2 == 0)
			{
				cout << "can't divide by zero\n";
				break;
			}
			else
				cout <<val1<<" divided by "<<val2<<" is  : "<< val1 / val2<<"\n";
			break;
		default:
			cout << "Sorry I don't know that operation";
			break;
		}
	}

	return 0;
}