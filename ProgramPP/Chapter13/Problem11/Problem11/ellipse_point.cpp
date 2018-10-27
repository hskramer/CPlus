#include "chapter13.h"
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

// use a parametric equation for points on an ellipse you have x = a cos(theta), y = b sin(theta) where a is major radius
// and b the minor radius with the ellipse centered at the origin.



int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Ellipse" };

	Point center{ win.x_max() / 2, win.y_max() / 2 };

	Graph_lib::Ellipse e{center, 300, 200 };
	Axis xa{ Axis::x, center, 400, 20, "x-axis" };
	Axis ya{ Axis::y, center, 300, 15, "y-axis" };

	Mark f1{ e.focus1(), 'X' };
	Mark f2{ e.focus2(), 'X' };

	int x = e.center().x + e.major() * cos(45); // add a mark in the first quadrant
	int y = e.center().y - e.minor() * sin(45);

	Mark p{ Point{ x, y }, '+' };

	Line L1{ e.focus1(), Point{x, y} };
	L1.set_color(Color::dark_green);

	Line L2{ e.focus2(), Point{x, y} };
	L2.set_color(Color::dark_green);

	Line tL{ Point{500, 261}, Point{850, 411} }; // tangent line with rounding to the point 

	e.set_color(Color::blue);
	f1.set_color(Color::red);
	f2.set_color(Color::red);
	p.set_color(Color::dark_red);


	win.attach(e);
	win.attach(tL);
	win.attach(p);
	win.attach(xa);
	win.attach(ya);
	win.attach(f1);
	win.attach(f2);
	win.attach(L1);
	win.attach(L2);
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