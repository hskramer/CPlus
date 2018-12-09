#include "Simple_window.h"
#include "Graph.h"


constexpr int xmax = 1000;
constexpr int ymax = 800;
constexpr double y_scale = 20;
constexpr double x_scale = 20;

constexpr int x_orign = xmax / 2;
constexpr int y_orign = ymax / 2;



namespace Graph_lib {

//------------------------------------------------------------------------------------------------------

struct SFunction :  Shape {
	// store function parameters
	SFunction(Fct ff, double rr1, double rr2, Point xyorig, int ncount = 100, double xs = 25, double ys = 25);

	void clear_points();
	void reset_fct(Fct *ff) { f = ff; reset(); }
	void reset_r1(int r) { range1 = r; reset(); }
	void reset_r2(int r) { range2 = r; reset(); }
	void reset_orign(Point p) { Point{ orig.x = p.x, orig.y = p.y }; reset(); }
	void reset_ncount(int n) { count = n; reset(); }
	void reset_xs(int x) { xscale = x; reset(); }
	void reset_ys(int y) { yscale = y; reset(); }

private:
	void reset();
	Fct *f;
	double range1;
	double range2;
	Point orig;
	int count;
	double xscale;
	double yscale;
};

}

//------------------------------------------------------------------------------------------------------

