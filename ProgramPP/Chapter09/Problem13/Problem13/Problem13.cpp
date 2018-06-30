#include "rational.h"

// it only supports positive values if a negative is entered its conveted to a positive

int main()
try {

	Rational a{13, 20}, b{ 1,4 }, c{ 0,1 };
	c = a + b;	
	cout <<(a)<<" + "<<(b)<<" = "<< (c) << endl;

	c = a - b;
	cout << (a) << " - " << (b) << " = " << (c) << endl;

	Rational m1{ 2,5 }, m2{ 3,8 };
	c = m1 * m2;
	cout << (m1) << " * " << (m2) << " = " << (c) << endl;

	Rational d1{ 5,8 }, d2{ 4,5 };
	c = d1 / d2;
	cout << (d1) << " / " << (d2) << " = " << (c) << endl;
	
	double result = convert(c);

	cout << "The result is approximately "<<result<<endl;

	Rational x{ 11,13 }, y{ 11,13 };
	if (x == y)
		cout<<"x is equal to y" << endl;
		
	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	return 2;
}
catch (...) {
	cerr << "unkown exception occured\n";
}