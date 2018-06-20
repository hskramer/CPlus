#include "../../std_lib_facilities.h"

// Month needs to be accessed and used outside of the Date class unlike Genre so declare it as an enum class outside of Date


enum class  Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day {
	sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

class Date {
public:
	Date(int y, Month m, int d);
	Date();

	// nonmodifying operations
	int day() const { return d; }
	Month month() const { return m; }
	int year() const { return y; }

	//modifying operations
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

private:
	int y;
	Month m;
	int d;
};

bool is_date(int y, Month m, int d); // true for valid date
bool leapyear(int y);

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(ostream& is, Date& dd);

int days_in_month(int y, Month m);

Date next_sunday(const Date& d); // next Sunday after d
Date next_weekday(const Date& d); // next weekday after d
