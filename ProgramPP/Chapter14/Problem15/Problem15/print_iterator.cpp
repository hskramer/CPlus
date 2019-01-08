#include "iterator.h"

int main()
try {
	
	vector<double> vempty; // This will return 0 and print() will print 'vector is empty'
	vector<double> vdbl = { 1.2, 0, 3.0, 3.5, 4.01  };
	vector<double> ten(10);
	
	for (int i = 0; i < ten.size(); ++i)
		ten[i] = i + 1.2;

	Vector_iterator v{ vempty};
	Vector_iterator v1{ vdbl};
	Vector_iterator vten{ ten };

	Iterators* ptr_v = &v;  // had to add s to Iterator to avoid error: argument list for alias template missing
	Iterators* ptr_vdbl = &v1; // print is a pure virtual member of Iterators
	Iterators* ptr_ten = &vten;
	
 	ptr_v->print(v);// this will print out a zero 

	ptr_vdbl->print(v1); // this prints all the elements in vdbl using Print(Iterators&) and next();
	ptr_ten->print(vten);

//-----------------------------------------------------------------------------------------------------------------
	list<double> lempty; // returns zero and prints 'list is empty'
	list<double> ldbl = { 1.3, 3.1, 0, 5.0, 2.7, 8.3, 5.5 };
	
	List_iterator l{ lempty };
	List_iterator l2{ ldbl };

	Iterators* ptr_l = &l;
	Iterators* ptr_l2 = &l2;

	ptr_l->print(l);
	ptr_l2->print(l2);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured " << endl;
	return -2;
}