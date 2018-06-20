#include "chrono.h"


	Date::Date(int yy, Month mm, int dd)
		:y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) error("Date(): invalid date entered");
	}

	const Date& default_date()
	{
		static Date dd{ 1970, Month::jan, 1 };

		return dd;
	}

	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}

	bool is_date(int y, Month m, int d)
	{
		if (y < 1970) return false; // check year assumme greater than unix epoch 0

		if (m < Month::jan || Month::dec < m) return false;	 // month must be between 1 and 12

		if (d <= 0) return false;	// days must be postive and less than 31
		if (days_in_month(y, m) < d) return false;

		return true;
	}

	void  Date::add_day(int n)
	{
		int max_days = days_in_month(y, m);
		if (d + n < 0) error("add_day(): error negative days");

		if (n + d > max_days) {
			add_month(1);
			d = 1;
		}

		d += n;
	}

	void Date::add_month(int n)
	{
		int m{ 0 };
		if (n > 0 && n < 11)
			m = (m == int(Month::dec)) ? (int(Month::jan) + n - 1) : int(Month(m)) + n;
	}

	bool leapyear(int y)
	{
		return(y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	}

	int days_in_month(int y, Month m)
	{
		switch (m)
		{
		case Month::apr: case Month::jun:case Month::sep: case Month::nov:
			return 30;

		case Month::feb:
			return leapyear(y) ? 29 : 28;

		default:
			return 31;
		}
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << "(" << d.year()
			<< "," << int(d.month())
			<< "," << d.day() << ")";
	}

	istream & operator>>(ostream & is, Date & dd)
	{
		// TODO: insert return statement here
	}

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;

		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;

		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // format error

			is.clear(ios_base::failbit); // set the fail bit

			return is;
		}

		dd = Date(y, Month(m), d);
	}

