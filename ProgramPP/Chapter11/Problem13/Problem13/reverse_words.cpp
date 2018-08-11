#include "../../std_lib_facilities.h"

void reverse_word(const string& iname, const string& oname)
{
	vector<string>words;

	ifstream ifs{ iname.c_str() };
	if (!ifs) error("error opening file", iname);

	ofstream ofs{ oname.c_str() };
	if (!ofs) error("error writing to file", oname);

	for (string word; ifs >> word;)
		words.push_back(word);

	reverse(words.begin(), words.end());

	//for (int i = words.size() - 1; i > 0; --i) // solution is a little more elegant but they both work I chose space rather than newline
	//	ofs << words[i] << ' ';					

	for (string word : words) 
		ofs << word << ' ';

}

int main()
try {

	string ifile{ "" }, ofile{ "" };

	cout << "Enter name of file to read." << '\n';
	cin >> ifile;

	cout << "Enter name of the new file" << '\n';
	cin >> ofile;

	reverse_word(ifile, ofile);

	return 0;

}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unkown error" << '\n';
	return -2;
}