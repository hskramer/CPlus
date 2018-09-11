#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

const double pi = 3.14159265359;

int main()
try {

	Simple_window win{ Point{15, 15}, 1500, 1400, "Regular Hexagon" };


	Regular_hexagon hx{ Point{100, 100}, 75 };
	Regular_hexagon hx1{ Point{100, 230}, 75 };	

	vector_ref<Regular_hexagon> hex;

	// it works for two rows and could be extended but it's not a good implementation may try again later.
	// tried to implement in class but I don't know how to access member functions without names.
	int x{ 100 }, y{ 100 }, R{ 75 };
	int side = round(2 * R * sin(pi / 6));
	for (int i = 1; i < 19; ++i) {
		int row = 0; 
		hex.push_back(new Regular_hexagon{ Point{x, y}, R }); 
		hex[hex.size() - 1].set_color(Color::red);
		win.attach(hex[hex.size() - 1]);
		x += 2 * round(0.5 * side * cos(pi / 6) / sin(pi / 6)); // two times the distance from center to a side
		if (i % 9 == 0) {
			++row;
			x = sqrt(3)/4 * R + 3; // added 2 pixels for so the lines don't lie on top of each other making it look thick
			y += 1.5 * side;
		}
	}
/*

	// problem 07
	hx.set_color(Color::red);
	hx1.set_color(Color::red);
			
	win.attach(hx);
	win.attach(hx1);
	win.attach(hx2);
	
*/
	
	win.wait_for_button();

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}