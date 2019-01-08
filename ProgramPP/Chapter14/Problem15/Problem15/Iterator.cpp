#include "iterator.h"


Vector_iterator::Vector_iterator(vector<double> vv) :  v{vv}
{
}

//---------------------------------------------------------------------------------------------------

 double* Vector_iterator::next() {	

	if (!v.empty()) {
		if (i == v.size()) i = 0;
		elem = &v[i++];		
	}
	else {
		return 0;
	}	
 	return elem;	
}

 //---------------------------------------------------------------------------------------------------

void Vector_iterator::print(Iterators& iter) {
	
	if(v.empty())
		cout << "Vector is empty" << endl;
	else {
		for(int j = 0; j < v.size(); ++j)
		cout << "The next element is: " << *iter.next() << endl;
	}
}

//---------------------------------------------------------------------------------------------------

List_iterator::List_iterator(list<double> ll) : ls{ ll }
{
}

//---------------------------------------------------------------------------------------------------

double* List_iterator::next() {

	if (!ls.empty()) {
		list<double>::iterator it = std::next(ls.begin(), i);
		*elem = *it;
		++i;
	}	
	else {
		return 0;
	}
	return elem;
}

//---------------------------------------------------------------------------------------------------

void List_iterator::print(Iterators& iter) {

	if (ls.empty())
		cout << "List is empty" << endl;
	else {
		for(int j = 0; j < ls.size(); ++j)
		cout << "The next element is: " << *iter.next() << endl;
	}
}