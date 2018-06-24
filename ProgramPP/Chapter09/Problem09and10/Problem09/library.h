#include "../../std_lib_facilities.h"

namespace Lib {
	
//--------------------------------------------------------------------------------------------------------------------------

	class Book {
	public:
		enum Genre {
			fiction, nonfiction, periodical, biography, children // I chose to put Genre in the book class since only applies to books and its clas functions
		};
		Book(string isbn, string ti, string auth, Genre gen, int cpyr, bool chkd); // check for valid info and initialize
		Book(); // default constructor

				// nonmodifying operations:
		string get_title() const { return ti; }
		string get_author() const { return auth; }
		string get_isbn() const { return isbn; }
		Genre get_genre() const { return gen; }  // want to return genre name not index defined in book.cpp
		int get_cpyright() const { return cpyr; }
		bool checked_out() const { return chkd; }

		// modifying operations
		void check_in();
		void check_out();

	private:
		string isbn;
		string ti;
		string auth;
		Genre gen;
		int cpyr;
		bool chkd;
	};

	string genre_name(const Book& b);

	bool is_isbn(string);

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	ostream& operator<<(ostream& os, const Book& b);


//--------------------------------------------------------------------------------------------------------------------------


	class Patron {
	public:
		Patron(string uname, int libcard, double fees); // decided to add age so I could have something concrete to base fees on
		Patron();

		// nonmodifying operations:
		string get_name() const { return uname; }
		int get_libcard() const { return libcard; }
		double get_fees() const { return fees; }
		bool owe_fees(const Patron& p);
		bool scan_libcrd()  { return true; }   // My library has an rfid scanner that automatically scans card when you enter
		bool get_inlib();

		// modifying operations
		void set_fee(double f);

	private:
		string uname;
		int libcard;
		double fees;
	};

	
	bool operator==(const Patron& a, const Patron& b);
	bool operator!=(const Patron& a, const Patron& b);

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
		void add_days(int n);
		void add_years(int n);

	private:
		int y;
		Month m;
		int d;
	};

	// convenience/auxiliary functions for the date class 

	bool is_date(int y, Month m, int d); // true for valid date
	bool leapyear(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);

	int days_in_month(int y, Month m);

	
//--------------------------------------------------------------------------------------------------------------------------


	class Library {
	public:
		struct Transaction {
			Book book;
			Patron pat;
			Date date;	
		};

		Library(vector<Book> books, vector<Patron> patrons, vector<Transaction> trans);
		Library();

		// nonmodifying operations
		void list_books();
		void list_patrons();
		vector<string> patrons_owe_fees();

		// modifying operations:
		void check_out(Book& b, Patron& p, const Date& d);
		void check_in();
		void check_status() { // felt this met the criteria for including in header short and would be used very frequently
			if (chkd)
				cout << "Book is already check out" << endl;
			else
				cout << "Book is available" << endl;
		}
		void set_patron_fee(Patron& pat, double fees);
		void add_book(const Book& bk);
		void add_patron(const Patron& pat);
	
		
	private:
		bool chkd{ false }; // books start out in the library by default
		vector<Book>books;
		vector<Patron>patrons;
		vector<Transaction>transaction;
	};
};