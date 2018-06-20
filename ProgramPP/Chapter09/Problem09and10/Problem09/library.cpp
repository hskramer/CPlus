#include "library.h"


namespace Lib {

//--------------------------------------------------------------------------------------------------------------------------
	// constuctors and functions for Book class

	Book::Book(string isbn, string ti, string auth, Genre gen, int cpyr, bool chk)  // constructor		
		:isbn{ isbn }, ti{ ti }, auth{ auth }, gen{ gen }, cpyr{ cpyr }, chkd{ chk } // initializers 
	{
		if (!is_isbn(isbn)) error("Book ISBN already in use", isbn);
		if (cpyr < 1850 || 2070 < cpyr) error("Bad copy right date", cpyr);		// allowing the library to add new books for 50+ years
	}

	Book::Book()
		:isbn{ "" }, ti{ "" }, auth{ "" }, gen{}, cpyr{}
	{
	}


	string genre_name(const Book& b)
	{
		switch (b.get_genre())
		{
		case 0:
			return "fiction";
		case 1:
			return "nonfiction";
		case 2:
			return "periodical";
		case 3:
			return "biography";
		case 4:
			return "children";
		default:
			cout << "genre not found" << endl;
			break;
		}
	}

	bool is_isbn(string ib) { // decided I wanted the ISBN numbers to be more than one digit so I settled on this after many attempts
	bool is{ true };	 // at trying  to have legitimate isbn numbers wich can have 6 or more digits this at least allows for three with one restriction
	int n1{ 0 };		// if n > 254 ctype throws an assert error if I use stol isdigit fails. Learned a lot, real world I would use a struct.
	int pos{ 0 };
	char x{ '-' };
	string integer{ " " };

	while (ib.length() > 2) {
		pos = ib.find(x);
		integer = ib.substr(0, pos);
		ib.erase(0, pos + 1);
		n1 = stoi(integer);
		if (n1 - n1 == 0 && to_string(n1).length() == integer.length()) // throws an error if first char is not an integer
			is = true;
		else
			return false;
	}
		n1 = stoi(integer);
	if (isalpha(n1) || isdigit(n1))
		is = true;
	else
		is = false;

		return is;
	}

	bool operator==(const Book& a, const Book& b)  // compare two books for equal ISBN's
	{
		return a.get_isbn() == b.get_isbn();
	}

	bool operator!=(const Book& a, const Book& b)
	{
		return !(a.get_isbn() == b.get_isbn());
	}

	ostream& operator<<(ostream& os, const Book& b)
	{
		return os << "Title:  " << b.get_title() << "\n"
			<< "Author: " << b.get_author() << "\n"
			<< "ISBN:   " << b.get_isbn() << endl;
	}
	

//--------------------------------------------------------------------------------------------------------------------------

	// constructor and functions for Patron class

	Patron::Patron(string nm, int lcard, double fee)
		:uname{ nm }, libcard{ lcard }, fees{ fee }
	{
	}
	Patron::Patron()
		: uname{ "" }, libcard{ -1 }, fees(0.)
	{
	}

	void Patron::set_fee(double f)
	{
		if (fees < 0) error("setUserFee(): error fee less than zero");
		fees = f;
	}

	bool owe_fees(const Patron& p)
	{
		return p.get_fees() > 0;
	}

	bool operator==(const Patron& a, const Patron& b)
	{
		return (a.get_fees() == b.get_libcard());
	}

	bool operator!=(const Patron& a, const Patron& b)
	{
		return !(a == b);
	}

//--------------------------------------------------------------------------------------------------------------------------


	// constructor and functions for Date class

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

		if (d + n > max_days){
			switch (max_days) {
			case 31:
				add_month(1);
				d += n - 1;
				break;
			case 30:
				add_month(1);
				d += n;
				break;
			case 29:
				add_month(1);
				d += n + 1;
				break;
			case 28:
				add_month(1);
				d += n + 2;
				break;
			default:
				cout << "Too many days try adding a month first" << endl;
				break;
			}			
		}		
	}

	void Date::add_month(int n)
	{
		int m{ 0 };
		if (n < 0) error("add_month(): negative value", n);

		if (n > 0 && n < 11)
			m = (m == int(Month::dec)) ? (int(Month::jan) + n - 1) : int(Month(m)) + n;
	}

	void Date::add_year(int n)
	{
		if (n < 0) error("add_year(): negative value", n);


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


//--------------------------------------------------------------------------------------------------------------------------

	Library::Library(vector<Book> b, vector<Patron> p, vector<Transaction> t)
		:books{ b }, patrons{ p }, trans{ t }
	{

	}

	Library::Library()
	{
	}

	Library::Transaction::Transaction(Book bb, Patron pp, Date dd)
	{
	}

	void Library::check_out()
	{
		if (chkd) cout << "check_out(): book is already checked out" << endl;
		chkd = true;
	}

	void Library::check_in()
	{
		if (!chkd) cout << "check_in(): book is already checked in" << endl;
		chkd = false;
	}

	void Library::add_book(const Book& bk)
	{
		for (Book b : books)
			if (bk == b)
				error("add_book(): book in library");
			else
				books.push_back(b);
	}

	void Library::add_patron(const Patron& pat)
	{
		for (Patron p : patrons)
			if (pat == p)
				error("add_patron(): patron already added to library");
			else
				patrons.push_back(pat);
	}

	void Library::add_trans()
};
