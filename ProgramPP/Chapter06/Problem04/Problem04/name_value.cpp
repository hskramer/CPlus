#include "../../std_lib_facilities.h"

class Name_value {
public:
	string name;	// string for holding persons name
	int	score;		// integer for holding their score

	Name_value(string, int);
};


Name_value::Name_value(string nm, int scr)
	:name(nm), score(scr) {}

void check_duplicates(vector<Name_value>nameVec, string name)
{
	for (int i = 0; i < nameVec.size(); ++i)
		if (nameVec[i].name == name)
			error("duplicate name entered", name);
}

int main()
try {

	vector<Name_value> name_score;
	string nm{};
	int scr{ -1 };

	cout << "Enter a name followed by a score end with 'NoName' 0 \n";

	while (cin >> nm >> scr) {
		if (!name_score.empty()) {
			check_duplicates(name_score, nm);
		}
		name_score.push_back(Name_value(nm, scr));
		if (nm == "NoName" && scr == 0) {
			cout << "Names and scores entered:\n";
			break;
		}			
	}

	for (int i = 0; i < name_score.size() - 1; ++i)
		cout << name_score[i].name << name_score[i].score << "\n";

}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...) {
	cerr << "unknown exception!\n";
	return 2;
}