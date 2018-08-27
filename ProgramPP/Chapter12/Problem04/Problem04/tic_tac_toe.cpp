#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {

	using namespace Graph_lib;

	Graph_lib::Rectangle r1{ Point{125,100}, 75, 75 };
	r1.set_fill_color(Color::white);

	Graph_lib::Rectangle r2{ Point{ 200,100}, 75, 75 };
	r2.set_fill_color(Color::red);

	Graph_lib::Rectangle r3{ Point{ 275,100 }, 75, 75 };
	r3.set_fill_color(Color::white);

	Graph_lib::Rectangle r4{ Point{ 125,175 }, 75, 75 };
	r4.set_fill_color(Color::red);

	Graph_lib::Rectangle r5{ Point{ 200, 175}, 75, 75 };
	r5.set_fill_color(Color::white);

	Graph_lib::Rectangle r6{ Point{ 275,175 }, 75, 75 };
	r6.set_fill_color(Color::red);

	Graph_lib::Rectangle r7{ Point{125, 250 }, 75, 75 };
	r7.set_fill_color(Color::white);

	Graph_lib::Rectangle r8{ Point{ 200,250 }, 75, 75 };
	r8.set_fill_color(Color::red);

	Graph_lib::Rectangle r9{ Point{ 275, 250 }, 75, 75 };
	r9.set_fill_color(Color::white);


	Simple_window win{ Point{100,100}, 500, 400, "tic-tac-toe" };
	
	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(r8);
	win.attach(r9);

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