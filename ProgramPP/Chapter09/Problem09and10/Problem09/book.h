#include "../../std_lib_facilities.h"


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
	int get_genre() const { return gen; }  // want to return genre name not index defined in book.cpp
	int get_cpyright() const { return cpyr; }
	
	
	// modifying operations:
	void check_out();
	void check_in();

private:
	string isbn;
	string ti;
	string auth;
	Genre gen;
	int cpyr;
};

string genre_name(const Book& b);

bool is_isbn(string );

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

ostream& operator<<(ostream& os, const Book& b);
