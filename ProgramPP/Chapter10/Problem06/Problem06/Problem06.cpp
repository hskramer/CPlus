#include "roman.h"

using namespace Roman;


int main()
try {

	Roman_int r{ 0 };	
	cin >> r;

	cout << r;
	
	return 0;
}
catch (exception& e)
{
	cerr << "error occured " << e.what() << endl;
	return -1;
}
catch (...)
{
	cerr << "unkown exception occured" << endl;
	return -2;
}