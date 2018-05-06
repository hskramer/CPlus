#include "std_lib_facilities.h"

int main(void)
{
	constexpr  double kroner_dollar{ 0.1652 };
	constexpr  double yen_dollar{ 0.00936 };
	constexpr  double pound_dollar{ 1.39 };
	char convert{ ' ' };
	double amount{ 0 };

	cout << "Please enter the amount followed by y for yen, p for pound or k for kroner\n";
	cin >> amount >> convert;

	if (convert == 'y')
		cout << yen_dollar << " Yen is equal to " << amount * yen_dollar << " dollars\n";

	else if (convert == 'p')
		cout << pound_dollar << " pounds is equal to " << amount * pound_dollar << " dollars\n";

	else if (convert == 'k')
		cout << kroner_dollar << " kroner is equal to " << amount * kroner_dollar << " dollars\n";

	else
		cout << "I don't recognize that currency\n";

	return 0;
	
}