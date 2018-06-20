#ifndef	CHRONO_H
#define CHRONE_H

namespace Chrono {

	class Date {
	public:
		enum Month {
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};

		class Invalid{};		// to throw as exception

		Date(int y, Month m, int d); // check for valid date and initialize
		Date();
		Month month() { return m; }
		int day() { return d; }
		int year() { return y; }
	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Date::Month m, int d);	// true for valid date
}

#endif

