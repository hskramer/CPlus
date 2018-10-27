#include "Graph.h"
#include "chapter14.h"
#include "Simple_window.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

int main()
try {

	Simple_window win{ Point{15,15}, 800, 825, "Draughts" };

	Group board;
	vector_ref<Graph_lib::Rectangle>r;
	vector_ref<Graph_lib::Circle> c;

	board.make_draught_board(c, r);
	board.move_piece(3, 5, 0); // row, col, piece

	win.attach(board);
	win.wait_for_button();

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return -2;
}