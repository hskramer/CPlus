#include "std_lib_facilities.h"


int main(void)
{
	string  first_name{};
	string  friend_name{};

	cout << "Please enter first name of the person you want to write to.\n";
	cin >> first_name;
	cout << "Dear " << first_name << ",\n";

	cout << "    How are you ?\n" << "When you arrive I'll meet you at the aiport.\n";
	cout << "See you in a couple of days.\n";
	cout << "Whats the name your friend?\n";
	cin >> friend_name;
	cout << "\nHave you seen " << friend_name << " lately?";

	return 0;
}