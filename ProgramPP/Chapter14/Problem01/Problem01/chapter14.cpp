#include "chapter14.h"

namespace Graph_lib {

//--------------------------------------------------------------------------------------------------

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	Circle eye1{ Point{center().x - int(radius() / 2.5), center().y - int(radius() / 2.5)}, radius() / 5 };
	eye1.draw_lines();
	Circle eye2{ Point{center().x + int(radius() / 2.5), center().y - int(radius() / 2.5)}, radius() / 5 };
	eye2.draw_lines();
	Arcs smile{ Point{center().x - int(radius() / 2), center().y - int(radius() / 4)}, radius(), radius(), 210, 330 };
	smile.draw_lines();
}

//--------------------------------------------------------------------------------------------------

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	Circle eye1{ Point{center().x - int(radius() / 2.5), center().y - int(radius() / 2.5)}, radius() / 5 };
	eye1.draw_lines();
	Circle eye2{ Point{center().x + int(radius() / 2.5), center().y - int(radius() / 2.5)}, radius() / 5 };
	eye2.draw_lines();
	Arcs frown{ Point{center().x - int(radius() / 2), center().y + int(radius() / 2.5)}, radius(), radius(), 35, 145 };
	frown.draw_lines();
}

//--------------------------------------------------------------------------------------------------

void Smiley_Hat::draw_lines() const
{
	Polygon shat;
	shat.add(Point{ center().x - radius(), center().y - radius() });
	shat.add(Point{ center().x - radius(), center().y - int(radius() * 1.5)});
	shat.add(Point{ center().x - int(radius() / 2) , center().y - int(radius() * 1.5) });
	shat.add(Point{ center().x - int(radius() / 2), center().y - int(radius() * 2) });
	shat.add(Point{ center().x + int(radius() / 2), center().y - int(radius() * 2) });
	shat.add(Point{ center().x + int(radius() / 2), center().y - int(radius() * 1.5) });
	shat.add(Point{ center().x + radius(), center().y - int(radius() * 1.5) });
	shat.add(Point{ center().x + radius(), center().y - radius() });
	shat.draw_lines();
	
}

//--------------------------------------------------------------------------------------------------

void Frowny_Hat::draw_lines() const
{
	Polygon fhat;
	fhat.add(Point{ center().x - radius(), center().y - radius() });
	fhat.add(Point{ center().x - radius(), center().y - int(radius() * 1.5) });
	fhat.add(Point{ center().x - int(radius() / 2) , center().y - int(radius() * 1.5) });
	fhat.add(Point{ center().x - int(radius() / 2), center().y - int(radius() * 2) });
	fhat.add(Point{ center().x + int(radius() / 2), center().y - int(radius() * 2) });
	fhat.add(Point{ center().x + int(radius() / 2), center().y - int(radius() * 1.5) });
	fhat.add(Point{ center().x + radius(), center().y - int(radius() * 1.5) });
	fhat.add(Point{ center().x + radius(), center().y - radius() });
	fhat.draw_lines();
}

//--------------------------------------------------------------------------------------------------

}