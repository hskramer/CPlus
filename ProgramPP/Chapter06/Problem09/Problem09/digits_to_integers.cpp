#include "../../std_lib_facilities.h"

vector<string>words;

void initialize_words()
{
	words.push_back("thousand");
	words.push_back("hundred");
	words.push_back("ten");
	words.push_back("one");
}

// chose to do my error checking in this function since its the first one to see the vector

int convert_to_integer(vector<int> v)
{
	int integer{ 0 };

	if (v.size() > 4)
		error("number exceeds 10,000");

	if (v.size() == 0)
		error("number not entered");

	if (v[0] == 0)
		error("zero can't be converted");

	if (v[0] == -3)
		error("negative number entered");

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] < 0 || v[i] > 9)
			error("error invalid character");
		else
			integer = integer * 10 + v[i];
	}

	return integer;
}

char print_sentence(vector<int> v, int n)
{
	char q{ 0 }; // need to see if we are doing another number if so we need to clear the vector
	
	cout << n << " is ";
	for (int i = 0; i < v.size(); ++i) {	 // start at the end of the vector then subtract the size giving us the index of the needed word
		cout << v[i] << " " << words[i + 4 - v.size()];//	as i increases we move forward one word
		if (v[i] > 1)
			cout << "s";
		if (i < v.size() - 1)
			cout << " and ";
	}
	cout << "\n";
	
	cout << "Try another? (y/n)\n";
	cin >> q;
	return q;
}

int main()
try {
	bool convert = true;	char n{ 0 }, yn{ 0 };
	vector<int>number;		int num{ 0 };

	initialize_words();

	cout << "Enter a positive number between 1 and 9999 followed by a ? enter.\n";
	cout << "Enter q to quit\n";

	while (convert) {
		cin>>n;
		if (n == 'q')
			convert = false;
	    else if (n == '?') {
			num = convert_to_integer(number);
			yn = print_sentence(number, num);
			if (yn == 'y')
				number.clear();
			else
				convert = false;
		}
		else
			number.push_back(n - '0'); // 0 is ascii code 48 and the characters 1...9 have ascii codes 49...47 subtracting 48 gives the integer value		
	}

}
catch (exception& e)
{
	cerr << "error: " << e.what()<< "\n";
	return 1;
}
catch (...)
{
	cerr << "unkown exception occured\n";
	return 2;
}