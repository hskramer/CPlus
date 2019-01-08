// chapter 16 header file start of header guard 
#ifndef CHAPTER16_H
#define CHAPTER16_H

//#include <FL/Fl_Widget.H>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include <random>
#include <ctime>

struct My_window : Window {

	My_window(Point xy, int w, int h, const string& title);

	void wait_for_button();

private:
	Button next_button;
	Button quit_button;
	bool button_pushed{ false };

	// actions
	void quit();
	bool next();
};

//----------------------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------------------

namespace Graph_lib {

	struct Img_button : My_window {

		Img_button(Point xy, Point ixy, int w, int h, const string& img_name); // using the image name for screen name

		void rmove();
		
	private:
		Image img;
		vector_ref<Button> vec_button;
	};

	inline int rand_int(int min, int  max);
	
}

#endif // !CHAPTER16_H
