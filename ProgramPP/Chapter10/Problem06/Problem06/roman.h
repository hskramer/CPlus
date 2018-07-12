#include "../../std_lib_facilities.h"

#ifndef	ROMAN_INT_H
#define ROMAN_INT_H
namespace Roman {
	class Roman_int {
	public:
		Roman_int();
		Roman_int(int v);

		// nonmodifying operations
		int as_int() const { return v; }	
		
		// set value
		void set_val(int r) { v = r; }
		
	private:
		int v;		
	};

// roman numerals use a subtractive notation so 19 is not XVIIII its XIX so its easiest from read left to right if the lval is less then rval subtract otherwise add

	const char I = 'I';			// one
	const char V = 'V';		   // five
	const char X = 'X';		  // ten
	const char L = 'L';		 // fifty
	const char C = 'C';		// one-hundred
	const char D = 'D';	   // five-hundred
	const char M = 'M';	  // one-thousand
	
	bool valid_char(const char ch);
	bool valid_order(string& s);
	int roman_char_value(const char& r);
	bool valid_numeral(string& s);
	bool valid_large_numeral(string& s, int n);		
	int roman_int(string& s);
	string roman_numeral(int rome_int);

	ostream& operator<<(ostream& os, Roman_int& r);
	istream& operator>>(istream& is, Roman_int& r);

}
#endif ROMAN_INT_H