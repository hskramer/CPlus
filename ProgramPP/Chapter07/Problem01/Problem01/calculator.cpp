
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


const char powr = 'P';
const char sqroot = 'S';
const char let = 'L';			// declaration token
const char quit = 'Q';			// quit token
const char print = ';';	   		// print token
const char number = '8';		// number token
const char name = 'a';			// name token

const string powrkey = "pow";
const string declkey = "let";	// declaration key word
const string quitkey = "quit";	// quit key word
const string sqrtkey = "sqrt";


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
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_' )) s += ch; // allow underscore in variable names
			cin.putback(ch);
			if (s == declkey) return Token(let);		// token that allows for the use of variables in calculations
			if (s == powrkey) return Token(powr);
			if (s == sqrtkey) return Token(sqroot);		// token for taking the square root
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
};

vector<Variable>var_table;

double get_value(string s)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == s) {
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}


 // checks if a  variable has already been declared
bool is_declared(string var)		
{
	for (int i = 0; i<var_table.size(); ++i)
		if (var_table[i].name == var) return true;
	return false;
}


double define_name(string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var,val });
	return val;
}


//------------------------------------------------------------------------------------------------

Token_stream ts;		// provides get() and putback() 

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
		d = power();
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
		return get_value(t.name);
		break;
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

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	double d = expression();
	define_name(var_name, d);
	return d;
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

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

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
	// predefined names:
	define_name("k", 1000);

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