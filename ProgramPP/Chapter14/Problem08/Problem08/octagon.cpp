#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;


int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "Octagon Class" };

	Octagon oct{ Point{300, 300}, 125 }; // define center and length of each side. 
	oct.set_color(Color::red);
	oct.set_style(Line_style{ Line_style::dash, 2 });
	oct.move(20, 20);
	//oct.set_fill_color(Color::blue); // working
	Mark m{ Point{300, 300}, 'X' }; // mark original center to make sure move is working.
	
	win.attach(m);
	win.attach(oct);
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