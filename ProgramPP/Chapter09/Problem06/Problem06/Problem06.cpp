#include "../../std_lib_facilities.h"
#include "book.h"

/*
* Programs should not terminate  from errors that can and should be caught. In this program bad dates or matching ISBN numbers should be
* reported while the program continues to run so that is what I chose to do catch report continue. If its within my current capability.
*/


int main()
try {

	Book JRR{ "14-88-99-J", "Lord of the rings", "J.R.R. Tolkien", 1985, false };
	Book fail{ "121-55-117-S", "Will Fail bad year","John Doe", 1500, true }; // results in bad copy right error at runtime does not stop program
	Book Book1{ "13-97-101-8", "Foundation and Empire", "Issac Asimov", 1952, true };
	Book Book2{ "11-88-99-A", "My Book One", "John Doe", 1984, true };
	Book Book3{ "11-88-99-A", "My Book Two", "John Doe", 1943, true };


	JRR.check_out(); 
	JRR.check_status(); // made for myself so I could see check-in/out work properly

	cout << Book1.get_title() << endl;
	Book1.check_in();
	Book1.check_status();

	if (Book2 == Book3) cout << "duplicate ISBN numbers" << endl<<endl;

	cout<<(Book1);

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