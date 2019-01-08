#include "chapter16.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	// the image name is also the screen name
	Img_button win{ Point{10, 10},Point{10,10}, 1000, 1000, "cpu.jpg" };

	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown error" << endl;
	return 2;
}