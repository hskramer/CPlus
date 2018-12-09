#include "Simple_window.h"
#include "chapter14.h"
#include <iostream>
#include <stdexcept>

int main()
try {

	Simple_window win{ Point{15, 15}, 1400, 1000, "Standard Exception Hierarchy" };

	Text_Box excpt{ Point{650, 25}, 300, 150, "Exception" };
	Text_Box logic_e{ Point{300, 200}, 200, 100, "Logic error" };
	Text_Box runt_e{ Point{1025, 225 }, 200, 100, "Runtime error" };

	Text_Box dom_e{ Point{25, 425}, 150, 75, "Domain"};
	Text_Box invl_e{ Point{225, 425}, 150, 75, "Invalid" };
	Text_Box lngt_e{ Point{400, 425}, 150, 75, "Length" };
	Text_Box outr_e{ Point{575, 425}, 150, 75, "Out of range" };

	Text_Box rng_e{ Point{1225, 425}, 150, 75, "Range" };
	Text_Box ovr_e{ Point{1050, 425}, 150, 75, "Overflow" };
	Text_Box undr_e{ Point{875, 425}, 150, 75, "Underflow" };

	Arrow log_ex{ Point{655,155},Point{490, 210},  true };
	Arrow run_ex{ Point{945,155}, Point{1045,225}, true };

	Arrow dom_l{ Point{310, 295}, Point{170, 430}, true };
	Arrow inv_l{ Point{350, 300}, Point{300, 425}, true };
	Arrow lng_l{ Point{415, 300}, Point{450, 425}, true };
	Arrow out_l{ Point{490, 290}, Point{585, 432}, true };

	Arrow und_r{ Point{1030, 315}, Point{950, 425}, true };
	Arrow ovf_r{ Point{1125, 325}, Point{1125, 425}, true };
	Arrow rng_r{ Point{1220, 315}, Point{1300, 425}, true };

	win.attach(excpt);
	win.attach(logic_e); win.attach(runt_e); win.attach(log_ex);
	win.attach(dom_e); win.attach(invl_e); win.attach(lngt_e); win.attach(outr_e); win.attach(run_ex);
	win.attach(dom_l); win.attach(inv_l); win.attach(lng_l); win.attach(out_l);
	win.attach(und_r); win.attach(ovf_r); win.attach(rng_r);
	win.attach(rng_e); win.attach(ovr_e); win.attach(undr_e);
	win.wait_for_button();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error" << endl;
	return -2;
}