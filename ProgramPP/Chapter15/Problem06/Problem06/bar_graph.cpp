#include "chapter15.h"
#include <iostream>
#include <stdexcept>


int main()
try {

	Simple_window win{ Point{15, 15}, xmax, ymax, "Bar graph" };
	
	Bar bar;
	bar.add_value(222);
	bar.add_value(120);
	bar.add_value(131);
	bar.add_value(113);
	bar.add_value(190);
	bar.build_bars();
	bar.set_fill_color(Color::red, 1);
	bar.set_color(Color::green, 4);
	bar.set_fill_color(Color::blue, 4);
	bar.set_label("15 cm", 2);

	win.attach(bar);	
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