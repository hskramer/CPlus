#include "money.h"

using namespace Monetary;

void test_solution14()
{
	Money m1{ 121, 1 }, m2{ 31 }; // $121.01 and $0.31 		

	cout << m1 << " plus " << m2 << " equals " << m1 + m2 << endl;

	// haven't decided if I want to allow negative amounts in an accounting system debts are required for now leave it be
	cout << m1 << " minus " << m2 << " equals " << m1 - m2 << endl;

	cout << " times 3  equals " << m1 << 3 * m1 << endl;

	cout << m2 << "4 time  equals " << m2 * 4 << endl;

	cout << m1 << " divided by 7 equals " << m1 / 7 << endl;

	Money i{ 0 };// largest amount supported is a little over 21 Million dollars when cents are used this makes sence when represented in pennies
				 // that's over 2.1 billion pennies, long int is 4 bytes.
//	cout << "Enter money using x...x.xx format" << endl;
//	cin >> i;
//	cout << "You entered " << i << endl;

}

int main()
try {
	
	//test_solution14();

	Money us{ Money::USD, 200,20 }, eu{ Money::EUR, 100,10 }, jp{ Money::YEN, 35000,29 };

	cout << us + eu << endl; // converts the second currency into the first then adds and ouputs amount in first 
	cout << eu + jp << endl; // adding and subtracting currency working 
	cout << jp - us << endl;
	cout << 2 * jp << endl;
	cout << eu / 4 << endl;
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}
