#include "../../std_lib_facilities.h"

vector<int> read_file(string& iname)
{
	vector<int>s;
	int x{ 0 };

	ifstream ist{ iname };
	if (!ist) error("can't open file", iname);

	while (ist>>x)
		s.push_back(x);

	return s;
}

void sum_vector(vector<int>& s)
{
	int sum{ 0 };
	for (int x : s)
		sum += x;
	
	cout << "The sum is equal to: " << sum << endl;
}

int main()
try {

	vector<int>sum;
	string file_name = "integers.txt";

	sum = read_file(file_name);
	sum_vector(sum);
}
catch (exception& e)
{
	cerr << "error occured" << e.what() << endl;
	return -1;
}
catch (...)
{
	cerr << "unkown exception occured" << endl;
	return -2;
}