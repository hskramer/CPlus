#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	Graph_lib::Rectangle r{ Point{200,170}, 100, 30 };
	r.set_color(Color::black);

	Text t{ Point{228,190}, "Howdy" };
	t.set_color(Color::dark_blue);

	Simple_window win{ Point{100,100}, 500, 400, "Howdy" };

	win.attach(r);
	win.attach(t);
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