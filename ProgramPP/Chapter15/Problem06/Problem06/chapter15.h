#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

//------------------------------------------------------------------------------------------------------

// simple window constants
constexpr int xmax = 1400;
constexpr int ymax = 1400;

//------------------------------------------------------------------------------------------------------

// Function constants
constexpr int xorign = xmax / 2;
constexpr int yorign = ymax / 2;

constexpr int xaxis = 50;		
constexpr int yaxis = 750;		
constexpr int xlength = xmax - 200;
constexpr int ylength = ymax - 200;

//------------------------------------------------------------------------------------------------------

// Bar graph constants
constexpr int xbarx = 120; 
constexpr int xbary = 1240;

constexpr int ybarx = 120;
constexpr int ybary = 1240;

const Point xorgn{ xbarx , xbary };
const Point yorgn{ ybarx, ybary };

//------------------------------------------------------------------------------------------------------

// removed template functions from header and cpp file after finishing problem they cause FL device errors when debugging

namespace Graph_lib {

//------------------------------------------------------------------------------------------------------
	class Bar : public Shape {
		int width{ 0 };
		int height{ 0 };
		double max{ 0 };
		vector<double> vals;
		vector_ref<Text> labels;
		vector_ref<Rectangle> bars;

	public:
		Bar() {}
		Bar(Point p, int ww, int hh);

		void draw_lines() const;
		void build_bars();

		void add_value(double v); // simple and they work but lack checks for errors easy to create runtime errors not production level code
		void set_label(string t, int x) { return labels[x-1].set_label(t); };
		void set_color(Color c, int x) { return bars[x-1].set_color(c); };
		void set_fill_color(Color fc, int x) { return bars[x-1].set_fill_color(fc); };

	};

	class Scale {
		double max;
		double length;

	public:
		Scale(double mx, double l);
		int operator()(double v) { return (int)ceil(((v / max))*length); }

	};

}
//------------------------------------------------------------------------------------------------------

