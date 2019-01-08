#include "chapter16.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	My_window win{ Point{100, 100}, 1200, 800, "My window" };
	
	Circle c{ Point{400, 400}, 150 };
	win.attach(c);

	win.wait_for_button();

	Line l{ Point{100, 100}, Point{700, 700} };
	win.attach(l);

	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown error" << endl;
	return 2;
}