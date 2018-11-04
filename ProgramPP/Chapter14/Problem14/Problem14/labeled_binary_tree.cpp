#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error: " << endl;
	return -2;
}