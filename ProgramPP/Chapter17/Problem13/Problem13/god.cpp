#include "gods.h"

Link* Link::insert(Link* n) {

	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->succ = this;

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

Link* Link::erase() {
 
	if (this == nullptr) return nullptr;
	if (succ) {
		if (prev)
			succ->prev = prev;
		else
			succ->prev = nullptr;
	}
	if (prev) {
		if (succ)
			prev->succ = succ;
		else
			prev->succ = nullptr;
	}
	return succ;
}

Link* Link::find(const string& s) {

	Link* p = this;
	while (p) {
		if (p->gods.name == s) 
			return p;
		p = p->succ;
	}

	return nullptr;
}

const Link* Link::find(const string& s) const {

	const Link* p = this;
	while (p) {
		if (p->gods.name == s)
			return p;
		p = p->succ;
	}

	return nullptr;
}

Link* Link::advance(Link* p, int n) {

	if (p == nullptr) 
		return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr)
				return nullptr;
			p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr) 
				return nullptr;
			p = p->prev;
		}
	}

	return p;
}

Link* select(Link* l, string god) {

	Link* p = l->find(god);

	if (p) {
		if (p == l && p->next())
			l = p->next();
		else
			l = nullptr;
		p->erase();
		return p;
	}

	return nullptr;	
}


Link* Link::add_ordered(Link* n) {

	if (n == 0) 
		return this;
	if (this == 0) {
		n->succ = 0;
		n->prev = 0;
		return n;
	}

	if (n->gods.name < gods.name) { // at head of list
		Link* p = insert(n);
		return p;
	}

	Link* p = this; // the object it was called from

	while (n->gods.name >= p->gods.name) {
		if (p->succ == 0) { // end of list so need to add otherwise use insert outside of while loop
			p->add(n);
			return this;
		}
		p = p->succ;
	}

	p->insert(n);

	return this;
}

void print_all(Link* p) {

	while (p) {
		cout << p->gods.name << ' ' << p->gods.mythology << ' ' << p->gods.weapon << ' ' << p->gods.vehicle << '\n';
		p = p->next();
	}
}

int main()
try {


	Link* gods = new Link{ God{"Odin", "Norse", "Eight-legged flying horse named Sleipner", "Spear called Gungnir"} };
	gods = gods->insert(new Link{ God{"Thor", "Nores", "Chariot", "Hammer"} });
	gods = gods->insert(new Link{ God{"Loki", "Norse", "", "Trickster"} });
	gods = gods->insert(new Link{ God{"Njord", "Nores", "", "Calm the Seas"} });

	gods = gods->insert( new Link{ God{"Zeus", "Greek", "", "lightning"} });
	gods = gods->insert(new Link{ God{"Atlas", "Greek", "", "Carry the World"} });
	gods = gods->insert(new Link{ God{"Morpheus", "Greek", "", "Take any human form"} });
	gods = gods->insert(new Link{ God{"Poseidon", "Greek", "", "God of sea, eathquakes, storms"} });

	print_all(gods);


	Link* norse_gods = nullptr;
	norse_gods = norse_gods->add_ordered(select(gods, "Njord"));
	norse_gods = norse_gods->add_ordered(select(gods, "Odin"));
	norse_gods = norse_gods->add_ordered(select(gods, "Thor"));
	norse_gods = norse_gods->add_ordered(select(gods, "Loki"));

	Link* greek_gods = nullptr;
	greek_gods = greek_gods->add_ordered(select(gods, "Zeus"));
	greek_gods = greek_gods->add_ordered(select(gods, "Morpheus"));
	greek_gods = greek_gods->add_ordered(select(gods, "Atlas"));
	greek_gods = greek_gods->add_ordered(select(gods, "Poseidon"));

	cout << "Norse gods" << '\n';
	print_all(norse_gods);

	cout << "Greek gods" << '\n';
	print_all(greek_gods);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}