#include "../../std_lib_facilities.h"

void reverse_v1(const vector<int>& v) {

	vector<int>rev_odd;

	for (int i = v.size() - 1; i >= 0; --i)
		rev_odd.push_back(v[i]);
}

void reverse_v2(vector<int>& v2) {

	
	for (int i = 0; i < v2.size()/2; ++i) 
		swap(v2[i], v2[v2.size()-1-i]);		
	
	for (int j = 0; j < v2.size(); ++j)
		cout << v2[j] << endl;
}

int main()
try {

	vector<int>odd;
	odd.push_back(1);

	for (int i = 0; i < 25; ++i)
		odd.push_back(odd[i] + 2);

	reverse_v1(odd);

	vector<int>even;
	even.push_back(0);

	for (int j = 0; j < 25; ++j)
		even.push_back(even[j] + 2);

	reverse_v2(even);

}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}