#ifndef READING_H
#define READING_H

struct Year {
	int year;
	vector<Month>month{ 12 }; // number of months [0:11]
};

struct Month {
	int month{ not_a_month };
	vector<Day>day{ 32 }; 
};

struct Day {
	vector<double>hour;
	Day();
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

Day::Day()
	:hour(24);
{
	for(int i = 0; i < hour.size();)
}

#endif
