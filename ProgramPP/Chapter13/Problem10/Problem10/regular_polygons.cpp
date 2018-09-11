#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win(Point{ 15, 15 }, 1200, 1200, "Regular polygons");

	Regular_polygons tri{ Point{400, 200}, 75, 3 };
	Regular_polygons sq{ Point{200, 200}, 75, 4 };
	Regular_polygons pent{ Point{100,100}, 75, 5 };
	Regular_polygons hex{ Point{300, 100}, 75, 6 };
	Regular_polygons hept{ Point{600, 100}, 75, 7 };
	Regular_polygons oct{ Point{900, 100}, 75, 8 };
	Regular_polygons pentad{ Point{600, 600}, 150, 15 }; // all work, polygon's with more than 15 sides start to look like a circle

	tri.set_color(Color::dark_red);
	sq.set_color(Color::dark_blue);
	pent.set_color(Color::black);
	hex.set_color(Color::blue);
	hept.set_color(Color::red);
	oct.set_color(Color::green);
	pentad.set_color(Color::red);

	win.attach(tri);
	win.attach(sq);
	win.attach(pent);
	win.attach(hex);
	win.attach(hept);
	win.attach(oct);
	win.attach(pentad);
	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}