#include "../../std_lib_facilities.h"

double celsius_to_kelvin(double c)
{
	if (c < -273.15)
	{
		error("Below absolute zero can't convert.\n");
		return EXIT_FAILURE;
	}

	double kelvin = c + 273.15;

	return kelvin;
}

double kelvin_to_celsius(double k)
{
	if (k < 0)
	{
		error("Below absolute zero can't convert.\n");
		return	EXIT_FAILURE;
	}

	double celsius = k - 273.15;

	return celsius;
}

int main(void)
try {

	double cel{ 0.0 }, kel{ 0.0 }, temp{ 0.0 };
	char kc{ 'c' };

	cout << "Enter 'C' to convert Celsius to Kelvin or 'K' for Kelvin to Celsius.\n";
	cin >> kc;
	while (kc != 'C' && kc != 'K')
	{
		cout << "Invalid input.\n";
		cin >> kc;
	}

	cout << "Enter temperature.\n";
	cin >> temp;

	if (kc == 'K')
	{
		cel = kelvin_to_celsius(temp);
		if (cel == -273.15)
			cout << temp << " Kelvin is " << cel << " Celsius also known as absolute zero.\n";
		else
			cout << temp << " Kelvin is " << cel << " Celsius.\n";
	}

	if (kc == 'C')
	{
		kel = celsius_to_kelvin(temp);
		if (kel == 0)
			cout << temp << " Celsius is " << kel << " Kelvin also known as absolute zero.\n";
		else
			cout << temp << " Celsius is " << kel << " Kelvin.\n";
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