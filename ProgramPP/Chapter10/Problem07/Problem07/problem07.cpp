#include "roman.h"

using namespace Roman;


class Token {
public:
	char kind;			// what kind of token
	Roman_int value;		// floating point number
	string name;
	Token(char ch) :kind(ch) { }					        // make a Token from a char
	Token(char ch, Roman_int val) :kind(ch), value(val) { }   // make a Token from a char and a double
	Token(char ch, string n) :kind(ch), name(n) {}		  // make a Token from a char and string
};

//------------------------------------------------------------------------------------------------

// creates the token stream
class Token_stream {
public:
	Token_stream();				// make a Token from cin
	Token get();				// get a Token
	void putback(Token t);		// putback a Token if not used by a function
	void ignore(char c);

private:						// this holds tokens that are putback 
	bool full{ false };
	Token buffer;
};


//------------------------------------------------------------------------------------------------



// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0) {}   // no Token in buffer


								 // The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;			// copy t to buffer
	full = true;		// buffer is now full
}



//------------------------------------------------------------------------------------------------


const char let = 'L';			// declare variable token
const char constnt = 'C';		// constant token
const char quit = 'Q';			// quit token
const char print = ';';	   		// print token
const char number = '8';		// number token
const char name = 'a';			// name token

const string declkey = "let";		// declare new variable key word
const string constkey = "con";		// declare a constant
const string quitkey = "quit";		// quit key word


//------------------------------------------------------------------------------------------------



Token Token_stream::get()
{
	if (full) {			// do we already have a Token ready?
		full = false;	// remove token from buffer
		return buffer;
	}
	char ch;
	cin>>ch;		// note that >> skips whitespace (space, newline, tab, etc.)
	
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ';':
	case ',':
		return Token(ch);		// let each character represnenst itself
//	case '.':					// floating points can start with a dot

	case N: case I: case V: case X: case L: case C:	case D: case M: // use Roman nuerals

	{	cin.putback(ch);		// put digit back into the input stream
		Roman_int val_r;
		cin >> val_r;				// read a floating point number
	//	val_r.as_int();
		return Token(number, val_r);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // allow underscore in variable names
			cin.putback(ch);
			if (s == declkey) return Token(let);		// token that allows for the use of variables in calculations
			if (s == constkey) return Token(constnt);	// token for declaring a constant
			if (s == quitkey) return Token(quit);		// quit token
			return Token(name, s);
		}
		error("Bad token");
	}
}

//------------------------------------------------------------------------------------------------


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch{ 0 };
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------------------------

class Variable {
public:
	string name;
	Roman_int value;
	bool constant;
	Variable(string s, Roman_int v, bool c) :name(s), value(v), constant(c) {};
};


vector<Variable> var_table;

// return value of variable given the name 
Roman_int get_value(string s)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);
}


// set the name and value of a new variable
void set_value(string s, Roman_int d, bool c)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].constant == true) error(s, " is a constant");
			var_table[i].value = d;
			var_table[i].constant = c;
			return;
		}
	error("set: undefined variable ", s);
}



// checks if a  variable has already been declared
bool is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

// defines a variable or constant and puts in the var_table
Roman_int define_name(string var, Roman_int val, bool c)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var, val, c }); // define a variable setting constant to false
	return val;
}


//------------------------------------------------------------------------------------------------


Token_stream ts;		// provides get() and putback() 

Roman_int expression();	// declaration so that primary() can call expression()

//------------------------------------------------------------------------------------------------


						// deal with numbers and parentheses and variable names
Roman_int primary()
{
	Token t = ts.get();
	Roman_int d{ 0 };
	switch (t.kind) {
	case '(':				// handle '(' expression ')'
	{   d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	break;
	}
	case '-':
		d = -primary();
		break;
	case number:
		d = t.value;
		break;
	case name:
	{	Token t2 = ts.get();
	if (t2.kind == '=') {
		d = expression();
		set_value(t.name, d, false);
	}
	else {
		ts.putback(t2);
		return get_value(t.name);
	}
	break;
	}
	default:
		error("primary expected");
	}

	return d;
}


//------------------------------------------------------------------------------------------------


// deal with *, /, %
Roman_int term()
{
	Roman_int left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left = left * primary();
			t = ts.get();
			break;
		case '/':
		{	Roman_int d = primary();
		if (d == 0) error("/:divide by zero");
		left = left / d;
		t = ts.get();
		break;
		}
		case '%': // decided to do integer version now wanted to make sure it worked
		{
			Roman_int i1 = left;
			Roman_int i2 = term(); //norrow_cast<int> give info lost error
			left = i1 % i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}


//------------------------------------------------------------------------------------------------


// deal with + and -
Roman_int expression()
{
	Roman_int left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left = left + term();
			t = ts.get();
			break;
		case '-':
			left = left - term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}


//------------------------------------------------------------------------------------------------


Roman_int declaration(Token lc)
{
	bool b{ 0 };
	if (lc.kind == let)
		b = false;	// if  kind is a let then set constant false
	else
		b = true;  // if not set constant true

	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	Roman_int d = expression();
	define_name(var_name, d, b); // this now declares a variable or constant
	return d;
}


//------------------------------------------------------------------------------------------------

Roman_int statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(t); // defines new variables
	case constnt:
		return declaration(t);
	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------------------------


void clean_up_mess()  // basic clean up function
{
	ts.ignore(print); // skips everything until it finds the print Token ;
}


const string prompt = "> ";
const string result = "= ";


void calculate() // This is our evaluation loop
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // first discard all "prints"
		if (t.kind == quit) return;			  // quit
		ts.putback(t);
		cout << result << roman_numeral(statement().as_int()) << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}


int main() // handle the start/end of the program and fatal errors

try {

	define_name("pi", 3.141592653899, true);

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}