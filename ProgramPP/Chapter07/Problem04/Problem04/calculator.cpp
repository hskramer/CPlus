
/*
Basic calculator: very robust even through this at it: sqrt(pow(2*(1+2),sqrt(3+7)))+2*pow((2+3)*2,(10/3+1))/(4+sqrt(pow(4,(6/2))));
noet it does round the exponent to the nearest integer. This gave correct result tested using Wolfram Mathematica

		
		The grammar for input is:
	
	Calculation:
		Statement
		Print
		Quit
		Help
		Calculation Statement

	Statement:
		Declaration
		Expression

	Declaration:
		"let" Name "=" Expression
		"const" name "=" Expression

	Name:
		letter
		letter Sequence

	Sequence:
		letter
		digit
		"_"
		letter Sequence
		digit Sequence
		"_" Sequence

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
		"sqrt(" Expression ")"
		"pow(" Expression "," Integer ")"
	Name
		Name "=" Expression
	Number:
		floating-point-literal


*/

#include "../../std_lib_facilities.h"


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


const char powr = 'P';			// power token
const char sqroot = 'S';		// sqrt token
const char let = 'L';			// declare variable token
const char constnt = 'C';		// constant token
const char quit = 'Q';			// quit token
const char print = ';';	   		// print token
const char number = '8';		// number token
const char name = 'a';			// name token

const string declkey = "let";		// declare new variable key word
const string constkey = "con";	// declare a constant
const string quitkey = "quit";		// quit key word
const string sqrtkey = "sqrt";		// sqrt key wors
const string powrkey = "pow";		// power key word


									//------------------------------------------------------------------------------------------------



Token Token_stream::get()
{
	if (full) {			// do we already have a Token ready?
		full = false;	// remove token from buffer
		return buffer;
	}
	char ch;
	cin >> ch;		// note that >> skips whitespace (space, newline, tab, etc.)
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);		// let each character represnenst itself
	case '.':					// floating points can start with a dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	cin.putback(ch);		// put digit back into the input stream
	double val;
	cin >> val;					// read a floating point number
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // allow underscore in variable names
			cin.putback(ch);
			if (s == declkey) return Token(let);		// token that allows for the use of variables in calculations
			if (s == powrkey) return Token(powr);
			if (s == sqrtkey) return Token(sqroot);		// token for taking the square root
			if (s == constkey) return Token(constnt);	// token for declaring a constant
			if (s == quitkey) return Token(quit);		// quit token
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
	Variable(string s, double v, bool c) :name(s), value(v), constant(c) {};
};


class Symbol_table {
	vector<Variable>var_table;
public:
	void set_value(string,  double, bool);
	double get_value(string);
	bool is_declared(string);
	double define_name(string, double, bool);
	
};

// return value of variable given the name 
double Symbol_table::get_value(string s)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);
}


// set the name and value of a new variable
void Symbol_table::set_value(string s, double d, bool c)
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


//------------------------------------------------------------------------------------------------


// checks if a  variable has already been declared
bool Symbol_table::is_declared(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return true;
	return false;
}

double Symbol_table::define_name(string var, double val, bool c)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var, val, c }); // define a variable setting constant to false
	return val;
}


//------------------------------------------------------------------------------------------------


Token_stream ts;		// provides get() and putback() 

Symbol_table st;		// provide access to the Symbol table

double expression();	// declaration so that primary() can call expression()

double square_root();	// declaration so that primary() can call square_root()

double power();			// declaration so that primary() can call power()


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
	case powr:
		d = power(); // since each function should perform one logical action I chose to use separate functions for power and sqrt
		break;
	case sqroot:
		d = square_root();
		break;
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
		st.set_value(t.name, d, false);
	}
	else {
		ts.putback(t2);
		return st.get_value(t.name);
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
		case '%': // implemted floating point mod
		{
			double d = primary();
			if (d == 0) error("%:divide by zero");
			left = fmod(left, d);
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


double power()
{
	double d{ 0 }; // this will work with very complex cases such as sqrt(pow(2*(1+2),(2+1))); or more sqrt(pow(2*(1+2),sqrt(3+7)))+2;

	Token t = ts.get();
	if (t.kind != '(') error("( expected"); // this both checks for proper use and allows for complex expression
	d = expression();						// inside such as pow((2+1)*2, 3)

	t = ts.get();
	if (t.kind != ',') error(", expected"); // this check for proper use  ',' so it prevents other function from throwing errors

	int i = expression(); // tried narr_cast<int> but it gave an "info lost" error so I decided to do this which works

	t = ts.get();
	if (t.kind != ')') error(") expected"); // this check for a closing ')' but it allows for complex statements for the exponents

	return pow(d, i);
}


//------------------------------------------------------------------------------------------------


// provides a square root function for real numbers only
double square_root()
{
	double d = primary();
	if (d < 0) error("error sqrt of negative number");

	return sqrt(d);
}


//------------------------------------------------------------------------------------------------


double constant()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected for constant");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing for constant ", var_name);
	double d = expression();
	st.define_name(var_name, d, true); // thise declares a constant
	return d;
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
	st.define_name(var_name, d, b); // this now declares a variable or constant
	return d;
}


//------------------------------------------------------------------------------------------------

double statement()
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
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() // handle the start/end of the program and fatal errors

try {

	st.define_name("pi", 3.141592653899, true);

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c&& c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}