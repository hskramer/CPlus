#include "book.h"
#include "patron.h"



int main()
try {

	Book JRR{ "14-88-99-J", "Lord of the rings", "J.R.R. Tolkien", Book::fiction, 1985, false };
	Book Book1{ "13-97-101-8", "Foundation and Empire", "Issac Asimov", Book::fiction, 1952, true };
	
	Patron One{ "Bob Doe", 53456, 0};
	Patron Two{ "Alice Smith", 32569, 0};
	One.set_fee(8.50);

	cout << JRR.get_title() <<endl;
	JRR.check_status();

	cout << endl;
	cout << (Book1) << "belongs in  " << genre_name(Book1) << "\n" << endl;

	cout << fixed;
	cout << setprecision(2);
	if (One.get_fees())
		cout << One.get_name() << " owes $" << One.get_fees() <<" suspend card number "<<One.get_libcard()<<endl;
	
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