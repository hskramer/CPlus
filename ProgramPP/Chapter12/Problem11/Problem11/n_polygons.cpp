#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	Closed_polyline tri;
	tri.add(Point{ 1623,650 });
	tri.add(Point{ 1595,750 });
	tri.add(Point{ 1695,725 });	
	tri.set_color(Color::dark_blue);

	Closed_polyline sqr;
	sqr.add(Point{ 1595,650 });
	sqr.add(Point{ 1595,750 });
	sqr.add(Point{ 1695,750 });
	sqr.add(Point{ 1695,650 });
	sqr.set_color(Color::dark_red);

	Closed_polyline pent;
	pent.add(Point{ 1695,650 });
	pent.add(Point{ 1604,635 });
	pent.add(Point{ 1555,715 });
	pent.add(Point{ 1620,770 });//1630,770
	pent.add(Point{ 1730,740 });
	pent.set_color(Color::dark_green);	
	

	Simple_window win{ Point{15,15}, 3340, 1340, "Polygons" };

	win.attach(tri);
	win.attach(sqr);
	win.attach(pent);

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