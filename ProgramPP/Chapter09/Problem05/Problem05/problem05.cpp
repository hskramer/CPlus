#include "../../std_lib_facilities.h"
#include "book.h"



int main()
try {

	Book JRR{"144-88-99-J", "Lord of the rings", "J.R.R. Tolkien", 1985, false };
	Book fail{ "121-55-117-8", "Will Fail bad year","John Doe", 1500, true }; // results in bad copy right error 
	Book Book1{ "13-97-101-V", "Foundation and Empire", "Issac Asimov", 1952, true };

	cout << JRR.get_author()<<" " <<JRR.get_title()<< endl;
	JRR.check_out(); // already checked in error
	JRR.check_status();
	
	cout << Book1.get_title() << endl;
	Book1.check_in();
	Book1.check_status();

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