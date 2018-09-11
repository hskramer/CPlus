#include "Graph.h"
#include "Simple_window.h"
#include "chapter13.h"
#include <iostream>
#include <stdexcept>



int main()
try {
	
	
	 Simple_window win{ Point{15, 15}, 1200, 1200, "test  classes" };

	 Graph_lib::Ellipse elps{ Point{500, 250}, 150, 100 };
	 elps.set_color(Color::dark_green);
	 Graph_lib::Marks m{ "X" };

	 m.add(n(elps));
	 m.add(s(elps));
	 m.add(e(elps));
	 m.add(w(elps));
	 m.add(nw(elps));
	 m.add(ne(elps));
	 m.add(sw(elps));
	 m.add(se(elps));
	 m.add(c(elps));

	 Arcs arc1{ Point{100,100}, 100, 100, 0, 90 }; // definef it as Arcs windows has a header file wingdi.h with an Arc declaration
	
	 Box box1{ Point{550,550}, 450, 250 }; // select the top left corner and the length of your horizontal, vertical lines

	 Arrow arw1{ Point{200, 500}, Point{300, 170} }; // arrow tip always at start point and is fixed size
	 arw1.set_color(Color::red);
	 
	 box1.set_color(Color::dark_magenta);	 	 	 
	
	 arc1.set_color(Color::blue);

	 win.attach(m);
	 win.attach(elps);
	 win.attach(arc1);
	 win.attach(box1);
	 win.attach(arw1);

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