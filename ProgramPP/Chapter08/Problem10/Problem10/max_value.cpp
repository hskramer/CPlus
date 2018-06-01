#include "../../std_lib_facilities.h"

void fill_vector(vector<int>& v) {
	int r{ 0 };
	
	srand(time(NULL));

	for (int i = 0; i < 100; ++i) {
		r = rand() % 1000 + 1;
		v.push_back(r);
	}
}

int maxv(vector<int>& v) {

	int mx{ 0 }, tmp{ 0 };

	for (int i = 0; i < v.size(); ++i) {
		tmp = v[i];
		if (tmp > mx) mx = tmp;
	}
	return mx;
}

int main()
try {
	int max{ 0 };
	vector<int>my_vector;
	
	fill_vector(my_vector);

	max = max_value(my_vector);

	cout << "max: " << max << endl;

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