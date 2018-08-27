#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	Circle c1{ Point{1030, 520}, 300 };
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid, 4));
	Circle c2{ Point{1355,820}, 300 };
	c2.set_style(Line_style(Line_style::solid, 4));
	c2.set_color(Color::yellow);
	Circle c3{ Point{1680,520},300 };
	c3.set_color(Color::black);
	c3.set_style(Line_style(Line_style::solid, 4));
	Circle c4{ Point{ 2005,820 },300 };
	c4.set_color(Color::dark_green);
	c4.set_style(Line_style(Line_style::solid, 4));
	Circle c5{ Point{ 2330,520 },300 };
	c5.set_color(Color::red);
	c5.set_style(Line_style(Line_style::solid, 4));


	Simple_window win{ Point{15,15},3340, 1340, "Olympic Rings" };

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

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