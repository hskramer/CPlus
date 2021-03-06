#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {
	
	Simple_window win{ Point{15, 15}, 1800, 800, "Binary Tree" };
	Binary_tree b_tree(7, 5); // max level is 7 with radius of 5 distance btw nodes is a function of levels and radius
	
	win.attach(b_tree);
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