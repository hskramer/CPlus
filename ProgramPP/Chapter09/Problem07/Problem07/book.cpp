#include "book.h"

Book::Book(string isbn, string ti, string auth, Genre gen, int cpyr, bool chk)  // constructor
	:isbn{ isbn }, ti{ ti }, auth{ auth }, gen{ gen }, cpyr {cpyr}, chkd{ chk } // initializers 
{
	if (!is_isbn(isbn)) cerr<<"Bad ISBN"<<endl;
	if (cpyr < 1850 || 2070 < cpyr) cerr << "Bad copy right date" << endl;; // allowing the library to add new books for 50+ years
}

Book::Book()
	:isbn{""}, ti{""}, auth{""},gen{}, cpyr{}, chkd{ false }
{
}

// originally had check in/out output an error but this stops the program would rather it report status and continue

void Book::check_out()
{
	if (chkd) cout << "check_out() book is already checked out" << endl;
	chkd = true;
}

void Book::check_in()
{
	if (!chkd) cout<<"check_in(): book is already checked in"<<endl; 
	chkd = false;
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
	bool is{ true };	 // at trying  to have legitimately sized isbn wich can have 6 or more digits this at least allows for three
	int n1{ 0 };		// if n > 254 larger ctype throws an assert error if I use stol isdigit fails. Learned a lot, real world I would use a struct.S
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

bool operator==(const Book& a, const Book& b)
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