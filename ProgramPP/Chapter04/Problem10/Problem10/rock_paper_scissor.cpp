#include "../../std_lib_facilities.h"

int computer_score{ 0 };
int person_score{ 0 };
int draws{ 0 };
int games{ 0 };

int computer_pick()
{
	// I choice mod 3 because it return 0,1,2 which represent rock,paper,scissor
	// Initial version had a vector solution changed it later.
	int num{ 0 };
	num = rand() % 100;
	return (num % 3);
}

// used a sepeate function to test for winner decided it was too big to include in while statement 
// this makes the program easier to read 
void find_winner(int p, int c)
{
	++games;
	// first three if statements check for player wins
	if (p == 0 && c == 2)
	{
		cout << "You win rock breaks scissors\n";
		++person_score;
		return;
	}
	else if (p == 1 && c == 0)
	{
		cout << "You win paper covers rock\n";
		++person_score;
		return;
	}
	else if (p == 2 && c == 1)
	{
		cout << "You win scissors cut paper\n";
		++person_score;
		return;
	}
	else if (p == 2 && c == 0)
	{
		cout << "I win rock breaks scissors\n";
		++computer_score;
		return;
	}
	// last three if statements check for computer wins last else must be a draw
	else if (p == 0 && c == 1)
	{
		cout << "I win paper covers rock\n";
		++computer_score;
		return;
	}
	else if (p == 1 && c == 2)
	{
		cout << "I win scissors cut paper\n";
		++computer_score;
		return;
	}
	else
	{
		++draws;
		cout << "Draw\n";
		return;
	}

}

int main(void)
{
	char rps;
	int y{ 0 }, z{ 0 };

	cout << "Lets play a game of rock paper or scissors.\n";
	cout << "Enter r, p, s or  to quit\n";

	z = computer_pick();
	while (cin >> rps)
	{
		
		switch (rps)
		{
		case 'r':
			find_winner(0, z);
			break;
		case 'p':
			find_winner(1, z);
			break;
		case 's':
			find_winner(2, z);
			break;
		case 'q':
			cout << "You won " << person_score << " games and I won " << computer_score <<" and there were "<<draws<<" draws\n";
			cout << "We played a total of " << games<<" games";
			return EXIT_SUCCESS;
			break;
		default:
			cout << "Invalid entry";
			return EXIT_SUCCESS;
		}
		z = computer_pick();
	}

}