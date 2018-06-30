#include "money.h"

namespace Monetary {

	Money::Money()
		:cur{ USD }, cents{ 0 } { }

	Money::Money(long int c)
		: cur{ USD }, cents{ c } { }

	Money::Money(int d, int c)
	: cur{ USD }, cents{ 100 * d + c }
	{
		if (c > 99) error("cemts must be between 0 and 99", c);
	}

	Money::Money(Currency cu, long int c)
		:cur{cu}, cents{c} {}

	Money::Money(Currency cu, int d, long int c)
		:cur{cu}, cents{100 * d + c}
	{		
	}

	long int round(double cnt)
	{
		return(cnt >= 0.5) ? (cnt + 0.5) : (cnt - 0.5);
	}
	
	double exchange(Money::Currency& c1, Money::Currency c2)
	{
		
		switch(c1) {
		case Money::EUR:
			switch (c2) {
			case Money::USD:
				return .859;
			case Money::YEN:
				return 0.0077;
			default:
				error("excange(): error currency not availabe");
			}
		case Money::USD:
			switch (c2) {
			case Money::EUR:
				return 1.17;
			case Money::YEN:
				return .009;
			default:
				error("excange(): error currency not availabe");
			}		
		case Money::YEN:
			switch (c2) {
			case Money::EUR:
				return 127.89;
			case Money::USD:
				return 111.1;
			default:
				error("excange(): error currency not availabe");
			}
		default:
			error("can't convert currenecies");
			break;
		}
	}
	
	Money operator+(Money& m1, Money& m2)
	{
		double rate{ 0.0 };
		if(m1.get_currency() == m2.get_currency())
			return Money(m1.get_currency(),m1.get_cents()+m2.get_cents());
		
		Money::Currency mc1 = m1.get_currency();
		Money::Currency mc2 = m2.get_currency();

		rate = exchange(mc1, mc2);
		return Money(mc1, m1.get_cents() + round(rate*double(m2.get_cents())));
	}

	Money operator-(Money& m1, Money& m2)
	{
		double rate{ 0.0 };
		if (m1.get_currency() == m2.get_currency())
			return Money(m1.get_currency(), m1.get_cents() - m2.get_cents());

		Money::Currency mc1 = m1.get_currency();
		Money::Currency mc2 = m2.get_currency();
		
		rate = exchange(mc1, mc2);
		return Money(mc1, m1.get_cents() - round(rate*double(m2.get_cents())));
	}

	Money operator*(int n, Money& m)
	{
		Money::Currency mc = m.get_currency();
		return Money(mc, n*m.get_cents());
	}

	Money operator*(Money& m, int n)
	{
		Money::Currency mc = m.get_currency();
		return Money(mc, m.get_cents()*n);
	}

	Money operator/(Money& m, int n)
	{
		if (n == 0) error("divide by zero ", n);
		double r = double(m.get_cents())/n;
		long int cnt = round(r);
		Money::Currency mc = m.get_currency();

		return Money(mc, cnt);
	}

	istream& operator>>(istream& is,  Money& mon)
	{
		int d{ 0 }, c{ 0 };
		char ch{ 0 };
		
		is >> d >> ch >> c;
		if (!is) return is;

		if (ch != '.') {
			is.clear(ios_base::failbit);
			return is;
		}

		mon = Money(d, c);
		return is;
	}
	
	ostream& operator<<(ostream& os, Money::Currency cur)
	{
		switch (cur) {
		case Money::Currency::EUR:
			return os << "EUR ";
		case Money::Currency::USD:
			return os << "USD ";
		case Money::Currency::YEN:
			return os << "YEN ";
		default:
			error("unkown currency", cur);
		}
	}

	ostream& operator<<(ostream& os, const Money& mon)
	{
		int d = mon.get_notes();
		double c = mon.get_coins();
		if (c < 100)
			c /= 100;

		return os<<mon.get_currency() <<fixed<<setprecision(2)<< d + c;
	}	
}
