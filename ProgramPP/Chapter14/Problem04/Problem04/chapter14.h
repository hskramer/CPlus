#include "Graph.h"
#include "chapter13.h"
#include <iostream>

namespace Graph_lib {

//------------------------------------------------------------------------------

struct Smiley : Circle {

	Smiley(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};


struct Smiley_Hat : Smiley {
	
	Smiley::Smiley;
	void draw_lines() const;	
};

//------------------------------------------------------------------------------

struct Frowny : Circle {

	Frowny(Point cntr, int r) : Circle(cntr, r) {}
	void draw_lines() const;
};

struct Frowny_Hat : Frowny {

	Frowny::Frowny;
	void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Immobile_Circle : Circle {

	Immobile_Circle(Point cntr, int r) : Circle(cntr,  r) {}
	void move(int dx, int dy) { cout << "immobile circle can't move" << endl; }
	
};

}
