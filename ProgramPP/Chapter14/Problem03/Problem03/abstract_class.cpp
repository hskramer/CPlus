#include "../../std_lib_facilities.h"
#include <iostream>
#include <stdexcept>

/*
* Class and struct behave differently in structs and unions members are public by default so there is no need to use 
* public keyword them. When a class is specified all members are private by default so overriding a method does not give 
* you access to the an abstract base class unless you specify public in the derived class.
*/

struct SA {
	virtual void vf() = 0;
	void g() const{ cout << "Abstract struct SA function g()" << endl; }
};

struct SB : SA {
	void vf() { cout << "Derived struct SB with an override of vf()" << endl; }
	void g() const { cout << "Derived stuct SB override of g()" << endl; }
};

class A {
	virtual void class_vf() = 0;
	void class_g() const { cout << "Abstract class A function class_g()" << endl; } 
};

class B : A {
public: // public required in derived class in order to use the override functions
	void class_vf() { cout << "Derived class B override of function class_vf()" << endl; }
	void class_g() const { cout << "Derived class B override of function class_g()" << endl; }
};

class C : B {
public:
	void class_vf() { cout << "Derived class C override of function class_vf()" << endl; }
	void class_g() const { cout << "Derived class C override of function class_g()" << endl; }
};

int main()
try {

	// A a; error abstract class not accessible pure virtual function ....
	SB sb;
	sb.vf();
	sb.g();

	B b;
	b.class_vf();
	b.class_g();

	C c;
	c.class_vf();
	c.class_g();	

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error: " << endl;
	return -2;
}