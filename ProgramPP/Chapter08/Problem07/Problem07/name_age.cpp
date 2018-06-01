#include "../../std_lib_facilities.h"

// each function performs one logical operation enter values, sum values, declare variables and call functions this could all fit in main
// and no global variables

void read_names(vector<string>& n) {

	string name{ 0 };

	for (int i = 0; i < 5; ++i) {
		cout << "Enter a name: ";
		cin >> name;
		n.push_back(name);	
	}
}


void prompt_age(const vector<string>& nm, vector<double>& a) {
	double age{ 0 };
	
	for (int i = 0; i < nm.size(); ++i) {
		cout << "Age of " << nm[i]<<": ";
		cin >> age;
		a.push_back(age);
	}
}

void print_name_age(const vector<string>& nm, const vector<double>& a) {
	
	if (nm.size() != a.size()) error("error names and age have different size");

	for (int i = 0; i < nm.size(); ++i)
		cout << nm[i]<<" "<< a[i] << " is years old." << endl;
}

void sort_names(vector<string> name, vector<double> age)
{
	vector<string>cpy_name; vector<double>cpy_age(name.size());
	int i{ 0 }, j{ 0 };

	cpy_name = name;
	sort(name.begin(), name.end());	
	
	for (int i = 0; i < name.size(); ++i) {
		while (name[i] != cpy_name[j]) {
			++j;
		}
		cpy_age[i] = age[j];
		j = 0;
	}
	age = cpy_age;
	print_name_age(name, age);
}

int main()
try {

	vector<string>name;
	vector<double>age;

	read_names(name);
	prompt_age(name, age);
	print_name_age(name, age);
	sort_names(name, age);

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