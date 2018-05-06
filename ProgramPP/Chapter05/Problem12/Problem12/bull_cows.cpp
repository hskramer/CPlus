#include "../../std_lib_facilities.h"

vector<int>get_solution()
{
	int x{ 0 }, y{ 0 };
	vector<int>new_solution(4);
	
	srand(time(NULL));

	while (x < 4) {

		y = 0;
		new_solution[x] = rand() % 9 + 1; // range from 1 to 9
		while (y < 4) {
			if (new_solution[y] == new_solution[x] && x != y) {
				--x; // set x back one
				y = 0; // reset y
				break; // try again
			}
			else {
				++y; // check next number
			}
		}
		++x;
	}


	// check for duplicates 
	return new_solution;

}

// convert the guess into a vector of integers
vector<int>convert_to_digits(int g) {
	
	int digit{ 0 }; vector<int>v(4);
	for (int i = 0; i < v.size(); ++i)	{
		digit = g % 10;
		g = g / 10;
		v[i]=digit;
	}
	
	reverse(v.begin(), v.end());

	return v;
}

void bulls_cows() {
	// vector to hold the players guess and a bulls vector to keep track of bulls and there position
	vector<int>guess(4, 0); 
	int a{ 0 }; // hold guess before convert to digits

	vector<int>solution = get_solution();
	bool win = false;

	while (!win) {

		vector<int>bull(4, 0); vector<int>cow(4, 0);
		int bulls{ 0 }, cows{ 0 };

		cout << "Enter a 4 digit unique number: ";
		cin >> a;
		guess = convert_to_digits(a);

		// check for bulls and keep track of position so it's not counted as a cow later
		for (int i = 0; i < guess.size(); ++i) {
			if (solution[i] == guess[i])
				bull[i] = 2;
		}
	
		for(int i = 0; i < guess.size(); ++i)
			for(int j = 0; j < guess.size(); ++j)
			 if (solution[i] == guess[j] && bull[i] == 0 && cow[i] != 1)
					cow[i] = 1;
			
		
		
		for (int k = 0; k < bull.size(); ++k)
			if (bull[k] == 2)
				++bulls;

		for (int k = 0; k < cow.size(); ++k)
			if (cow[k] == 1)
				++cows;
	
		if (bulls == 4) {
			cout << "You guessed my number!\n";
			return;
		}
			
		// if number is guessed print out bulls/cows/
		cout << "bulls: " << bulls << " and cows: " << cows << "\n";		
	}
}

int main() 
try {
	
	bool quit{ false };
	char yn{ 0 };
	
	cout << "Lets play a game of Bulls and Cows.\n";

	while (!quit) {
		bulls_cows();

		cout << "Would you like to play another game (y/n)\n";
		cin >> yn;
		if (yn == 'n')
			quit = true;
	}

}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...) {
	cerr << "unknown exception\n";
	return 2;
}