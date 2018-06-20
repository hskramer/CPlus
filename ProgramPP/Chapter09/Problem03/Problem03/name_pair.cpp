#include "../../std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();
	const vector<string>& get_name() const { return name; }
	const vector<double>& get_age() const { return age; }
private:
	vector<string>name;
	vector<double>age;
};


//----------------------------------------------------------------------------------------


int find_index(vector<string>& v, string& n)
{
	for (int i = 0; i < v.size(); ++i)     // find index for age so the sorted names have the correct age
		if (v[i] == n) return i;
	error("find_index(): name not found");
}


//----------------------------------------------------------------------------------------


void Name_pairs::sort()
{
	vector<string>original_name = name;
	vector<double>original_age = age;

	std::sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); ++i) 
		age[i] = original_age[find_index(original_name, name[i])];

	original_name.clear();
	original_age.clear();
}


//----------------------------------------------------------------------------------------


void Name_pairs::read_names()
{
	string nm;
	cout << "Please enter some names (enter 'quit' when finished)" << endl;

	while (cin >> nm && nm != "quit") {
		for (int i = 0; i < name.size(); ++i)
			if (name[i] == nm) error("read_names(): duplicate name");
		name.push_back(nm);
	}
}


//----------------------------------------------------------------------------------------


void Name_pairs::read_ages()
{
	double ag;

	for (int i = 0; i < name.size(); ++i) {
		cout << "Please enter the age for " << name[i] << ": ";
		cin >> ag;
		age.push_back(ag);
	}
}


//----------------------------------------------------------------------------------------

void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); ++i)
		cout << "(" << name[i] << ", " << age[i] << ")" << endl;
}


//----------------------------------------------------------------------------------------


bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	bool is_equal{ true };

	if (a.get_name().size() != b.get_name().size() || a.get_age().size() != b.get_age().size())
		is_equal = false;

	for (int i = 0; i < a.get_name().size(); ++i)
		if (a.get_name()[i] != b.get_name()[i])
			is_equal = false;

	for (int i = 0; i < a.get_age().size(); ++i)
		if (a.get_age()[i] != b.get_age()[i])
			is_equal = false;

	return is_equal;
}


//----------------------------------------------------------------------------------------


bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b); // performs the operator== !(==)  negates it returning a true if not equal and false if equal
}


//----------------------------------------------------------------------------------------


int main()
try {

	Name_pairs nameagesA, nameagesB, nameagesC;

	nameagesA.read_names();
	nameagesA.read_ages();
	nameagesA.print();
	nameagesA.sort();
	cout << "Sorted name age pairs:" << endl;
	nameagesA.print();

	nameagesB = nameagesA;

	if (nameagesA == nameagesB)
		cout << "names and ages of group A and group B match" << endl;

	nameagesC.read_names();
	nameagesC.read_ages();
	nameagesC.sort();

	if (nameagesC != nameagesB)
		cout << "names and ages of group C and group B don't match" << endl;

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
