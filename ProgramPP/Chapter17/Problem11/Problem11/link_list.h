#include "../../std_lib_facilities.h"

class Link {
public:
	string value;

	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		:value{ v }, prev{ p }, succ{ s } {}


	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase(Link* p);

	Link* find(const string& s);
	Link* advance(Link* p, int n);

	Link* next() const { return succ; }
	Link* previous() const { return prev; }

	const Link* find(const string& s) const;

private:
	Link* prev;
	Link* succ;
};

