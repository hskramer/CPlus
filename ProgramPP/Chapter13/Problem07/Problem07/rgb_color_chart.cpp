#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

using namespace Graph_lib;


/* wingdi.h interfering again has RGB function which works just fine with FLTK swap fl_rgb_color(r, g, b) out and
*  put RGB(r, g, b) in  and it works but it doesn't produce the same colors given the same values for r,g,b.
*  Decided to reproduce the image from wikipedia page on 8-bit color. These problems become much easier if you read
*  chapters 12 through 14 and the graph header and cpp files before doing any problems.
*/

int main()
try {	

	Simple_window win{Point{15, 15}, 1280, 260, "RGB Chart"};
	
	vector_ref<Graph_lib::Rectangle> rect;

	int r_size{ 40 };
	Graph_lib::Rectangle r{ Point{0, 0}, 40, 40 };

		for (int i = 0; i < 6; ++i) { 
			for (int j = 0; j < 6; ++j) { 
				for (int k = 0; k < 6; ++k) {
					rect.push_back(new Graph_lib::Rectangle{ Point{r_size * j + i * 6 * r_size, k * r_size + 20}, r_size, r_size });
					rect[rect.size() - 1].set_fill_color(fl_rgb_color(i * 51, j * 51, k * 51));
					rect[rect.size() - 1].set_color(Color::invisible);					
				}
			}
		}

		for(int i = 0; i < rect.size() - 1; ++i)
			win.attach(rect[i]);

	win.wait_for_button();

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}