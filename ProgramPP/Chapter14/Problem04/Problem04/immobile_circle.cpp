#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Immobiel Circle" };

	Circle circ{ Point{200, 200}, 75 };
	circ.move(100, 100);
	Mark mk{ Point{200, 200}, 'X' }; // this is used to show the circle original center so we can see if the circle has moved, it did move.

	Immobile_Circle im_circ{ Point{500, 500}, 100 };
	im_circ.move(100, 100); 
	Mark imk{ Point{500, 500}, 'X' }; // circle remained in place move has been overriden msg doesn't print out however tried cerr and cout.

	win.attach(circ);
	win.attach(mk);

	win.attach(im_circ);	
	win.attach(imk);

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