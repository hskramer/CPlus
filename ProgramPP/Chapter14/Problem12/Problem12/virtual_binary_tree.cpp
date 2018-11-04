#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15,15}, 1800, 800, "Binary Tree" };
	Binary_triangle b_tree{6, 5}; // max level is six
	
	win.attach(b_tree);
	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error:" << endl;
	return -2;
}