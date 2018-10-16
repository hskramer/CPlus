#include "Graph.h"
#include "chapter13.h"
#include <iostream>
#include <cmath>


namespace Graph_lib {

//-------------------------------------------------------------------------------------------------

struct Smiley : Circle {

	Smiley(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};


struct Smiley_Hat : Smiley {
	
	Smiley::Smiley;
	void draw_lines() const;	
};

//-------------------------------------------------------------------------------------------------

struct Frowny : Circle {

	Frowny(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};

struct Frowny_Hat : Frowny {

	Frowny::Frowny;
	void draw_lines() const;
};

//-------------------------------------------------------------------------------------------------

struct Immobile_Circle : Circle {

	Immobile_Circle(Point cntr, int r) : Circle(cntr,  r) {}
	void move(int dx, int dy) { cout << "immobile circle can't move" << endl; }
	
};

//-------------------------------------------------------------------------------------------------

struct Striped_Rectangle : Rectangle {

	Rectangle::Rectangle;
	void draw_lines() const;

};

//-------------------------------------------------------------------------------------------------

struct Striped_Circle : Circle {

	Circle::Circle;
	void draw_lines() const;
};

//-------------------------------------------------------------------------------------------------

struct Striped_closed_polyline : Closed_polyline {

	Closed_polyline::Closed_polyline;
	void draw_lines() const;
	void set_fill_color(Color col);

};



}
