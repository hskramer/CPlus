#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1100, 900, "" };
	Pseudo_window ps{ Point{25, 25}, 1000, 700, "Psuedo Window", "screen.jpg" };

	win.attach(ps);
	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return -2;
}