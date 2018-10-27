#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1200, 1200, "FLTK class diagram" };

	// top boxes
	Text_Box wndw{ Point{150, 25}, 200, 100, "Window" }; // all Text boxes have line color yellow with a black bold font
	Text_Box lnstyl{ Point{450, 25}, 200, 100, "Line_Style" };
	Text_Box colr{ Point{750, 25}, 200, 100, "Color" };

	// middle boxes
	Text_Box smplwin{ Point{125, 425}, 200, 100, "Simple_window" };
	Text_Box shape{ Point{425, 400}, 200, 100,"Shape" };
	Text_Box pnt{ Point{800, 425}, 200, 100, "Point" };

	// bottom boxes
	Text_Box lin{ Point{100, 1000}, 100, 50, "Line"}; 
	Text_Box linstyl{ Point{225, 1000},  100, 50, "Lines" };
	Text_Box poly{ Point{350, 1000}, 100, 50, "Polygon" };
	Text_Box axs{ Point{475, 1000}, 100, 50, "Axis" };
	Text_Box rect{ Point{600, 1000}, 100, 50, "Rectangle" };
	Text_Box txt{ Point{725, 1000}, 100, 50, "Text" };
	Text_Box img{ Point{850, 1000}, 100, 50,"Image" };
	
	
	Arrow swmw{ Point{225, 426,}, Point{225, 126}, false }; // arrow head at start of line if true, end if false.
	swmw.set_color(Color::red); // all arrows are red because, well why not?

	Arrow lnsh{ Point{150, 1001}, Point{430, 488}, false }; lnsh.set_color(Color::red);
	Arrow lns{ Point{275, 1001}, Point{455, 499}, false }; lns.set_color(Color::red); // add to account for the radius
	Arrow polys{ Point{400, 1001}, Point{485, 501}, false }; polys.set_color(Color::red); // found that one pixel into the line looked best
	Arrow axsh{ Point{525, 1001}, Point{515, 501}, false }; axsh.set_color(Color::red);
	Arrow rects{ Point{650, 1001}, Point{545, 501}, false }; rects.set_color(Color::red);
	Arrow txts{ Point{775, 1001}, Point{580, 502}, false }; txts.set_color(Color::red);
	Arrow imgs{ Point{900, 1001}, Point{615, 492}, false }; imgs.set_color(Color::red);

	win.attach(wndw);
	win.attach(lnstyl); win.attach(lnstyl); win.attach(colr); // top
	win.attach(swmw); 
	win.attach(smplwin); win.attach(shape); win.attach(pnt); // middle
	win.attach(lnsh); win.attach(lns); win.attach(polys); win.attach(axsh); win.attach(rects); win.attach(txts); win.attach(imgs);
	win.attach(lin); win.attach(linstyl); win.attach(poly); win.attach(axs); win.attach(rect); win.attach(txt); win.attach(img); // bottom
	
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
