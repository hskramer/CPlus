#include "../../std_lib_facilities.h"

void write_sorted_nums(const string& name)
{
	ofstream ofs{ name.c_str(), ios::out };
	if (!ofs) error("ofstream error opening file ", name);

	ifstream ifs{ name.c_str(), ios::in };
	if (!ifs) error("ifstream error opening file ", name);

	int rnum{ 0 };
	cout << "How many random numbers do you want?\n";
	cin >> rnum;

	srand(time(NULL));

	for (int i = 0; i < rnum; ++i) { // wanted a way to check solution with large number of entries without typing in manually
		if (i > 80 && i % 80 == 0)
			ofs << '\n';
		ofs << rand() % 25 + 1 << ' ';		
	}
	ofs << flush; // this is the key to creating a new file to read and write from

	vector<int>vint;
	int i{ 0 };

	while (ifs >> i)
		vint.push_back(i);

	ifs.close();// also read that not closing a file leaves data in ram not certain though
	sort(vint.begin(), vint.end());

	int cnt{ 1 }; 	// if the number of entries exceeds a line this fails sometime on less than that
	for (int i = 0; i < vint.size(); ++i) {
		if (i == 0 || vint[i - 1] != vint[i]) {
			if (cnt > 1)
				cout << '\t' << cnt;
			cout << '\n';
			cnt = 1;
			cout << vint[i];			
		}
		else
			++cnt;			
	}	

}

int main()
try {
	string file{ "" };

	cout << "Name of file to read\n";
	cin >> file;
	
	write_sorted_nums(file);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}