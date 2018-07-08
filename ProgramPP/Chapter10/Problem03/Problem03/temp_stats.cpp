#include "../../std_lib_facilities.h"


struct Reading {
	int hour;			  // 24 hour [0:23]
	double temperature;	 // in Fahrenheit
	Reading()
		:hour{ 0 }, temperature{0} {}
	Reading(int h, double t)
		:hour{ h }, temperature{ t } {}
};

istream& operator>>(istream& is, Reading& r)
{
	int hour;
	double temperature;
	is >> hour>> temperature;
	if (!is)
		return is;

	r = Reading(hour, temperature);
	return is;
}

ostream& operator<<(ostream& os, Reading& r)
{
	return os <<r.hour<<' '<<r.temperature << endl;
}


void read_file(vector<Reading>& temps, string& name)
{
	ifstream ist{ name };
	if (!ist) error("unable to open file ", name);

	Reading r;
	while (ist >> r)
		temps.push_back(r);
}

void compute_stats(vector<Reading>& temps)
{
	vector<double>t;
	double mean{ 0 }, sum{ 0 }, median{ 0 };
	int count{ 0 };
	// compute mean
	for (Reading r : temps) {
		sum += r.temperature;
		++count; // make sure all 50 temps are read print out during testing
		t.push_back(r.temperature);
	}
	mean = sum / count;
	sort(t.begin(), t.end());
	median = t[count/2];

	//cout << count << endl;
	cout << "mean temperature: " << mean << " median: " << median << endl;
}

int main()
try {

	vector<Reading>temperature;
	string file_name = "raw_temps.txt";

	read_file(temperature, file_name);
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