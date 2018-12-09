#include "chapter15.h"
#include <iostream>
#include <stdexcept>

// latest upgrade of vs 2017 causing many problems with narrowing conversion errors

int main()
try {

	Simple_window win{ Point{15, 15}, 1400, 1000, "Bar graphs" };

	Axis x{ Axis::x, Point{700, 500}, 1000, 1000 / 25, "one notch == 1" };
	x.set_color(Color::black); win.attach(x);


	win.wait_for_button();

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error: " << endl;
	return -2;
}