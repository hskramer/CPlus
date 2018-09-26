/*
*  Header for all the problems in chapter 13 requiring a class definition
*/
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;
//------------------------------------------------------------------------------

double to_radians(double deg);

//------------------------------------------------------------------------------

struct Arcs : Shape {
	
	Arcs(Point c, int ww, int hh, double s, double e)
		:w{ ww }, h{ hh }, start{ s }, end{ e }
	{
		add(c);
	}

	void draw_lines() const;

private:
	int w;
	int h;
	double start;
	double end;
};

//------------------------------------------------------------------------------
// use fl_line and fl_arc look at how their defined 
//------------------------------------------------------------------------------

struct Box : Shape {

	Box(Point p, int ww, int hh) : w{ ww }, h{ hh }
	{ 
		add(Point{p.x, p.y}); 
	}

	void draw_lines() const;

private:
	Point p;
	int w;
	int h;
};

//------------------------------------------------------------------------------
/*
  we know the start/end point(x, y) so define dx=(end2.x - start1.x) and dy=(end2.y - start1.y)
  then the normals are (-dy, dx), (dy, -dx) no division avoids divide by zero as would
  be the case if you wanted the slope for the equation's of the lines. Wikipedia has
  a good article on rotations which I used.
*/
//------------------------------------------------------------------------------

struct Arrow : Shape {

	Arrow(Point s, Point e)
		:s{ s }, e{ e }
	{
		c = Point(e.x - s.x, e.y - s.y);
		cmag = sqrt(pow(c.x, 2) + pow(c.y, 2));
		cunit = Point(c.x / cmag * 15, c.y / cmag * 15);
		ctrans = Point(cunit.x, cunit.y);

		cperp = Point(-ctrans.y, ctrans.x);
		a1 = Point(s.x + cperp.x + ctrans.x, s.y + cperp.y + ctrans.y);
		a2 = Point(s.x - cperp.x + ctrans.x, s.y - cperp.y + ctrans.y);

	};

	void draw_lines() const;	

private:
	Point e;
	Point s;
	Point c;
	Point cunit;
	Point ctrans;
	Point cperp;
	Point a1;
	Point a2;

	double cmag;
};

//------------------------------------------------------------------------------

Point n(Graph_lib::Rectangle& r);
Point s(Graph_lib::Rectangle& r);
Point e(Graph_lib::Rectangle& r);
Point w(Graph_lib::Rectangle& r);
Point nw(Graph_lib::Rectangle& r);
Point sw(Graph_lib::Rectangle& r);
Point ne(Graph_lib::Rectangle& r);
Point se(Graph_lib::Rectangle& r);
Point c(Graph_lib::Rectangle& r);

//------------------------------------------------------------------------------

Point n(Graph_lib::Circle& c);
Point s(Graph_lib::Circle& c);
Point e(Graph_lib::Circle& c);
Point w(Graph_lib::Circle& c);
Point nw(Graph_lib::Circle& c);
Point sw(Graph_lib::Circle& c);
Point ne(Graph_lib::Circle& c);
Point se(Graph_lib::Circle& c);
Point c(Graph_lib::Circle& r);

//------------------------------------------------------------------------------

Point n(Graph_lib::Ellipse& e);
Point s(Graph_lib::Ellipse& e);
Point e(Graph_lib::Ellipse& e);
Point w(Graph_lib::Ellipse& e);
Point nw(Graph_lib::Ellipse& e);
Point sw(Graph_lib::Ellipse& e);
Point ne(Graph_lib::Ellipse& e);
Point se(Graph_lib::Ellipse& e);
Point c(Graph_lib::Ellipse& e);

//------------------------------------------------------------------------------