#include "../../std_lib_facilities.h"

/* Program to solve for the roots of the quadratic equation a x^2 + b x + c = 0
*  It can only solve for real roots. 
*/

double a{ 0.0 }, b{ 0.0 }, c{ 0.0 }; // coefficients of the equation

void find_roots()
{
	double x1{ 0.0 }, x2{ 0.0 }, r{ 0.0 }; // variables for the solution of the quadratic equation

	while (cin >> a >> b >> c)
	{
		r = (b*b - 4.0 * a*c);
		// not really a quadratic but still give a solution
		if (a == 0)
		{
			if (b == 0)
				cout << "no roots\n";
			else
				cout << "The solution is " << -c / b << "\n";
		}

		// check for one solution
		else if (r == 0)
		{
			x1 = -b / 2 * a;
			cout << "The solution to your equation is x = " << x1 << "\n";
		}
		else if (r > 0 && a != 0)
		{
			x1 = (-b + sqrt(r)) / (2.0 * a);
			x2 = (-b - sqrt(r)) / (2.0 * a);
			cout << "The solutions are x = " << x1 << " and x = " << x2 << "\n";
		}

		// check for real valued solutions		
		if (r < 0)
			cout << "That equation has no real solutions\n";	

			cout << "If you have another equation to solve enter a, b and c again or ctrl-z to quit.\n";
	}
}


int main(void)
try {
		
	cout << "Enter a, b and c for the equation you would like solved it must be in the form ax^2 + bx + c = 0 or bx + c = 0\n";

	find_roots();
}
catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...)
{
	cerr << "unknown exception\n";
	return 2;
}