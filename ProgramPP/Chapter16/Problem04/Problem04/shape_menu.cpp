#include "chapter16.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Add_shape win(Point{ 15, 15 }, 1000, 1000, "Shape Menu");

	return gui_main();
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown error\n";
	return 2;
}