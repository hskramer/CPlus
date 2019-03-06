#include "../../std_lib_facilities.h"

void stack(int a) {
	
	int b{ 2 };

	cout << "Stack address a: " << &a << '\n';
	cout << "Stack address b: " << &b << '\n';

	if (&b < &a)
		cout << "Stack grows down" << '\n';
	else
		cout << "Stack grows up" << '\n';
	
}

int main()
try {

	double* qd = new double[4];
	double* od = new double[8];
	cout << "Heap address qd: " << &qd << '\n';
	cout << "Heap address od: " << &od << '\n'; // the heap grows up

	if (&qd < &od)
		cout << "Heap grows up" << '\n';
	else
		cout << "Heap grows down" << '\n';

	delete qd;
	delete od;

	stack(10);

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}