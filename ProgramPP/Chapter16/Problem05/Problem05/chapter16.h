// chapter 16 header file start of header guard 
#ifndef CHAPTER16_H
#define CHAPTER16_H

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include <random>

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

//----------------------------------------------------------------------------------------------------------------------------------

namespace Graph_lib {

	struct Add_shape : Window {

		Add_shape(Point xy, int w, int h, const string& title);
		
	private:
		Button quit_button;
		In_box x_coord;
		In_box y_coord;
		In_box length;
		Menu shape_menu;
		vector_ref<Shape> vec_shape;
		Button shape_button;
	
		// actions
		void quit();
		void name_shape(string);
		// draw shape and make sure it will fit in window
		void draw_shape(string, int, int, int);	
	};

//----------------------------------------------------------------------------------------------------------------------------------

	struct Move_shape : Window{

		Move_shape(Point xy, int w, int h, const string& title);

	private:
		Button quit_button;
		Button next_button;
		Out_box coord;
		vector_ref<Shape> vec_circ;
		Button circle;

		// actions
		void quit();
		void next();
		Point new_coord();

	};


}

#endif // !CHAPTER16_H
