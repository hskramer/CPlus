#include "Chrono.h"

namespace Chrono {

	Date::Date(int yy, Month mm, int dd)
		:y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	Date::Date() // defualt constructor choice unix epoch 0
		: y{ 1970 }, m{ Month::jan }, d{ 1 }
	{
	}
		
	bool is_date(int y, Date::Month m, int d)
	{
		if (d <= 0) return false;
		
		if (m < Date::jan || Date::dec < m) return false;

		int days_in_month = 31;

		switch (m) {
		case Date::feb:
			days_in_month = 28; // will add leapyear when I do problem 10
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			days_in_month = 30;
			break;
		}

		if (days_in_month < d) return false;

		return true;
	}
}


