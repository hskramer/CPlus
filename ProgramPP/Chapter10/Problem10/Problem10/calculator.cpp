
/*
Basic calculator: 


				The grammar for input is:
	
	Calculation:
		Statement
		Print
		Quit
		Calculation Statement

	Statement:
		Declaration
		Expression

	Declaration:
		"let" Name "=" Expression

	Name:
		letter
		letter Sequence

	Sequence:
		letter
		digit
		letter Sequence
		digit Sequence

	Print:
		";"

	Quit:
		"quit"

	Expression:
		Term
		Expression "+" Term
		Expression "-" Term

	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary

	Primary:
		Number
		"(" Expression ")"
		"-" Primary
		"+" Primary
	Name
		Name "=" Expression
	Number:
		floating-point-literal

*/

#include "../../std_lib_facilities.h";


class Token {
public:
	char kind;			// what kind of token
	double value;		// floating point number
	string name;
	Token(char ch) :kind(ch) { }					        // make a Token from a char
	Token(char ch, double val) :kind(ch), value(val) { }   // make a Token from a char and a double
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

// this was the only way I could make it compile and work will revisit as my skills and experience improve, would like to see a solution

string input_name = "calc_input.txt";
string output_name = "calc_output.txt";
ifstream ifs{ input_name.c_str() };
ofstream ofs{ output_name.c_str() };


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch{ 0 };
	while (ifs >> ch)
		if (ch == c) return;
}


//------------------------------------------------------------------------------------------------


const char let = 'L';			// declare variable token
const char quit = 'q';			// quit token
const char print = ';';	   		// print token
const char number = '8';		// number token
const char name = 'a';			// name token

const string result = "= ";
const string prompt = "> ";

const string declkey = "let";		



//------------------------------------------------------------------------------------------------



Token Token_stream::get()
{
	if (full) {			// do we already have a Token ready?
		full = false;	// remove token from buffer
		return buffer;
	}
	char ch;
	ifs>>ch;		// note that >> skips whitespace (space, newline, tab, etc.)
	switch (ch) {
	case quit:
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
		return Token(ch);		// let each character represnenst itself
	case '.':					// floating points can start with a dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	ifs.putback(ch);		// put digit back into the input stream
	double val;
	ifs >> val;					// read a floating point number
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (ifs.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // allow underscore in variable names
			ifs.putback(ch);
			if (s == declkey) return Token(let);		// token that allows for the use of variables in calculations
			return Token(name, s);
		}
		error("Bad token");
	}
}


//------------------------------------------------------------------------------------------------


class Variable {
public:
	string name;
	double value;
	bool constant;
	Variable(string s, double v) :name(s), value(v) {};
};


//------------------------------------------------------------------------------------------------


vector<Variable> var_table; 


//------------------------------------------------------------------------------------------------


// return value of variable given the name 
double get_value(string s)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);
}


// set the name and value of a new variable
void set_value(string s, double d)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) {
			var_table[i].value = d;
			return;
		}
	error("set: undefined variable ", s);
}


//------------------------------------------------------------------------------------------------


// checks if a  variable has already been declared
bool is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

// defines a variable or constant and puts in the var_table
double define_name(string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var, val}); // define a variable setting constant to false
	return val;
}


//------------------------------------------------------------------------------------------------


Token_stream ts;		// provides get() and putback() 

double expression();	// declaration so that primary() can call expression()


//------------------------------------------------------------------------------------------------


						// deal with numbers and parentheses and variable names
double primary()
{
	Token t = ts.get();
	double d{ 0 };
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
		set_value(t.name, d);
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
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("/:divide by zero");
		left /= d;
		t = ts.get();
		break;
		}
		case '%': // decided to do integer version now wanted to make sure it worked
		{
			int i1 = int(left);
			int i2 = int(term()); //norrow_cast<int> give info lost error
			left = i1%i2;
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
double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}


//------------------------------------------------------------------------------------------------


double declaration(Token lc)
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
	double d = expression();
	define_name(var_name, d); // this now declares a variable or constant
	return d;
}


//------------------------------------------------------------------------------------------------

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(t); // defines new variables
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


//------------------------------------------------------------------------------------------------


void calculate(ifstream& ifs, ofstream& ofs) // This is our evaluation loop
{
	while (ifs) try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // first discard all "prints"
		if (t.kind == quit) return;			  // quit
		ts.putback(t);
		ofs << result << statement() << endl;
	}
	catch (runtime_error& e) {
		ofs << e.what() << endl;
		clean_up_mess();
	}
}

int main() // handle the start/end of the program and fatal errors

try {

	define_name("pi", 3.141592653899);
	define_name("e", 2.7182818284);
	
	calculate(ifs, ofs);

	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (ifs >> c&& c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (ifs >> c && c != ';');
	return 2;
}