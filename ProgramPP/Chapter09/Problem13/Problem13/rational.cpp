#include "rational.h"

//----------------------------------------------------------------------------------------------------------------------------


Rational::Rational(int n, int d) 
	:num{abs(n)}, denom{abs(d)} {}

Rational::Rational(int n)
	:num{n}, denom{1} {}

Rational::Rational()
	:num{0}, denom{1} {}




// find greatest common divisor using Euclid's method for reducing
int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	
	int cf{ 0 }; // this is the common factor between the numerator and denominator if they don't have one it returns a 1.
	while (b) {
		cf = a % b;
		a = b;
		b = cf;
	}

	return a;
}

Rational reduce(Rational r3)
{
	int n{ 1 };
	if (r3.get_denom() == 0) error("divide by zero error");
	n = gcd(r3.get_numerator(), r3.get_denom());

	return Rational(r3.get_numerator() / n, r3.get_denom() / n);
}


//----------------------------------------------------------------------------------------------------------------------------


Rational operator+(const  Rational& r1, const Rational& r2)
{
	Rational r{ 1 };	
	r = Rational(r1.get_numerator()*r2.get_denom() + r2.get_numerator() * r1.get_denom(), r1.get_denom()*r2.get_denom());

	return reduce(r);
}



Rational operator-(const Rational& r1, const Rational& r2)
{
	Rational r{ 1 };
	r = Rational(r1.get_numerator()*r2.get_denom() - r2.get_numerator() * r1.get_denom(), r1.get_denom()*r2.get_denom());

	return reduce(r);
}


Rational operator*(const Rational& r1, const Rational& r2)
{
	Rational r{ 1 };
	r = Rational(r1.get_numerator()*r2.get_numerator(), r1.get_denom()*r2.get_denom());

	return reduce(r);
}


Rational operator/(const Rational& r1, const Rational& r2)
{
	Rational r{ 1 };
	r = Rational(r1.get_numerator()*r2.get_denom(), r2.get_numerator()*r1.get_denom());

	return reduce(r);
}


bool operator==(const Rational& r1, const Rational& r2)
{
	return(r1.get_numerator() == r2.get_numerator() && r1.get_denom() == r2.get_denom());
}


bool operator!=(const Rational& r1, const Rational& r2)
{
	return !(r1 == r2);
}

ostream& operator<<(ostream& os, const Rational& r)
{
	return os << r.get_numerator() << "/"<< r.get_denom();
}

//----------------------------------------------------------------------------------------------------------------------------

double convert(const Rational& n)
{
	double c{ 1 };
	c = (double)n.get_numerator() / n.get_denom();

	return c;
}