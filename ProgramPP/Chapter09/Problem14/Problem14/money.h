#ifndef MONEY_H
#define MONEY_H

#include "../../std_lib_facilities.h"

namespace Monetary {

	class Money {
	public:
		enum Currency {
			USD, EUR, YEN // major trading partners and allies screw China
		};

		Money();
		Money(long int cent);
		Money(int d, int cent);
		Money(Currency cur, long int cent);		
		Money(Currency cur, int d, long int cent);
					

		// nonmodifying gets
		int get_coins() const { return cents % 100; }
		//Currency get_currency() const { return cur; }
		int get_notes() const { return cents / 100; } // using neutral terms common to all countries instead of dollars/cents
		long int get_cents() const { return cents; } // need access the private variable cent better that making it public and only used in implentation
		Money::Currency get_currency() const { return cur; }
	private:
		long int cents;
		Currency cur;
	};

	long int round(double dol);
	
	Money operator+(Money& m1, Money& m2);
	Money operator-(Money& m1, Money& m2);
	Money operator*(int n, Money& m1); // * operator requires two definitions one for int befor Money and after
	Money operator*(Money& m1, int n);
	Money operator/(Money& m, int n);

	istream& operator>>(istream& is, Money& mon);
	ostream& operator<<(ostream& os, const Money& mon);
}
#endif