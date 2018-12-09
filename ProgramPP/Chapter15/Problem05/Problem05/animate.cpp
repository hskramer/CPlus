#include "chapter15.h"
#include <iostream>
#include <stdexcept>

double term(double y) {

	return  (2 * y + 1);
}

double leib_sum(int n) {
	double sum{ 1 };

	for(int i = 1; i <= n; ++i) {
		int x = i % 2 == 0 ? 1 : -1;
		sum += (x / term(i));
	}
	return sum;
}
// vs 2017 15.9.3 much more restrictive before this version it would do an implicit conversion with a warning now its an error
// unless you do an explicit cast could not get this to work even when I copied example from book there were multiple errors

int main()
try {
	
	Simple_window win{ Point{15, 15}, xmax, ymax, "" };

	Axis x{ Axis::x, Point{x_axis, y_orign}, xlength, xlength / x_scale, "one notch == 1" };
	x.set_color(Color::black); x.label.move(-100, 25); win.attach(x);

	Axis y{ Axis::y, Point{x_orign, y_axis}, ylength, ylength / y_scale, "one notch == 1" };
	y.set_color(Color::black); win.attach(y);

	for (int n = 1; n < 50; ++n) {
		ostringstream ss;
		ss << "Leibniz's series n =" << n;
		win.set_label(ss.str());
		IFunction ls{ leib_sum, 0., static_cast<double>(n), Point{ x_orign,y_orign }, 100, 25, 25 };
		win.attach(ls);
		win.wait_for_button();
		win.detach(ls);
	}

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

