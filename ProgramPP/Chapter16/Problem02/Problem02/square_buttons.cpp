#include "chapter16.h"
#include <iostream>
#include <stdexcept>

int main()
try {
	
	My_Button win(Point{ 15, 15 }, 350, 270, "Buttons");

	return gui_main();

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