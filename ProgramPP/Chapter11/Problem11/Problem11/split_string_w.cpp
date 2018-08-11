#include "../../std_lib_facilities.h"

string is_whitespace(string str, const string& white)
{
	for (int i = 0; i < str.size(); ++i) {
		for (char w : white)
			if (str[i] == w) {
				str[i] = NULL;				
			}
	}	
	return str;
}

// solved two different ways just testing alternative solutions can think of at least two more.

/*vector<string> split(const string& s, const string& w) 
{
	vector<string>substr;
	string ss{ "" };  

	istringstream is{ s };

	while (is >> ss) {
		ss = is_whitespace(ss, w);
		substr.push_back(ss);
	}

	return substr;
}*/

vector<string> split(const string& s, const string& w)
{
	vector<string>substr;
	string subs{ "" };

	stringstream ss(s);
	for (string word; ss >> word;) {
		subs = is_whitespace(word, w);
		substr.push_back(subs);
	}
	return substr;
}

void print_vec(vector<string>& str)
{
	for (string s : str)
		cout << s <<endl;
}

int main()
try {

	string line{ "" };
	string wspace{ "" };
	vector<string>st;

	cout << "Enter a line of text.\n";
	while (getline(cin, line)) {
		cout << "Enter characters that you want to represent as whitespace.\n";
		getline(cin, wspace);
		st = split(line, wspace);
		print_vec(st);
		cout << "One more time?" << endl;
	}
}
catch(exception& e) {
	cerr << "error: " << e.what() << '\n';
	return-1;
}
catch (...) {
	cerr << "unkown error: " << '\n'; // use string n\" to end the line of a string '\n' to end a line without flushing the stream with
	return -2;						  // some exceptions in linux, most cases '\n' is best.
}