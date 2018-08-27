#include "std_lib_facilities.h"
#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "Window.h"

#include <iostream>
#include <stdexcept>

int main()
try {
	 
	Image snd{ Point{1200, 500}, "sound.jpg" };
	Text t{ Point{1220,485}, "Boom!" };
	t.set_font(Font::helvetica_bold);
	t.set_color(Color::dark_red);
	t.set_font_size(25);

	Simple_window win{ Point{15,15},3340,1340,"Jet breaking speed of sound" };


	win.attach(snd);
	win.attach(t);
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