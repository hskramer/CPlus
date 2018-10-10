#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Striped Rectangle" };

	Striped_Circle st_circ1{ Point{250,250}, 30 };
	st_circ1.set_color(Color::red);
	
	Striped_Circle st_circ2{ Point{500, 500}, 250 };
	st_circ2.set_color(Color::blue);
	

//	win.attach(st_circ1);
	win.attach(st_circ2);
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