#include "std_lib_facilities.h"


int main(void)
{
	string  first_name{};
	string  friend_name{};
	char	friend_sex{ 0 };
	int		age{ 0 };


	cout << "Please enter first name of the person you want to write to.\n";
	cin >> first_name;
	cout << "Dear " << first_name << ",\n";

	cout << "    How are you ?\n" << "When you arrive I'll meet you at the aiport.\n";
	cout << "See you in a couple of days.\n";
	cout << "Is your friend male or female(m/f)?\n";
	cin >> friend_sex;
	cout << "Whats the name your friend?\n";
	cin >> friend_name;
	cout << "\nHave you seen " << friend_name << " lately?\n";
	cout << "How old is your friend?\n";
	cin >> age;
	cout << "So your friend is " << age << " years old.\n";
	

	if (age <= 0)
		simple_error("you're kidding!");
	if (age >= 110)
		simple_error("you're kidding!");


	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";

	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	return 0;
}