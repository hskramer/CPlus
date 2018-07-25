#include "../../std_lib_facilities.h"


struct Reading {
	int hour;
	double temp;

	Reading() :hour{0}, temp{0} {}
	Reading(int h, double t) :hour{h}, temp{t} {}
};

istream& operator>>(istream& is, Reading& r)
{
	int hour;
	double temp;
	
	is >> hour >> temp;
	if (!is)
		return is;
	
	r = Reading(hour, temp);
	return is;
}

ostream& operator<<(ostream& os, Reading& r)
{
	return os << r.hour << ' ' << r.temp << endl;
}

vector<Reading> read_file(const string& file_name)
{
	ifstream ifs{ file_name };
	if (!ifs) error("error opening file", file_name);

	vector<Reading>temps;
	Reading r;
	while (ifs >> r)
		temps.push_back(r);

	return temps;
}

void write_file(const vector<Reading>& r1, const vector<Reading>& r2, const string& file_name)
{
	ofstream ofs{ file_name };
	if (!ofs) error("error opening file", file_name);

	for (Reading r : r1)
		ofs << r;

	for (Reading r : r2)
		ofs << r;
	
}

int main()
try {
	string file1{ "" }, file2{ "" };
	cout << "Enter name of first file" << endl;
	cin >> file1;
	cout << "Enter name of seconf file" << endl;
	cin >> file2;

	vector<Reading>temps_one = read_file(file1);
	vector<Reading>temps_two = read_file(file2);
	write_file(temps_one, temps_two, "temp3.txt");

	return 0;
}
catch (exception& e)
{
	cerr << "error occurred " << e.what() << endl;
	return -1;
}
catch (...)
{
	cerr << "unkown exception occurred" << endl;
	return -2;
}