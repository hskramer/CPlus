#include "../../std_lib_facilities.h"

/* program implements a parses simple english sentence given the following definitions:

*  Sentence: 
			Article Noun Verb
			Noun Verb
			Sentence Conjunction Sentence
*  Noun: 
		birds, fish, C++

*  Verb: 
		rules, fly, swim

*  Conjunction:
		and, or, but

* Article:
		The, the

* Having a upper case and lower case 'the' allows for sentences like: "The fish swim but the birds fly";
  this also works with: "The birds fly but the fish swim and C++ rules" . Started working with the full
  class definition but soon realized the bulk of it wasn't neccessary so I kept what worked and deleted 
  the rest. This turned to be a simple program that can handle any correct use of the grammar.

*/

//----------------------------------------------------------------------------

// taken from the calculator problem only difference is it handles words instead of tokens


class String_stream {
public:
	String_stream();
	string get();
private:
	bool full{ false };
	string buffer;
};

//-------------------------------------------------------------------------------

// The constructor just sets buffer full to false to indicate buffer is empty
String_stream::String_stream()
	:full(false), buffer("") {}


string String_stream::get()
{
	string str;
	cin >> str;

	if (str == "The" || str == "the") {
		string word{ "" };
		cin >> word;
		return word;
	}
	else
		return str;
}

String_stream sstrm;

bool verb(string str)
{
	vector<string>verbs{ "rules", "fly", "swim" };

	for (string v : verbs)
		if (v != str)
			continue;
		else
			return true;

	return false;
}

bool noun(string str)
{
	vector<string>nouns{ "birds", "fish", "C++" };

	for (string n: nouns)
		if (n != str)
			continue;
		else 
			return true;		

	return false;
}

bool conjunctions(string str)
{
	vector<string>conj{ "and", "but", "or" };

	for (string c : conj)
		if (c != str)
			continue;
		else
			return true;

	return false;
}

bool sentence()
{
	bool ok = false;
	string str{ "" };
	ok = noun(sstrm.get());
	ok = verb(sstrm.get());
	str = sstrm.get();
	if (ok && str == ".") {
		return true;
	}
	else if (ok) {
		ok = conjunctions(str);
		if (ok)
			sentence();
	}
	else if (!ok)
		return false;
 
	if (!ok && str == ".")
		return false;
}

int main()
try {

	bool good = true;

	while (good) {
		good = sentence();
		if (good) {
			cout << "OK\n";
			return 0;
		}
		else {
			cout << "Not OK\n";
			return 0;
		}
	}
}
catch (exception& e)
{
	cerr << "error: " << e.what() << "\n";
	return 1;
}
catch (...)
{
	cerr<<"unkown exception!\n";
	return 2;
}