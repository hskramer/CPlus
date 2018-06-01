#include "../../std_lib_facilities.h"

/* tried to see if this would work with utf-8 variable length character problem. Works on ascii.
vector<int> count_charsV2(vector<string>& vstr)
{
	vector<int>count;  no error checking becuase its not used just wrote as an exercise to the var length char problem
	int i{ 0 };		   tested and it fails on utf-8 char also. Much more involved than expected.

	for (string s : vstr) {
		while(isalpha(s[i])) ++i;
		count.push_back(i);
		i = 0;
	}

	return count;
}
*/


// considered using length until I read in cplusplus.com that length and size return the same value
// and that both may not always return the correct value in the case of variable length characters (UTF-8)
vector<int> count_chars(const vector<string>& vstr) {
	
	vector<int> num_chars(vstr.size());
	for (int i = 0; i < vstr.size(); ++i)
		num_chars[i] = vstr[i].size();
	
	return num_chars;	
}


int longest_string(const vector<string>& vstr) {

	if (vstr.size() == 0) error("longest_string(): empty vector");

	int max{ 0 };
	for (int i = 0; i < vstr.size(); ++i) {
		if (vstr[i].size() > max)
			max = i; // return index of longest string so we can retrieve it any time
	}
	return max;
}

int shortest_string(const vector<string>& vstr) {

	if (vstr.size() == 0) error("shortest_string(): empty vector");
	
	//int min{ 0 };  need to brake habit of initiallizing everything to zero 
	int min = vstr[0].size();
	for (int i = 0; i < vstr.size() - 1; ++i) {
		if (vstr[i].size() < min)
			min = i;
	}
	return min;
}

//Does not do a true lexigraphical compare instead it compares the ascii numbers so a capital 'Zebra' comes before 'a' drove me nuts untill I realized this.
string lex_first(const vector<string>& vstr) {

	if (vstr.size() == 0) error("lex_first(): empty vector");
	
	vector<string> vs = vstr;

	sort(vs.begin(), vs.end());

	return vs[0];
}
	

string lex_last(const vector<string>& vstr) {

	if (vstr.size() == 0) error("lex_last(): empty vector");

	string last = vstr[0];
	for (int i = 0; i < vstr.size(); ++i) {
		if (last < vstr[i])
			last = vstr[i];
	}
	return last;
}


int main()
try {
	
	int mx{ 0 }, mn{ 0 };
	string lexfirst{ "" }, lexlast{ "" };
	vector<string>words;
	vector<int>char_in_word;

	words.push_back("this"); 							
	words.push_back("function");
	words.push_back("counts");
	words.push_back("all");
	words.push_back("characters");

	char_in_word = count_chars(words);
	mx = longest_string(words);
	mn = shortest_string(words);
	lexfirst = lex_first(words);
	lexlast = lex_last(words);


	cout << "The longest word is: " << words[mx] << endl;
	cout << "The shortest word is: " << words[mn] << endl;
	cout << "The lexicographically first word is: " << lexfirst << endl;
	cout << "The lexicographically last word is: " << lexlast << endl;

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