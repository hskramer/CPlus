#include "../../std_lib_facilities.h"

const int  min_temp = - 100;
const int max_temp = 210;

struct Reading {
	int hour;			  // 24 hour [0:23]
	double temperature;	 // in Fahrenheit
	Reading(int h, double t)
		:hour{h}, temperature{t} {}
};

ostream& operator<<(ostream& os, Reading& r)
{
	return os << r.hour << ' ' << setprecision(4)<<r.temperature << '\n';
}

vector<Reading> fill_temps()
{
	int hour{ 0 };
	double temp{ 0.0 };
	vector<Reading>r;

	for (int i = 0; i < 50; ++i) {
		hour = randint(0, 23);
		temp = randint(min_temp, max_temp) / double(2.2); // produces a broad and reasonble range of temperatures as doubles
		r.push_back(Reading{ hour,temp });
	}
	return r;
}

void write_file(vector<Reading>& temps, const string& oname)
{
	ofstream ofs{ oname };
	if (!ofs) error("can't open file ", oname);

	for (Reading r : temps)
		ofs << r;
}

int main()
try {

	vector<Reading>temps = fill_temps();

	write_file(temps, "raw_temps.txt");
}
catch (exception& e)
{
	cerr << "error occured " << e.what() << endl;
	return -1;
}
catch (...)
{
	cerr << "unkown exception occured" << endl;
	return -2;
}