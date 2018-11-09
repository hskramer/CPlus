#include "chapter13.h"
#include <iostream>
#include <cmath>


namespace Graph_lib {

//------------------------------------------------------------------------------------------------------

struct Smiley : Circle {

	Smiley(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};


struct Smiley_Hat : Smiley {

	Smiley::Smiley;
	void draw_lines() const;
};

//------------------------------------------------------------------------------------------------------

struct Frowny : Circle {

	Frowny(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};

struct Frowny_Hat : Frowny {

	Frowny::Frowny;
	void draw_lines() const;
};

//------------------------------------------------------------------------------------------------------

struct Immobile_Circle : Circle {

	Immobile_Circle(Point cntr, int r) : Circle(cntr, r) {}
	void move(int dx, int dy) { cout << "immobile circle can't move" << endl; }

};

//------------------------------------------------------------------------------------------------------

struct Striped_Rectangle : Rectangle {

	Rectangle::Rectangle;
	void draw_lines() const;
};

//------------------------------------------------------------------------------------------------------

struct Striped_Circle : Circle {

	Circle::Circle;
	void draw_lines() const;
};

//------------------------------------------------------------------------------------------------------

struct Striped_closed_polyline : Closed_polyline {

	Closed_polyline::Closed_polyline;
	void draw_lines() const;
};

//------------------------------------------------------------------------------------------------------

struct Octagon : Shape {

	Octagon(Point c, int dd);
	void draw_lines() const;

private:
	int d;
	Point center;
};

//------------------------------------------------------------------------------------------------------

struct Group : Shape {
	Group() {}

	void add_board_rect(Shape& r) { rect.push_back(r); }
	void add_board_circ(Shape& c) { circ.push_back(c); }
	void make_draught_board(vector_ref<Graph_lib::Circle>& circ_ref, vector_ref<Graph_lib::Rectangle>& rect_ref);

	void move_piece(int sq_row, int sq_col, int piece);
	void draw_lines() const;

private:
	vector_ref<Shape> rect;
	vector_ref<Shape> circ;
};

//------------------------------------------------------------------------------------------------------

struct Pseudo_window : Box {

	Pseudo_window(Point p, int ww, int hh, string winlbl, string imgname);
	
	void draw_lines() const;

private:
	int w;
	int h;
	Point tl;
	string label;
	string image;
	Box main;
	Line ln;
	Rectangle max;
	Rectangle min;
	Rectangle cls;
};

//------------------------------------------------------------------------------------------------------

struct Binary_tree : Shape {

	Binary_tree(int nn, int rr, Color lc = Color::black, Line_style ls = Line_style::solid);

	virtual void draw_lines() const;

	// you can set color and line style using the constructor but I created the functions for a consistent interface
	void set_color(Color cl) { lcolor = cl; }
	void set_style(Line_style ls) { lstyle = ls; }

	Point root_node() { return point(0); }
	int number_levels() { return levels; }
	void label_node(string node, string n_lbl); // assuming utf-8 so number of bytes equal to actual string length

protected:
	int levels;
	int r;
	Point c{ 875, 30 }; // first point at x = half screen width this allows for a symmetrical use of screen space
	Color lcolor;
	Line_style lstyle;
	vector_ref<Text> labels;
};

//------------------------------------------------------------------------------------------------------

struct Binary_triangle : Binary_tree {

	using Binary_tree::Binary_tree;
	void draw_lines() const;

};

//------------------------------------------------------------------------------------------------------


}

