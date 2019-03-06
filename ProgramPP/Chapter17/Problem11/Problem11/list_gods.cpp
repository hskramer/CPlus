#include "link_list.h"



Link* Link::insert(Link* n) {

	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->succ = this;

	// remember "this"->prev
	if (prev) prev->succ = n;
	n->prev = prev;
	prev = n;
	return n;
}

Link* Link::add(Link* n) {

	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->prev = this;
	
	// rember "this"->succ
	if (succ) succ->prev = n;
	n->succ = succ;
	succ = n;
	return n;
}

Link* Link::erase(Link* p) {

	if (p == nullptr) return nullptr;
	if (p->succ) p->succ->prev = p->prev;
	if (p->prev) p->prev->succ = p->succ;

	return p->succ;
}

Link* Link::find(const string& s) {

	Link* p = this;
	while (p) {
		if (p->value == s) return p;
		p = p->next();
	}
	
	return nullptr;
}

const Link* Link::find(const string& s) const {

	const Link* p = this;
	while (p) {
		if (p->value == s) return p;
		p = p->next();
	}

	return nullptr;
}

Link* Link::advance(Link* p, int n) {

	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}

	return p;
}

void print_all(Link* p) {

	cout << "{";
	while (p) {
		cout << p->value;
		if (p = p->next()) cout << ",";
	}
	cout << "}";
}

int main()
try {

	Link* norse_gods = new Link{ "Thor" };
	norse_gods = norse_gods->add(new Link{ "Odin" });
	norse_gods = norse_gods->add(new Link{ "Freia" });


	print_all(norse_gods);
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}