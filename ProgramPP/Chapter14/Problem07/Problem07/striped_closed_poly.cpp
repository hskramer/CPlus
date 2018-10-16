#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Striped Closed Polyline" };

	Graph_lib::Striped_closed_polyline strp_cpl;
	strp_cpl.add(Point{ 100, 100 });
	strp_cpl.add(Point{ 450, 500 });
	strp_cpl.add(Point{ 550, 550 });
	strp_cpl.add(Point{ 600, 500 });	
	strp_cpl.set_color(Color::red);
	strp_cpl.set_fill_color(Color::red);
	
	
	win.attach(strp_cpl);
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