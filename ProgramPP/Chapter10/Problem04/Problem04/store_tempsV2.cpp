#include "../../std_lib_facilities.h"

const int  min_temp = -90;
const int max_temp = 210;

struct Reading {
	int hour;
	char scale;
	double temperature;

	Reading(int h, double t, char c)
		:hour{ h }, temperature{ t }, scale{ c } {}
};

ostream& operator <<(ostream& os, Reading& r)
{
	return os << r.hour << ' ' << setprecision(4) << r.temperature << r.scale << '\n';
}

vector<Reading> fill_temps()
{
	int hour{ 0 };
	char cf{ 0 };
	double temp{ 0.0 };
	vector<Reading>r;

	for (int i = 0; i < 50; ++i) {
		hour = randint(0, 23);
		temp = randint(min_temp, max_temp) / double(2.2);
		randint(0, 1) ? cf = 'F' : cf = 'C';
		r.push_back(Reading{ hour, temp, cf });
	}
	return r;
}

void write_file(vector<Reading>& temps, const string& oname)
{
	ofstream ofs{ oname };
	if (!ofs) error("erro opening file ", oname);

	for (Reading r : temps)
		ofs << r;
}

int main()
try {

	string file_name = "raw_temps.txt";
	vector<Reading> temps = fill_temps();
	write_file(temps, file_name);
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