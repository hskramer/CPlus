#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {
	
	Simple_window win{ Point{15, 15}, 1400, 1400, "Binary Tree" };

	Circle top{ Point{win.x_max()/2, 30}, 7 };
	Circle left{ Point{win.x_max() / 2 - 20, 65}, 7 };
	Circle right{ Point{win.x_max() / 2 + 20, 65}, 7 };
	
	Line l{ Point{win.x_max() / 2-5, 37}, Point{win.x_max() / 2 - 20, 58} };
	Line r{ Point{win.x_max() / 2+5, 37}, Point{win.x_max() / 2 + 20, 58} };
	l.set_color(Color::black);
	r.set_color(Color::black);

	top.set_color(Color::black);
	left.set_color(Color::black);
	right.set_color(Color::black);

	win.attach(top);
	win.attach(l);
	win.attach(left);
	win.attach(r);
	win.attach(right);
	win.wait_for_button();
	
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return -2;
}