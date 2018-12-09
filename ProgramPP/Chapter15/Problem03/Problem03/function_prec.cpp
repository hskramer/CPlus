#include "chapter15.h"
#include <iostream>
#include <stdexcept>



int slope(int x) { return x / 2; };

int main()
try {

	Simple_window win{ Point{15, 15}, xmax, ymax, "Function Precision" };

	// template functions have to be declared with the template definitions themselves before being used here. 
	SFunction<double> f{ cos, -10, 10, Point{x_orign, y_orign}, 200, 30, 30, 2.0};
	SFunction<int> s{ sqrt, -15, 15, Point{x_orign, y_orign}, 150, 20, 20, 1 };
	f.set_color(Color::black);
	//f.reset_fct(s); cannot figure out how to reset function using templates there like nothing I've come across
	s.set_color(Color::blue);
	s.reset_orign(Point{ 200, 400 }); 

	
	win.attach(s);
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