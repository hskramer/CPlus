#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1400, 1400, "Tile" };

	vector_ref<Right_triangle> vr;
	
	int l{ 70 };
	for (int i = 1; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			vr.push_back(new Right_triangle{ Point{j * 70, i * 70}, l, l });
			if (j % 2 == 0) 
				vr[vr.size() - 1].set_color(Color::red);			
			else
				vr[vr.size() - 1].set_color(Color::blue);
			win.attach(vr[vr.size() - 1]);			
		}
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