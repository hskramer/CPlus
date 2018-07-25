#include "../../std_lib_facilities.h"

enum Base {
	zero, decimal, octal, hexadecimal
};

void output_base(Base b, int x)
{
	switch (b) {
	case zero:
		cout << "zero is " << '\t' << '\t' << "zero in all three bases" << '\n';
		break;
	case decimal:
		cout << dec << x << " decimal" << '\t' << '\t' << x << " decimal" << '\n';
		break;
	case octal:
		cout << oct << x << " octal" << '\t' << '\t' <<dec<< x << " decimal" << '\n';
		break;
	case hexadecimal:
		cout << hex << x << " hexadecimal" << '\t' << '\t' <<dec<< x << " decimal" << '\n';
		break;

	default:
		error("not a valid base", x);
	}
}

int main()
try {
	
	cout << "Enter numbers in either decima, octal or hexadecimal using 0x for hex and 0 for octal" << '\n';

	cin.unsetf(ios::dec); cin.unsetf(ios::oct); cin.unsetf(ios::hex); // clear the flags to allow input of hex and octal
	char ch{ -1 };
	int a{ 0 };

	while (cin.get(ch)) {
		if (ch == '0') { // don't forget your quotes!!
			cin.get(ch);
			if (ch == 'x') {
				cin >> hex >> a;
				output_base(hexadecimal, a);
			}
			else if(isdigit(ch)){
				cin.putback(ch); // unget works while putback does not did some reading finally understand the difference.
				cin >> oct >> a; // putback changes the pointer in the string buffer so when cin comes along it will only retrieve from the point onward
				output_base(octal, a); // where as unget leaves the pointer alone so you can retrieve everything from the original place onward.
			}
			else {
				cin.unget();
				output_base(zero, 0);
			}
		} 
		else if (isdigit(ch)) {
			cin.unget();
			cin >> dec >> a;
			output_base(decimal, a);
		}
	}

	return 0;

}
catch (exception& e) {
	cerr << "error occurred " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error occurred" << '\n';
	return -2;
}