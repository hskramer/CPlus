/*
*  Header for all the problems in chapter 13 requiring a class definition
*/

#include "Graph.h"
#include "std_lib_facilities.h"
#include <cmath>

using namespace Graph_lib;

Point operator+(Point a, Point b);

//------------------------------------------------------------------------------

double to_radians(double deg); // declaration for member function to convert degrees to radians

//------------------------------------------------------------------------------


struct Arcs : Shape {
	
	Arcs(Point c, int ww, int hh, double s, double e);
	
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

	Box(Point p, int ww, int hh);
	Box() {}

	Point center();

	int height() const { return h; }
	int width() const { return w; }
	
	
	void draw_lines() const;

private:
	int w;
	int h;
};

Point n(const Box& b);
Point s(const Box& b);
Point e(const Box& b);
Point w(const Box& b);


//------------------------------------------------------------------------------
/*
  we know the start/end point(x, y) so define dx=(end2.x - start1.x) and dy=(end2.y - start1.y)
  then the normals are (-dy, dx), (dy, -dx) no division avoids divide by zero as would
  be the case if you wanted the slope for the equation's of the lines. Wikipedia has
  a good article on rotations which I used.
*/
//------------------------------------------------------------------------------

struct Arrow : Shape {

	Arrow(Point strt, Point end, bool s); // arrow head at start point by default
	Arrow(Point p1, Point p2);

	void draw_lines() const;	

private:
	Point start;
	Point end;
	Point c;
	Point cunit;
	Point ctrans;
	Point cperp;
	Point a1; // arrow head line one end point
	Point a2; // arrow head line two end point
	bool s; // default is true  arrow point at start of line if false at end of line
	double cmag;
};

//------------------------------------------------------------------------------

struct Text_Box : Shape {

	Text_Box( Point tl, int w, int h, string s);

	void draw_lines() const;

private:
	// Text Box
	int w;
	int h;
	Point p;

	//label
	Point txt_pt;
	string label;	
};

//------------------------------------------------------------------------------

struct Regular_hexagon : Shape {

	Regular_hexagon(Point c, int ll);  
	
	int side();
	int dist() const { return l; }

	void draw_lines() const;

private:
	int l;
	Point center;
};

//------------------------------------------------------------------------------

struct Regular_polygons : Shape {

	Regular_polygons(Point c, int ll, int nn);

	void draw_lines() const;

private:
	int l, n; // length and number of sides
	Point center;
};

//------------------------------------------------------------------------------

struct Right_triangle : Closed_polyline {

	Right_triangle(Point r, int ww, int hh);	
	
	void add_points();
	void rotate(int angle);	
	void draw_lines() const;

private:
	int w, h;
	Point r;
};



//------------------------------------------------------------------------------

// Rectangel Point Declarations

//------------------------------------------------------------------------------

Point n(const  Graph_lib::Rectangle& r);
Point s(const  Graph_lib::Rectangle& r);
Point e(const  Graph_lib::Rectangle& r);
Point w(const  Graph_lib::Rectangle& r);
Point nw(const Graph_lib::Rectangle& r);
Point sw(const Graph_lib::Rectangle& r);
Point ne(const Graph_lib::Rectangle& r);
Point se(const Graph_lib::Rectangle& r);
Point c(const  Graph_lib::Rectangle& r);

//------------------------------------------------------------------------------

// Circle Point Declarations

//------------------------------------------------------------------------------

Point n(const  Graph_lib::Circle& c);
Point s(const  Graph_lib::Circle& c);
Point e(const  Graph_lib::Circle& c);
Point w(const  Graph_lib::Circle& c);
Point nw(const Graph_lib::Circle& c);
Point sw(const Graph_lib::Circle& c);
Point ne(const Graph_lib::Circle& c);
Point se(const Graph_lib::Circle& c);
Point c(const  Graph_lib::Circle& r);

//------------------------------------------------------------------------------

// Ellipse Point Declarations

//------------------------------------------------------------------------------

Point n(const  Graph_lib::Ellipse& e);
Point s(const  Graph_lib::Ellipse& e);
Point e(const  Graph_lib::Ellipse& e);
Point w(const  Graph_lib::Ellipse& e);
Point nw(const Graph_lib::Ellipse& e);
Point sw(const Graph_lib::Ellipse& e);
Point ne(const Graph_lib::Ellipse& e);
Point se(const Graph_lib::Ellipse& e);
Point c(const  Graph_lib::Ellipse& e);

//------------------------------------------------------------------------------