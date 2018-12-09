#include "chapter15.h"
#include <iostream>
#include <stdexcept>


using namespace Graph_lib;

double slope(double x) { return x / 2; }

int main()
try {

	Simple_window win{ Point{15,15}, xmax, ymax, "Functions" };// xmax = 1000, ymax = 800;

	SFunction f
	{ cos, -8, 8, Point{x_orign, y_orign }, 400, 50, 50};
	f.set_color(Color::blue);
	f.reset_fct([](double x) { return x * x; });
	f.reset_orign(Point{ 500, 700 });
	f.reset_r1(-10);
	f.reset_r2(10);
	
	//f.reset_fct(slope);
	
	//f.reset_fct([](double x) {return x * x * x; });
	//f.reset_orign(Point{ 500, 400 });
	

	win.attach(f);
	win.wait_for_button();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error" << endl;
	return -2;
}
