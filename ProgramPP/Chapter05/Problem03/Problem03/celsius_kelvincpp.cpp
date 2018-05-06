#include "../../std_lib_facilities.h"

double celsius_to_kelvin(double c)
{
	double kelvin = c + 273.15  ;

	return kelvin;
}

int main(void)
try {
	double celsius{ 0.0 }, ctok{ -500.0 };
	
	cout << "Enter the value in celsius you want converted to kelvin.\n";
	cin >> celsius;

	if (celsius < -273.15)
	{
		error("Below absolute zero can't convert.\n");
		return EXIT_FAILURE;
	}

	ctok = celsius_to_kelvin(celsius);

	if (ctok == 0)
		cout << celsius << " Celsius is absolute zero or " << ctok << " Kelvin\n";
	else
		cout << celsius << " Celsius is " << ctok << " Kelvin.\n";

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