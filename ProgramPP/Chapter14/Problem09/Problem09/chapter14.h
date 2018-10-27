#include "Graph.h"
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


}
