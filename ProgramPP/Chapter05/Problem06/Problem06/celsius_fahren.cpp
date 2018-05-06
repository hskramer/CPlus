#include "../../std_lib_facilities.h"


/* Simple program for converting between Celsius and Fahrenheit
*  Decided to exit loop on below zero error for practice on catching error's
*  in a real world scenario I would have the program continue.
*/


double fahrenheit_celsius(double f)
{
	if (f < -459.67)
	{
		error("Below absolute zero can't convert.\n");
		return EXIT_FAILURE;
	}

	double celsius = (f - 32.0) * 5.0 / 9;

	return celsius;
}

double celsius_fahrenheit(double c)
{
	if (c < -273.15)
	{
		error("Below absolute zero can't convert.\n");
		return EXIT_FAILURE;
	}

	double fahren = (c * 9.0 / 5) + 32.0;

	return fahren;
}

int main(void)
try {

	double cel{ 0.0 }, fahren{ 0.0 }, temp{ 0.0 };
	char cf{ 'c' };

	cout << "Enter 'C' for Celsius to Fahrenheit or 'F' for Fahrenheit to Celsius (CTR-L Z to exit) .\n";

	while (cin >> cf)
	{
		// Check for valid input upper/lower case C or F
		if (cf != 'C' && cf != 'F')
			cout << "Error invalid input valid inputs are 'C' or 'F'\n";

		if (cf == 'C')
		{
			cout << "Enter temperature in Celsius\n";
			cin >> temp;

			fahren = celsius_fahrenheit(temp);

			if (fahren == -459.67)
			
				cout << temp << " Celsius is " << fahren << " Fahrenheit also known as absolute zero.\n";
			else
				cout << temp << " Celsius is " << fahren << " Fahrenheit.\n";			
		}

		if (cf == 'F')
		{
			cout << "Enter temperature in Fahrenheit\n";
			cin >> temp;

			cel = fahrenheit_celsius(temp);

			if(cel == -273.15)
				cout << temp << " Fahrenheit is " << cel << " Celsius also known as absolute zero.\n";
			else
				cout << temp << " Fahrenheit is " << cel << " Celsius.\n";

		}
	}

	return EXIT_SUCCESS;

}
catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...)
{
	cerr << "Unkown exception\n";
	return 2;
}

