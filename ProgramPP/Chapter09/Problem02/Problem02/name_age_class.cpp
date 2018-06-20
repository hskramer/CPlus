#include "../../std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();
private:
	vector<string>name;
	vector<double>age;
};

int find_index(const vector<string>& v, const string& n)
{
	for (int i = 0; i < v.size(); ++i) // find the origianal index associated the name, age pair
		if (v[i] == n) return i;
	error("find_index(): name not found", n);
}

void Name_pairs::sort() 
{

	vector<string>original_name = name;
	vector<double>original_age = age;

	std::sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); ++i) {
		age[i] = original_age[find_index(original_name, name[i])];
	}
	original_name.clear(); // free resources when finished
	original_age.clear();
}

void Name_pairs::read_names() 
{
	string nm;
	cout << "Please enter some names (enter 'quit' when finished)" << endl;

	while (cin>>nm && nm !="quit") {
		for (int i = 0; i < name.size(); ++i)
			if (name[i] == nm) error("read_names(): duplicate name");
		name.push_back(nm);
	}
}

void Name_pairs::read_ages() 
{
	double ag;

	for (int i = 0; i < name.size(); ++i) {
		cout << "Please enter the age for " << name[i] << ": ";
		cin >> ag;
		age.push_back(ag);
	}
}

void Name_pairs::print() const 
{

	for (int i = 0; i < name.size(); ++i) {
		cout << "(" << name[i] << ", " << age[i] <<")"<< endl;
	}
}

int main()
try {

	Name_pairs namepairs;

	namepairs.read_names();
	namepairs.read_ages();
	namepairs.print();
	namepairs.sort();
	cout << "Sorted name age pairs:" << endl;
	namepairs.print();
	
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
