#include "Simple_window.h"
#include "chapter14.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
try {
	
	Simple_window win{ Point{15, 15}, 1000, 800, "Controller" };

	Circle c{ Point{500, 400}, 100 };
	
	Controller_test ctest; 
	ctest.set_level(5);
	ctest.on();
	ctest.show();// you need to look at the screen behind the graphics window to see the state and level.

	Controller_shape cshape(c);
	cshape.on();
	cshape.control_level(3); // line is always solid by default but level will change width.
//	cshape.off(); 

	cshape.control_color(Color::red);

	win.attach(c);
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