#include "../../std_lib_facilities.h"

#define number '8'  //represents "a number"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full{ false };        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------


// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0) {}   // no Token in buffer


//------------------------------------------------------------------------------


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}


//------------------------------------------------------------------------------


Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
					  // remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':   // for "quit"		
	case '(': case ')': case '{': case '}': // grouping symbols
	case '+': case '-': case '*': case '/': case '%': case '!':  // operation symbols
		return Token(ch); // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token(number, val);   // number defined as '8' 
	}
	default:
		error("Bad token");
	}
}


//------------------------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

						//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//-------------------------------------------------------------------------------------------------------
long long int factorial( long long int d)
{
	long long int fac = d;

	if (fac < 0)
		error("factorial for negatives not defined");
	else if (fac > 21)
		error("number to large");
	else if (abs(fac - d) > 0)
		error("factorial not defined for floats");
	else if (fac == 0)
		return 1;
	else {
		for (int i = 0; i < d - 1; ++i)
			fac *= (i + 1);
		return fac;
	}
}
						//------------------------------------------------------------------------------

						// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	double d{ 0 };
	switch (t.kind) {
	case '{':		// handle '{(' expression ')...}'
	{
	    d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected'");
		break;
	}
	case '(':    // handle '(' expression ')'
	{
	    d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected)'");
		break;
	}
	case '8':            // we use '8' to represent a number
		d = t.value;  // return the number's value
	case '!':         
		t = ts.get(); // I left out the break after a number so I could check for ! and perform it this maintains the precedence oder
		if (t.kind != '!') { 
		ts.putback(t);	// if it's not a factorial just put it back into the token stream buffer same with below
			return d;
		}
		return factorial(d);
	case 'x':
		break;
	default:
		error("primary expected");
	}

	//
	t = ts.get(); // this check for factorial when the immediate left term is not a number i.e. (5+9)! again to maintain proper order
	if (t.kind != '!') {
		ts.putback(t);
		return d;
	}
	else
		return factorial(d);
}


//------------------------------------------------------------------------------


// deal with *, /, % and !
double term()
{
	double left = primary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			long long int x1 = left;
			if (abs(left - x1) > 0)	error("error left op not an integer");

			long long int x2 = d;
			if (abs(d - x2) > 0) error("error right op not an integer");

			if (x2 == 0) error("divide by zeor");

			left = x1 % x2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}


//------------------------------------------------------------------------------


// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}


//------------------------------------------------------------------------------
// my compiler requires all variables be initialized so the ts buffer is always full so I need to symbols to quit one to 
// clear the buffer and then one to exit there may be another way but this works and is simple.

int main()
try
{
	cout << "Welcome to our simple calculator.  Please enter expressions using floating-point numbers\n";
	cout << "I can handle () {} +, -, *, /, and !, % on integers.\n";
	cout << "Hit '=' when you want the answer and  xx to exit\n";
	cout << ">";

	double val{ 0 };

	while (cin) {
		Token t = ts.get();
	
		if (t.kind == 'x') return 0; // 'x' for exit
		if (t.kind == '=') {      // '=' for "print answer now"
			cout << "answer: " << val << '\n';
			cout << "> ";
		}
		else
			ts.putback(t);
		val = expression();
		
	}

}
catch (exception& e) {
	cerr << "error: " << e.what() << "\n";
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------