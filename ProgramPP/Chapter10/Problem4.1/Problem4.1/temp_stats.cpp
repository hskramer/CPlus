#include "../../std_lib_facilities.h"

struct Reading {
	int hour;
	char scale;
	double temperature;

	Reading() :hour{ 0 }, temperature{ 0 }, scale{ 0 } {}
	Reading(int h, double t, char c)
		:hour{h}, temperature{t}, scale{c} {}
};

istream& operator>>(istream& is, Reading& r)
{
	int hour;
	char scale;
	double temperature;
	char ch1;

	is >> hour >> temperature >> scale;
	if (!is)
		return is;
	scale == 'F' ? temperature : temperature = temperature * 1.8 + 32;

	r = Reading(hour, temperature, 'F');
	return is;
}

ostream& operator<<(ostream& os, Reading& r)
{
	return os << r.hour << ' ' << r.temperature << r.scale << endl;
}

void read_file(vector<Reading>& temps, const string& name)
{
	ifstream ist{ name };
	if (!ist) error("error opening file ", name);

	Reading r;
	while (ist >> r)
		temps.push_back(r);
}

void compute_stats(vector<Reading>& temps)
{
	vector<double>t;
	double mean{ 0 }, sum{ 0 }, median{ 0 };
	int count{ 0 };

	for (Reading r : temps) {
		sum += r.temperature;
		++count;
		t.push_back(r.temperature);
	}
	mean = sum / count;
	sort(t.begin(), t.end());
	median = t[count / 2];

	cout << "mean temperature: " << mean << " median: " << median << endl;

}

int main()
try {

	vector<Reading>temperature;
	string file_name = "raw_temps.txt";

	read_file(temperature, file_name);

	//for (Reading r : temperature) used to double check conversion is working and it is.
	//	cout <<r.temperature<< r.scale << endl;

	compute_stats(temperature);

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