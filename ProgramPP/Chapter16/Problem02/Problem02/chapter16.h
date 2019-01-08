// chapter 16 header file start of header guard 
#ifndef CHAPTER16_H
#define CHAPTER16_H

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

struct My_window : Window {

	My_window(Point xy, int w, int h, const string& title);

	void wait_for_button();

private:
	Button next_button;
	Button quit_button;
	bool button_pushed{ false };

	// actions
	void quit();
	void next();
};

struct My_Button : My_window {

	My_Button(Point xy, int w, int h, const string& title);

private:
	Out_box xy_out;
	Menu one;
	Menu two;
	Menu three;
	Menu four;

	// actions
	void b11();	void b21();	void b31();	void b41();

	void b12();	void b22();	void b32();	void b42();

	void b13();	void b23();	void b33();	void b43();

	void b14();	void b24();	void b34();	void b44();

	void point_xy(Point p);
};




#endif // !CHAPTER16_H
