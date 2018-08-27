#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	Open_polyline H;
	H.add(Point{ 75, 145 });
	H.add(Point{ 75, 295 });
	H.add(Point{ 75, 220 });
	H.add(Point{ 165, 220 });
	H.add(Point{ 165, 145 });
	H.add(Point{ 165, 295 });

	Open_polyline K, K1;
	K.add(Point{ 215, 150 });
	K.add(Point{ 215, 300 });
	K1.add(Point{ 215, 230 });
	K1.add(Point{ 285, 150 });
	K.add(Point{ 215, 233 });
	K.add(Point{ 270, 300 });

	K.set_color(Color::dark_red);
	K1.set_color(Color::dark_red);

	K1.set_style(Line_style(Line_style::solid, 4));
	K.set_style(Line_style(Line_style::solid, 5));
	

	H.set_color(Color::dark_blue);
	H.set_style(Line_style(Line_style::solid, 5));

	Simple_window win{ Point{100,100}, 450, 350, "Initials" };

	win.attach(H);
	win.attach(K);
	win.attach(K1);

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