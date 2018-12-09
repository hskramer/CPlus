#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

constexpr int xmax = 1400;
constexpr int ymax = 800;
constexpr double y_scale = 25;
constexpr double x_scale = 25;

constexpr int x_orign = xmax / 2;
constexpr int y_orign = ymax / 2;

// constants for the x and y Axis lengths and leave 50 pixels at each end

constexpr int x_axis = 50;		// x coordinate for point
constexpr int y_axis = 750;		// y coodinate for point
constexpr int xlength = xmax-100;
constexpr int ylength = ymax-100;


namespace Graph_lib {

//------------------------------------------------------------------------------------------------------

template<class T> class SFunction : public Shape {
public:

	SFunction(Fct ff, double rr1, double rr2, Point xyorig, int ncount = 100, double xs = 25, double ys = 25, T precision = 1.0);

	void reset();
	void clear_points();
	void reset_r1(int r) { range1 = r; reset(); }
	void reset_r2(int r) { range2 = r; reset(); }
	void reset_orign(Point p) { Point{ orig.x = p.x, orig.y = p.y }; reset(); }
	void reset_ncount(int n) { count = n; reset(); }
	void reset_xs(int x) { xscale = x; reset(); }
	void reset_ys(int y) { yscale = y; reset(); }
	

private:
	Fct *f;
	double range1;
	double range2;
	Point orig;
	int count;
	double xscale;
	double yscale;
	T precision;
};

}
//------------------------------------------------------------------------------------------------------

