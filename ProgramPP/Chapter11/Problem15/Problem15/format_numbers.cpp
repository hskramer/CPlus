#include "../../std_lib_facilities.h"

void format_output(const string& iname, const string& oname)
{
	vector<double>vdbl;

	ifstream ifs{ iname.c_str() };
	if (!ifs) error("error opening file ", iname);

	ofstream ofs{ oname.c_str() };
	if(!ofs) error("error opening file ", oname);


	double num{ 0.0 };
	while (ifs >> num) {
		vdbl.push_back(num);
	}

	//cout.precision(8); this specifies maximum number of digits not a fixed number
	ofs << scientific << setprecision(8);
	ofs << "Four aligned rows of numbers in scientific notation with a precision of eight:\n";
	for (int i = 0; i < vdbl.size(); ++i) {
		if (i % 4 == 0) ofs << endl;
		ofs << setw(20) << vdbl[i];
	}

}

int main()
try {
	
	string ifile{ "" }, ofile{ "" };

	cout << "Enter name of file to be read\n";
	cin >> ifile;

	cout << "Enter name of file to write\n";
	cin >> ofile;

	format_output(ifile, ofile);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what()<< '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error: " << '\n';
	return -2;
}