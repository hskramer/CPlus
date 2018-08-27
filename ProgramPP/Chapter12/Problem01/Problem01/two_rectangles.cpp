#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	Graph_lib::Rectangle r1{ Point{150, 150}, 150, 75 };
	r1.set_color(Color::blue);

	Graph_lib::Rectangle r3{ Point{125, 225}, 25, 50 };
	r3.set_color(Color::green);

	Closed_polyline r2;
	r2.add(Point{ 300, 75 });
	r2.add(Point{ 450, 75 });
	r2.add(Point{ 450, 150 });
	r2.add(Point{ 300, 150 });
	r2.set_color(Color::red);

	Point tl{ 100,100 };
	Simple_window win{ tl, 600, 400, "My Window" };

	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
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