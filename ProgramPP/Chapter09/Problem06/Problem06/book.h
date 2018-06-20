#include "../../std_lib_facilities.h"


class Book {
public:
	Book(string isbn, string ti, string auth, int cpyr, bool chkd); // check for valid info and initialize
	Book(); // default constructor

	// nonmodifying operations:
	string get_title() const { return ti; }
	string get_author() const { return auth; }
	string get_isbn() const { return isbn; }
	int get_cpyright() const { return cpyr; }
	void check_status() { // felt this met the criteria for including in header short and would be used very frequently
		if (chkd)
			cout << "Book is already check out" << endl;
		else
			cout << "Book is available" << endl;
	}
	
	// modifying operations:
	void check_out();
	void check_in();

private:
	string isbn;
	string ti;
	string auth;
	bool chkd{ false }; // books are start out in the library by default
	int cpyr;
};

bool is_isbn(string );

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

ostream& operator<<(ostream& os, const Book& b);
