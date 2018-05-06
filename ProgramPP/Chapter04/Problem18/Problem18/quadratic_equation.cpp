#include "../../std_lib_facilities.h"

double solution_one(double a, double b, double c)
{
	double x{ 0.0 };
	x = -b + sqrt(b*b - 4.0 * a*c); // used (b + sqrt(b*b - 4.0 * a*c) / 2.0 * a) but wouldn't divided properly
	x /= 2.0 * a;
	return x;
}

double solution_two(double a, double b, double c)
{
	double x{ 0.0 };
	x = -b - sqrt((b*b - 4.0 * a*c));
	x /= 2.0 * a;
	return x;
}

int main(void)
{
	double x{ 0.0 }, y{ 0.0 }, z{ 0.0 };
	double x1{ 0.0 }, x2{ 0.0 };

	cout << "Please enter the values for a, b, and c of your quadratic equation (note: cannot solve for complex solutions)\n";

	cin >> x >> y >> z;

	if ((y*y - 4 * x*z) < 0)
	{
		cout << "This equation has complex solutions can't solve\n";
		EXIT_SUCCESS;
	}

	x1 = solution_one(x, y, z);
	x2 = solution_two(x, y, z);

	cout << "The first solution is: " << x1 << " \n";
	cout << "The second solution is: " << x2 << " \n";

	return EXIT_SUCCESS;
	
}