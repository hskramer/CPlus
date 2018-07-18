#include "../../std_lib_facilities.h"

// each function performs one logical operation 


vector<string> read_file(string& file_name)
{
	ifstream ifs{ file_name };
	if (!ifs) error("error opening file ", file_name);

	vector<string>temp;
	string str{ "" };	

	while (ifs >> str)
		temp.push_back(str);

	return temp;
}


//------------------------------------------------------------------------------------------------


void write_file(const vector<string>& str, const string& file_name)
{
	ofstream ofs{ file_name };
	if (!ofs) error("error opening file ", file_name);

	for (string s : str)
		ofs << s <<' ';
}


//------------------------------------------------------------------------------------------------


vector<string> alphabetize(vector<string>& s1, vector<string>& s2)
{
	s1.insert(s1.end(), s2.begin(), s2.end());
	return s1;
}


//------------------------------------------------------------------------------------------------


int main()
try {

	string file1{ "" }, file2{ "" };
	cout << "Enter name of first file" << endl;
	cin >> file1;
	cout << "Enter name of seconf file" << endl;
	cin >> file2;

	vector<string>str_one = read_file(file1);
	vector<string>str_two = read_file(file2);

	vector<string>alpha = alphabetize(str_one, str_two);
	
	string file3{ "" };
	cout << "Enter name of file to be written " << endl;
	cin >> file3;

	write_file(alpha, file3);
}
catch (exception& e) {
	cerr << "error occured " << e.what() << endl;
	return -1;
}
catch (...) {
	cerr << "unkown error occured" << endl;
	return -2;
}