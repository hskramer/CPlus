#include "../../std_lib_facilities.h"

vector<string>names;
vector<int>scores;

void check_duplicate(string n)
{
	for(int i = 0; i < names.size(); ++i)
		if (names[i] == n)
		{
			cout << "Name entered twice exiting\n";
			exit(1);
		}	
}

int main(void)
{
	string name;
	int score;

	cout << "Enter a name followed by a score end with 'NoName' 0 \n";

	while (cin >> name >> score)
	{
		if (!names.empty())
		{
			check_duplicate(name);
		}

		names.push_back(name);
		scores.push_back(score);

		if (name == "NoName" && score == 0)
			break;
	}

	cout << "\n";
	for (int i = 0; i < names.size() - 1; ++i)
		cout << names[i] <<" "<< scores[i] << "\n";

	return EXIT_SUCCESS;

}