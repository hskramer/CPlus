#include "std_lib_facilities.h"


int main(void)
{
	string  firstName{};
	
	cout << "Please enter first name of the person you want to write to.\n";
	cin >> firstName;
	cout << "Dear " << firstName << ",\n";

	cout << "    How are you ?\n" << "When you arrive I'll meet you at the aiport.\n";
	cout << "See you in a couple of days.\n";

	return 0;
}