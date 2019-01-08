#include "../../std_lib_facilities.h"


class Iterators {
public:
	virtual double* next() = 0;	
	virtual void print(Iterators& iter) = 0;

	virtual ~Iterators() {}

protected:
	Iterators() {}
	double* elem = new double;
	int i = 0;
};

//---------------------------------------------------------------------------------------------------

class Vector_iterator : public Iterators {
public:
	Vector_iterator() {}
	Vector_iterator(vector<double> v);

	void print(Iterators& iter);

	double* next();	 // returns a pointer to the next element is a vector or a list

protected:
	vector<double> v;
};

//---------------------------------------------------------------------------------------------------

class List_iterator : public Iterators {
public:
	List_iterator() {}
	List_iterator(list<double> ls);

	void print(Iterators& iter);

	double* next();

protected:
	list<double> ls;
	double* it = new double;
};

//---------------------------------------------------------------------------------------------------