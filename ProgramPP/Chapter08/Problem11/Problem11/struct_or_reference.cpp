#include "../../std_lib_facilities.h"

struct statistics {
	double max;
	double min;
	double mean;
	double median;
};

void fill_vector(vector<double>& v) {
	double r{ 0 }; int num{ 0 };

	srand(time(NULL)); // making the number of numbers generated random  both odd and even method of computing a median must be used
	num = rand() % 50 + 10;

	mt19937 rnd(time(NULL));
	uniform_real_distribution<>d(1, 100); // generate random real numbers from 1 to 100
	for (int i = 0; i < num; ++i) {
		r = d(rnd);
		v.push_back(r);
	}

	if (v.size() == 0) ("error fill_vector failed");
}


statistics find_stats(vector<double>& v)
{
	statistics fstats{ 0 };
	double tmp{ 0 };

	for (int i = 0; i < v.size(); ++i) {
		tmp = v[i];
		if (tmp > fstats.max) fstats.max = tmp;
	}

	fstats.min = 51; // set this larger than any possible value so the min can be found
	for (int i = 0; i < v.size(); ++i) {
		tmp = v[i];
		if (tmp < fstats.min) fstats.min = tmp;
	}
	
	for (int i = 0; i < v.size(); ++i) {
		tmp += v[i];
	}

	int i1{ 0 }, i2{ 0 };
	if (v.size() % 2 != 0) {
		i1 = v.size() / 2;
		sort(v.begin(), v.end());
		fstats.median = v[i1];		
	}
	else {
		i1 = v.size() / 2;
		i2 = i1 + 1;
		sort(v.begin(), v.end());
		fstats.median = (v[i1] + v[i2]) / 2.0;		
	}

	fstats.mean = tmp / v.size();

	return fstats;
}

int main()
try {
	
	statistics stats;
	vector<double> my_vector;

	fill_vector(my_vector); // fill a vector with random numbers from 1 to 100

	stats = find_stats(my_vector);

	cout << "The maximum value is: " << stats.max << endl;
	cout << "The minimum value is: " << stats.min << endl;
	cout << "The mean is: " << stats.mean << endl;
	cout << "The median is: " << stats.median << endl;
	
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}