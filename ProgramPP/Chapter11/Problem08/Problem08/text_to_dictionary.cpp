m#include "../../std_lib_facilities.h"


void remove_punct(string& str)
{
	if (str.size() == 0) return; // empty line

	for (int i = 0; i < str.size(); ++i) {
		if (ispunct(str[i]) && str[i] != '-' && str[i] != '\'')
			str[i] = ' ';
		else if (str[i] == '-' && str[i - 1] == ' ' && str[i + 1] == ' ')
			str[i] = ' ';
		else
			str[i] = tolower(str[i]);
	}
	
}


void replace_with_not(string& str)
{
	string word{ "" };
	string str_out{ "" };

	istringstream is(str);
	if (!is) error("is not valid input stringstream");

	ostringstream os(str_out);
	if (!os) error("os not valid output stringstream");


	for (string word; is >> word;) {
		if (word == "can't")
			os << "cannot"; // this is the only time the word and not don't have a space btw them.

		else if (word.size() >= 3 && word[word.size() - 1] == 't' && word[word.size() - 2] == '\'') {

			for (int i = 0; i < word.size() - 3; ++i)
				os << word[i];
			os << " not";
		}
		else os << word;
		os << ' '; // need to add space between words as you move through the stringstream buffer
	}
	str = os.str(); //copy the stringstream buffer contents back into the string without this the file is left empty as I experienced many times

}

void make_dictionary(const string& iname, const string&  dict_name)
{
	vector<string>vs;
	string word{ "" };	

	ifstream ifs(iname.c_str());
	if (!ifs) error("can't opening file ", iname);

	while(ifs>>word) 
		vs.push_back(word);	

	sort(vs.begin(), vs.end());

	ofstream ofs(dict_name.c_str());
	if (!ofs) error(" open file ", dict_name);

	for (int i = 0; i < vs.size(); ++i) {
		if (i == 0 || vs[i] != vs[i - 1])
			ofs << vs[i] << '\n';
	}
}


void modify_file(const string& iname, const string&  oname)
{
	string line{ "" };
	vector<string>dict;
	
	ifstream ifs{ iname.c_str() };
	ofstream ofs{ oname.c_str() };


	while (getline(ifs, line)) {
		remove_punct(line); // this removes punctuation converts to lower and leaves double quoted statements alone also removes extraneous 
		replace_with_not(line); // hyphens
		ofs << line << '\n';
	}

}

int main()
try {

	string read{ "" }, write{ "" };

	cout << "Name of file to read?" << '\n';
	cin >> read;

	cout << "Name of file to write?" << '\n';
	cin >> write;

	modify_file(read, write);

	string iname{ "" };
	cout << "Name of file used for makeing dictionary" << '\n';
	cin >> iname;

	string dict_name{ "" };
	cout << "Name for dictionary file?" << endl;
	cin >> dict_name;

	make_dictionary(iname, dict_name);

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return -1;
}
catch (...) {
	cerr << "unknown error" << '\n';
	return -2;
}