#include "../../std_lib_facilities.h"

const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

vector<char>get_solution()
{
	int x{ 0 }, y{ 0 };
	vector<char>new_solution(4);

	srand(time(NULL));

	while (x < 4) {

		y = 0;
		new_solution[x] = alphabet[rand() % 26]; // randomly select a char from alphabet
		while (y < 4) {		// check for duplicates
			if (new_solution[y] == new_solution[x] && x != y) {
				--x;	// set x back one
				y = 0; // reset y and try again 
				break;
			}
			else {
				++y; // check next character
			}
		}
		++x;
	}

	return new_solution;
}

vector<char>string_to_char(string str)
{
	vector<char>v(4); // vector to hold the characters
	for (int i = 0; i < v.size(); ++i)
		v[i] = str[i];

	return v;
}

void bulls_cows()
{
	vector<char>guess(4);
	string a{ 0 };
	bool win = false;

	vector<char>solution = get_solution();

	while (!win) {

		vector<int>bull(4, 0); vector<int>cow(4, 0);
		int bulls{ 0 }, cows{ 0 };

		cout << "Enter a unique four letter guess: ";
		cin >> a;
		guess = string_to_char(a);

		// check for bulls and keep track of position so it's not counted as a cow later
		for (int i = 0; i < guess.size(); ++i) {
			if (solution[i] == guess[i])
				bull[i] = 2;
		}

		// check for cows we know from above not to count a bull as a cow
		for (int i = 0; i < guess.size(); ++i)
			for (int j = 0; j < guess.size(); ++j)
				if (solution[i] == guess[j] && bull[i] == 0 && cow[i] != 1)
					cow[i] = 1;


		for (int k = 0; k < bull.size(); ++k)
			if (bull[k] == 2)
				++bulls;

		for (int k = 0; k < cow.size(); ++k)
			if (cow[k] == 1)
				++cows;

		if (bulls == 4) {
			cout << "You guessed my letters!\n";
			return;
		}

		// if number is guessed print out bulls/cows/
		cout << "bulls: " << bulls << " and cows: " << cows << "\n";
	}
}


int main()
try {

	bool play{ true };
	char yn{ 0 };

	cout << "Lets play a game of Bulls and Cows with four lower case unique letters\n";

	while (play) {
		bulls_cows();

		cout << "Would you like to play another game (y/n)\n";
		cin >> yn;
		if (yn == 'n')
			play = false;
	}


}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...) {
	cerr << "unkown exception\n";
	return 2;
}