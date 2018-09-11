#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1000, 1000, "16*16 color matrix" };

	vector_ref<Graph_lib::Rectangle> vr;

	int r_size{ 40 };

	for (int i = 0; i < 16; ++i) 
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Graph_lib::Rectangle{ Point{r_size * i, r_size * j }, r_size, r_size });
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			vr[vr.size() - 1].set_color(Color::invisible);
			win.attach(vr[vr.size() - 1]);
		}

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