#include "../../std_lib_facilities.h"


vector<char> remove_punct(string& str)
{
	bool is_quote{ false };
	vector<char>vchar;

	for (char& ch : str) {
		if (ch == '"') {
			is_quote = true;
		}
		else if (!is_quote && ispunct(ch) && ch !='-') {
			ch = ' ';
			vchar.push_back(ch);
		}
		vchar.push_back(tolower(ch));
	}
	vchar.push_back('\n');
	
	return vchar;
}


void replace_with_not(string& str)
{
	string word{ "" };
	string str_out{ "" };

	istringstream is(str);
	if (!is) error("is not valid input stringstream");

	ostringstream os(str_out);
	if(!os) error("os not valid output stringstream");

	
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

void remove_hyphen(string& str)
{
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '-' && str[i - 1] == ' ' && str[i + 1] == ' ')
			str[i] = ' ';
	}
}

void modify_file(const string& iname, const string&  oname)
{
	string line{ "" };
	vector<char>vch;

	ifstream ifs{ iname.c_str() };
	if(!ifs) error("error opening file", iname);
	
	ofstream ofs{ oname.c_str() };
	if(!ofs) error("error opening file", oname);


	while (getline(ifs, line)) {
		replace_with_not(line);
		vch = remove_punct(line);
		for (char ch : vch)
			ofs << ch;
	}
	cout << endl;
	
}

int main()
try {



	string read{ "" }, write{ "" };
	
	cout << "Name of file to read?" << '\n';
	cin >> read;
	

	cout << "Name of file to write?" << '\n';
	cin >>write;

	modify_file(read, write);
	
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