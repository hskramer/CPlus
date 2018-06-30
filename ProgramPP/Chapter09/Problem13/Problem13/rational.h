#include "../../std_lib_facilities.h"

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
	Rational(int num, int denom);
	Rational(int num);
	Rational();

	//nonmodifying operations
	int get_numerator() const { return num; }
	int get_denom() const { return denom; }

private:
	int num;
	int denom;
};

Rational reduce(Rational r3);

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

ostream& operator<<(ostream& os, const Rational& r);

bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

double convert(const Rational& n);

#endif