#include "../../std_lib_facilities.h"

/* Found a very nice article on pre/post ++ or -- and it made clear why ++i is preferred 
* ++ is really a pair of operators: pre-increment and post-increment. The former increments the value of a variable
* and returns the resulting value; the latter increments the value of the variable and returns the value prior to the increment.
* So, if a variable x initially contains the value 3, the following expressions yield different results: 
*
*  y = ++x; y==4, x==4
*  y = x++; y==3, x==4 
*/


int stringto_number(string str)
{
	vector<string>numbers{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string>digits{ "0", "1", "2", "3", "4", "5","6", "7", "8", "9" };
	double x{ 0 };
	bool found = false;

	for (int i = 0; i < numbers.size(); ++i)
		if (numbers[i] == str)
		{
			x = i;
			found = true;
		}
	
	for (int i = 0; i < digits.size(); ++i)
		if (digits[i] == str)
		{
			x = i;
			found = true;
		}

	if (!found)
	{
		cout << "Not a valid entry\n";
		return -1;
	}

	return x;
}


int main(void)
{	
	string digit1{ 0 }, digit2{ 0 };
	char op{ 0 };

	cout << "Spell or enter any digit between 'zero' and 'nine' followed by an operation (+,-,*,/ or crtl-z to quit)\n";

	while (cin >> digit1>>digit2>>op)
	{
		double num1 = stringto_number(digit1);
		double num2 = stringto_number(digit2);

		if (num1 == -1 || num2 == -1)
			break;
		
		switch (op)
		{
		case '+':
			cout << "the sum is : " << num1 + num2 << "\n";
			break;
		case '-':
			cout << "the difference is : " << num1 - num2 << "\n";
			break;
		case'*':
			cout << "the product is : " << num1 * num2 << "\n";
			break;
		case '/':
			if (num2 == 0)
			{
				cout << "can't divide by zero\n";
				break;
			}
			else
				cout << num1 << " divided by " << num2 << " is  : " << num1 / num2 << "\n";
			break;
		default:
			cout << "Sorry I don't know that operation";
			break;
		}
	}

}