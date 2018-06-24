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

	void Book::check_in()
	{
		if (checked_out())
			error("check_in(): book already checked in");
		chkd = true;
			
	}

	void Book::check_out()
	{
		if (checked_out()) error("check_out(): book already checked out");
		chkd = true; 
					   // this is just used to access the variable that determines the status of a book and sets it to true
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
	
	bool Patron::owe_fees(const Patron & p)
	{
		return p.get_fees() > 0;
	}

	void Patron::set_fee(double f)
	{
		if (f < 0) error("Patron set_fee(): fee is less than zerp");
		fees = f;
	}
	
	bool Patron::get_inlib()
	{
		if (scan_libcrd())
			return true;
		
		return false;
	}

	bool operator==(const Patron& a, const Patron& b)
	{
		// make sure name and card are equal 
		return (a.get_name() == b.get_name() &&	a.get_libcard() == b.get_libcard());
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

	void  Date::add_days(int n)
	{
		int max_days = days_in_month(y, m);

		if (d + n < 0) error("add_day(): error negative days");

		if (d + n > max_days) error("too many days would result in adding months");
		d += n;
	}

	void Date::add_years(int n)
	{
		if (n < 0) error("add_year(): negative value", n);
		y += n;
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
		:books{ b }, patrons{ p }, transaction{ t }
	{
	}

	Library::Library()
	{
	}

	void Library::add_book(const Book& bk)
	{
		for (Book b : books)
			if (bk == b)
				error("add_book(): book in library");

		books.push_back(bk);
	}

	void Library::add_patron(const Patron& pat)
	{
		for (Patron p : patrons)
			if (pat == p)
				error("add_patron(): patron already added to library");

		patrons.push_back(pat);
	}


	void Library::check_out(Book& bk, Patron& pat, const Date& dt)
	{
		bool in_library{ false };
		bool found{ false };

		for (Patron p : patrons) {
			if (p == pat) {
				found = true;
				break;
			}
		} // note be sure you fully understand your else clause they can really be misleading this use to be an if/else statement and it didn't work
			
		if(!found) error("lib chec_out(): patron not found");
			
		
		// if patron exists make sure book and patron in library
			if (bk.checked_out()) { //  check_out returns that books status true if already checked out or false if not
				in_library = false;
			}
			else {
				in_library = true;
			}

			if (pat.get_inlib()) {
				in_library = true;
			}
			else {
				in_library = false;
			}

		if (pat.get_fees() > 0) error("lib check_out(): patron owes fees");

	
		if (found && in_library)
			transaction.push_back(Transaction{ bk, pat, dt });
		bk.check_out();
	}

	void Library::set_patron_fee(Patron& pat, double f)
	{
		if (pat.get_fees() < 0) error("setUserFee(): error fee less than zero");
		
		bool found{ false };
		for (int i = 0; i < patrons.size(); ++i) {
			if(patrons[i] == pat){
				patrons[i].set_fee(f);
				found = true;
				break;
			}
		}

		if (!found) error("Library set_patron_fee(): patron not found");
	}

	void Library::check_in()
	{
		if (!chkd) cout << "check_in(): book is already checked in" << endl;
		chkd = false;
	}

	void Library::list_books()
	{
		for (Book bk : books) {
			cout << bk.get_title() << " " << bk.get_author() << endl;
		}
	}

	void Library::list_patrons()
	{
		for (Patron pat : patrons)
			cout << pat.get_name() << " " << pat.get_libcard() << endl;
	}

	vector<string> Library::patrons_owe_fees()
	{
		vector<string> owe_fees;

		for (Patron pat : patrons) {
			if (pat.get_fees() > 0)
				owe_fees.push_back(pat.get_name());
		}

		return owe_fees;
	}
};
