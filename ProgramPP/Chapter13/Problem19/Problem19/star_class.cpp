#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>


int main()
try {
	
	Simple_window win{ Point{15, 15}, 1200, 1000, "Star" };

	Star st1{ Point{200, 200}, 5, 40 };
	st1.set_fill_color(Color::red);

	Star st2{ Point{400, 400}, 6, 40 };
	st2.set_fill_color(Color::blue);

	Star st3{ Point{200,600}, 8, 45 };
	st3.set_fill_color(Color::green);

	Star st4{ Point{600, 600}, 12, 50 };
	st4.set_fill_color(Color::yellow);
	
	win.attach(st1);
	win.attach(st2);
	win.attach(st3);
	win.attach(st4);
	win.wait_for_button();

	return 0;
}

catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -2;
}
catch (...) {
	cerr << "unkown error: " << endl;
	return -2;
}