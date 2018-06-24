#include "library.h"
// decided not to allow addition of months so long as its an enumeration its considerded bad form for example say you enumerate car brands
// adding GM to Toyota doen't result in a Nissan same with fruits or most other things enumerations are used for. If it were an integer sure it makes sense.
using namespace Lib;

int main()
try {

	Library lib_one;

	Book JRR{ "14-88-99-J", "Lord of the rings", "J.R.R. Tolkien", Book::fiction, 1985, false };
	Book Book1{ "13-97-101-8", "Foundation and Empire", "Issac Asimov", Book::fiction, 1952, true };
	Book PPP{ "11-97-103-C", "Programming Principles and Practices", "Bjarne Stroustrup", Book::nonfiction, 2010, false };
	
	lib_one.add_book(JRR); // adding books working
	lib_one.add_book(Book1);
	lib_one.add_book(PPP);

	Patron One{ "Bob Doe", 53456, 0 }; 
	Patron Two{ "Alice Smith", 32569, 0 };
	Patron Three{ "John Doe", 246810,0 };
	
	lib_one.add_patron(One); // adding patrons working
	lib_one.add_patron(Two);
	lib_one.add_patron(Three);

	lib_one.set_patron_fee(Two, 8.50); 
	cout << JRR.get_title() << endl;
	
	Date test = Date(2016, Month::jun, 15 );
	test.add_days(10);
	cout <<"Date: "<<(test)<< endl;
	test.add_years(1);
	cout << "Date: " << (test) << endl;

	
	cout << (Book1) << "belongs in  " << genre_name(Book1) << "\n" << endl;

	lib_one.list_books();
	cout << endl;
	lib_one.list_patrons();

	if (!JRR.checked_out())
		cout << "Book available for check out" << endl;
	lib_one.check_out(JRR, One, Date(2017, Month::jun, 20)); // tranactions working fine
	if (JRR.checked_out())
		cout << "Book unvailable already checked out\n" << endl;

	//lib_one.check_out(PPP, Two, Date(2017, Month::jul, 15)); // should fail owes fee works

	lib_one.set_patron_fee(Two, 8.50);
	
	cout << "Names of patrons that owe fees:" << endl;
	vector<string> owe_fees = lib_one.patrons_owe_fees();

	for (string s : owe_fees)
		cout << s << " has unpaid fees" << endl;

	next_worday(Day::monday);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}