#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Copy Shape" };


	Graph_lib::Rectangle rect{ Point{200, 200}, 400, 400 };
	Circle circ{ Point{500, 500}, 100 };

	Graph_lib::Shape copy_rect; // vs 2017 imediately underlines copy_rect with red and gives a syntax error inaccessible
	Graph_lib::Shape copy_circ; //  can't even come close to compiling

	win.attach(rect);

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