#include "chapter15.h"
#include <iostream>
#include <stdexcept>



double sum_of_squares(double x) {
	return pow(sin(x),2) + pow(cos(x),2);
}

int main()
try {
	
	Simple_window win{ Point{15, 15}, xmax, ymax, "Graphing Functions" };

	// axis centerd on screen and 100 pixels shorter the xmax and ymax
	Axis x{ Axis::x, Point{x_axis, y_orign}, xlength, xlength/x_scale, "one notch == 1"};
	x.set_color(Color::black);
	x.label.move(-300, 45);
	Axis y{ Axis::y, Point{x_orign, y_axis}, ylength, ylength/y_scale, "one notch == 1" };
	y.set_color(Color::black);

	Function f{ sin, -25, 25, Point{x_orign, y_orign}, 400 }; Line lf{ Point{150,100}, Point{200, 100} }; 
	f.set_color(Color::blue); lf.set_color(Color::blue); win.attach(lf);
	Text tf{ Point{30, 100}, "sin" }; tf.set_color(Color::blue), win.attach(tf);

	Function f1{ cos, -25, 25, Point{x_orign, y_orign }, 400 }; Line lf1{ Point{150, 125}, Point{200, 125} };
	f1.set_color(Color::red); lf1.set_color(Color::red); win.attach(lf1);
	Text tf1{ Point{30, 125}, "cos" }; tf1.set_color(Color::red); win.attach(tf1);

	Function f2{ [](double x) {return sin(x) + cos(x); }, -25, 25, Point{x_orign, y_orign}, 400 }; Line lf2{ Point{150, 150}, Point{200, 150} };
	f2.set_color(Color::dark_red); lf2.set_color(Color::dark_red); win.attach(lf2);
	Text tf2{ Point{30, 150}, "sin+cos" }; tf2.set_color(Color::dark_red); win.attach(tf2);

	Function f3{ sum_of_squares, -25, 25, Point{x_orign, y_orign}, 400 }; Line lf3{ Point{150, 175}, Point{200, 175} };
	f3.set_color(Color::dark_green); lf3.set_color(Color::dark_green); win.attach(lf3);
	Text tf3{ Point{30, 175}, "sin*sin+cos*cos" }; tf3.set_color(Color::dark_green); win.attach(tf3);

	win.attach(f3);
	win.attach(f2);
	win.attach(f1);
	win.attach(f);
	win.attach(y);
	win.attach(x);
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