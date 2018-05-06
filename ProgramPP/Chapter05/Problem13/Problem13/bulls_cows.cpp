#include "../../std_lib_facilities.h"

vector<int>answer;

void bulls_cows();

// random generator function:
int myrandom(int i) { return rand() % i; }

// this generates random numbers 1-9 with uniform distribution
void initialize_game()
{
	int seed{ -1 }; // answer to a part of the question but used time(null) for games played after initial start
	
	cout << "Please enter a number before we begin to help me get started\n";
	cin >> seed;
	srand(seed); // seed so it doesn't play same game each time it starts
	
	vector<int>one_nine = { 1,2,3,4,5,6,7,8,9 };

	random_shuffle(one_nine.begin(), one_nine.end());	// bulls/cows played with four unique numbers only way I could think of doing this
	random_shuffle(one_nine.begin(), one_nine.end(), myrandom);
	for (int i = 1; i < 5; ++i)
		answer.push_back(one_nine[i]);

	bulls_cows();
}

void get_new_number()
{	
	vector<int>one_nine = { 1,2,3,4,5,6,7,8,9 };
	time_t t;

	srand(time(&t));
	
	random_shuffle(one_nine.begin(), one_nine.end());
	random_shuffle(one_nine.begin(), one_nine.end(), myrandom);
	for (int i = 0; i < 4; ++i)
		answer.push_back(one_nine[i]);

}

void convert_to_digits(vector<int>& v, int g) {
	// if guess to long you receive a range error in real game I would trap and continue 

	int digit = g;
	for (int i = 0; i < 4; ++i) {
		digit = g % 10;
		g = g / 10;
		v[i] = digit;
	}
	reverse(v.begin(), v.end());
}

void bulls_cows() {
	// one vector to hold the players guess, the answer and the response
	vector<int>guess{ 0,0,0,0 };  vector<int>response{ 0,0,0,0 }; // 0 = nothing, 1 = cow, 2 = bull
	int a{ 0 };
	bool win = false;

	cout << "Please enter your first guess\n";	

	while (!win) {
		cin >> a;
		convert_to_digits(guess, a);

		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 4; ++j) {
				if (answer[i] == guess[j] && i == j) // check for a bull
					response[i] = 2;
				else if (answer[i] == guess[j] && i != j)	// check for a cow
					if (response[i] == 2)
						continue;
					else
						response[i] = 1;
			}
		}

		int bulls{ 0 }; // count bulls then check for win
		for (int i = 0; i < 4; ++i)
			if (response[i] == 2)
				++bulls;

		// check for win using count
		if (bulls == 4) {
			cout << "You guessed my number!\n";
			win = true;	
		}

		// if number is guessed don't print out bulls else respond
		if (!win) {
			for (int k = 0; k < response.size(); ++k) { // respond to guess
				if (response[k] == 1)
					cout << "Cow ";
				else if (response[k] == 2)
					cout << "Bull ";
			}
		}

		// check for no matches
		int cows{ 0 };
		for (int i = 0; i < 4; ++i)
			if (response[i] == 1)
				++cows;

		if (bulls == 0 && cows == 0)
			cout << "Sorry no matches.";

		cout << "\n"; // new line need after printing out bulls and cows or no match

		//reset response for next guess
		for (int i = 0; i < 4; ++i)
			response[i] = 0;
	}	
}

int main()
try {
	char yn;
	bool play = true;

	cout << "Lets play a game of Bulls and Cows\n";
	initialize_game();

	while (play) {
		cout << "Would you like to play another game (y/n)\n";
		cin >> yn;
		if (yn == 'n') 
			break;
		else {
			get_new_number();
			bulls_cows();
		}
	}
}
catch(exception& e) {
	
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch(...) {

	cerr << "unkown exception\n";
	return 2;
}