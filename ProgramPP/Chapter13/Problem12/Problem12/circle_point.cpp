#include "chapter13.h"
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

const double pi = 3.141592653;

Point move_on_circle(Circle& c, int t) {

	return Point{ int(c.center().x + c.radius() * cos(to_radians(t))), int(c.center().y - c.radius() * sin(to_radians(t))) };
}

int main()
try {

	char ch{ 0 };
	Simple_window win{ Point{15, 15}, 1000, 1000,  "Moving point on Circle" };
	Circle circ{ Point{win.x_max() / 2, win.y_max() / 2}, 150 }; // this allows me to change win size and still make sure the circle is centered
	Text txt{ Point{415, 500}, "Hit next to move the o" }; // centered on the x-axis running through the circle look good
	txt.set_font(FL_HELVETICA_BOLD);
	txt.set_color(Color::dark_magenta);
	circ.set_color(Color::red);
	win.attach(txt);
	win.attach(circ);

	int theta = 0;
	while (true) {
		Mark mk{ move_on_circle(circ, theta), 'o' };
		mk.set_color(Color::blue);
		win.attach(mk);		
		win.wait_for_button();
		theta += 10;
		if (theta == 360) theta = 0; // not reall required but doesn't hurt to keep value between 0 and 2 pi
	}

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