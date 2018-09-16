#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1200, 1200, "Octagonal shape" };

	int length{ 100 };   // making the side equal gives a 45-45-90 degree triangle (you can enter seperate values
	Point center{ win.x_max() / 2, win.y_max() / 2 };	

	vector_ref<Right_triangle> vr;
	
	for (int i = 0; i < 8; ++i) {
		vr.push_back(new Right_triangle{ center, length, length }); // changing lengths alters the final shape.
		vr[i].rotate(45 * i);
		for(int j = 0; j < 8; ++j)    // adding inner loop for color really helps achieve a good contrast between colors
			vr[i].set_color(Color{ 16 * i + j * 8 });
		win.attach(vr[i]);
	}
	
	win.wait_for_button(); // altering your choice for which point acts as an origin and angle of rotation will produce many interesting geometric patterns
						   // including a nice octagonal shape
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