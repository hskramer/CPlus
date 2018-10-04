#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {
	
	Simple_window win{ Point{15, 15}, 1000, 1000, "Smiley" };

	Smiley sm{ Point{200, 300}, 125 };
	Smiley_Hat smh{ Point{200, 300}, 125 };
	Frowny frn{ Point{500, 600}, 125 };
	Frowny_Hat fnh{ Point{500, 600}, 125 };
	
	Rectangle r1{ Point{100, 700}, 75, 50 };

	win.attach(sm);
	win.attach(smh);
	win.attach(frn);
	win.attach(fnh);
	win.attach(r1);
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