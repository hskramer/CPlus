// chapter 16 header file start of the header guard 
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


#endif // !CHAPTER16_H
