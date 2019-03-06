#include "../../std_lib_facilities.h"

struct God {

	God(const string& n, const string& m, const string& v, const string& w)
		: name{ n }, mythology{ m }, vehicle{ v }, weapon{ w } {}

	string name;
	string mythology;
	string vehicle;
	string weapon;
};

class Link {
public:
	God gods;

	Link(God g, Link* p = nullptr, Link* s = nullptr)
		:gods{ g }, prev{ p }, succ{ s } { }

	Link* insert(Link* n);
	Link* erase(Link* n);

	Link* next() const { return succ; }
	Link* previous() const { return prev; }

private:
	Link* prev;
	Link* succ;
};