#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;

// this works down to level 6 but doesn't look great the fonts no longer fit inside the node

int main()
try {
	Simple_window win{ Point{15, 15}, 1750, 500, "Lalebled binary tree" };
	Binary_tree btree{ 5, 12};
	//btree.set_color(Color::red); 
	btree.label_node("lrl", "9"); // if label_node is used node 0 is automatically labeled as root node
	btree.label_node("l", "1");
	btree.label_node("rlr", "12");
	btree.label_node("rrr", "14");
	btree.label_node("llrl", "17"); 
	btree.label_node("rlll", "23");
//	btree.label_node("a", ""); added instruction to label all nodes
	

	win.attach(btree);
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