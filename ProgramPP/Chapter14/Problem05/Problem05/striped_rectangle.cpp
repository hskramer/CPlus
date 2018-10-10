#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Striped Rectangle" };

	Striped_Rectangle st_rect{ Point{100, 100}, 600, 400 };
	//st_rect.set_color(Color::red);
		
	
	win.attach(st_rect);
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
