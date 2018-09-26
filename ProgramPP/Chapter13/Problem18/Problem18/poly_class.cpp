#include "Graph.h"
#include "Simple_window.h"
#include "Chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Poly Class" };

	vector_ref<Point> vrt;
	vrt.push_back(new Point{ 100, 100 });
	vrt.push_back(new Point{ 100, 200 });
	vrt.push_back(new Point{ 200, 200 });
	
	//vector_ref<Point> verror;
	//verror.push_back(new Point{ 300, 300 });
	//verror.push_back(new Point{ 300, 400 });

	Poly tri{ vrt };
	//Poly er{ verror }; // will result in error polygons require three or more  points
	win.attach(tri);

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