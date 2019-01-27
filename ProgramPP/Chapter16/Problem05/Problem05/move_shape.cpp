#include "chapter16.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Move_shape win(Point{ 15, 15 },	1000, 1000, "Move shape");

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