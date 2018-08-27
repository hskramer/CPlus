#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	int tx =  (x_max() * 0.33333)/2 ;
	int ty =  (y_max() * 0.25)/2; // divide by two so its equal space on each side

	Graph_lib::Rectangle r{ Point{tx,ty}, int(x_max() * 0.666666), int(y_max() * 0.75) };
	r.set_color(Color::red);
	r.set_style(Line_style(Line_style::solid, 20));


	Simple_window win{ Point{0,0}, x_max(), y_max(),"" };
	
	win.attach(r);
	win.wait_for_button();

	return 0;
}
catch(exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}