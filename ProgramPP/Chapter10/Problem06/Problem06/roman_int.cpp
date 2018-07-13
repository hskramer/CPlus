#include "roman.h"

namespace Roman {

	Roman_int::Roman_int()
		:v{ 0 } {}

	Roman_int::Roman_int(int r)
		: v{ r } {}

	bool valid_char(const char ch)
	{
		switch (ch) {
		case I: case V: case X: case L: case C: case D: case M:
			return true;
		default:
			return false;
		}
	}

	bool valid_order(string& s)
	{
		// values should decrease from left to right with exceptions for 400, 90, 9 and 4
		// with exception of 400 and 4 the left is 10 times the right, but checking for 10x should work for most cases 
		int left{ 0 }, right{ 0 };
		bool is_valid{ false };
		for (int i = 0; i < s.length() - 1; ++i) {
			left = roman_char_value(s[i]);
			right = roman_char_value(s[i + 1]);
			if (right <= 10 * left) {
				is_valid = true;
			}
			else {
				is_valid = false;
				break;
			}
		}
		return is_valid;
	}

	int roman_char_value(const char& r)
	{
		switch (r) { // the Roman's had no numeral for zero they did have word nulla for nothing (Wikipedia) and about 725AD some used N for nulla
		case I:	 return 1;
		case V:	 return 5;
		case X:	 return 10;
		case L:	 return 50;
		case C:	 return 100;
		case D:  return 500;
		case M:  return 1000;
		default:
			error("not a valid roman numeral ", r);
		}
	}

	bool valid_numeral(string& s)
	{
		int cnt{ 1 }, dcnt{ 0 }, lcnt{ 0 }; // D and L only used once
		for (int i = s.length() - 1; i >= 1; --i) {
			if (s[i] == M && s[i - 1] != C) {		// this excludes M from the maximum of three rule romans used as many M's as required
				if (valid_large_numeral(s, i)) {
					return true;					
				}
				else return false;

			}
			else if (s[i] == D)	{
				++dcnt; // romans only used D once 
				if (dcnt > 1)
					return false;
			}
			else if (s[i] == L) {
				++lcnt;
				if (lcnt > 1)
					return false;
			}
			else if (s[i] == s[i - 1]) {
				++cnt;
				if (cnt > 3) return false;
			}
			else {
				cnt = 1;
			}
		}
		return true;
	}

	bool valid_large_numeral(string& s, int n)
	{
		bool is_valid = false;
		for (int i = n; i >= 0; --i) { 
			if (s[i] != M || s[i] == D) {
				is_valid = false;
				break;
			}
			else
				is_valid = true;			
		}
		return is_valid;
	}

	
	int roman_int(string& s)
	{
		char ch{ 0 };
		int sum{ 0 }, prev_val{ 0 };

		if (!valid_order(s))
			error("valid_order(): error not a valid roman numeral ", s);
		
		if (!valid_numeral(s))
			error("roman_int(): not a valid roman numeral ", s);

					
		for (int i = s.length() - 1; i >= 0; --i) {
			if (roman_char_value(s[i]) >= prev_val) {
				sum += roman_char_value(s[i]);
			}
			else {
				sum -= roman_char_value(s[i]);
			}
			prev_val = roman_char_value(s[i]);
		}
		return sum;
	}

	string roman_numeral(int rome_int)
	{
	// learned in a mathematica problem let your array/vector index match your required symbol and apply div and mod in the proper order
		vector<string> thousands{ "", "M", "MM", "MMM" ,"MMMM", "MMMMM", "MMMMMM", "MMMMMMM" ,"MMMMMMMMM", "MMMMMMMMMM" };
		vector<string> hundreds{ "","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		vector<string> tens{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		vector<string> ones{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }; //

		string m = thousands[rome_int / 1000];
		string h = hundreds[(rome_int % 1000) / 100];
		string t = tens[(rome_int % 100) / 10];
		string o = ones[(rome_int % 10)];

		string numeral = m + h + t + o;

		return numeral;
	}

	ostream& operator<<(ostream& os, Roman_int& r)
	{
		return os <<"The roman numeral "<<roman_numeral(r.as_int()) << " is equal to "<<r.as_int() << endl;
	}
	
	istream& operator>>(istream& is, Roman_int& r)
	{
		char c{ 0 };
		string str{ "" };

		is.exceptions(is.exceptions() | ios_base::badbit); // make is throw if it goes bad

		while (is.get(c)) {
			if (valid_char(c))
				str += c;
			else {
				is.putback(c);
				break;
			}
		}
		int rint = roman_int(str);

		r.set_val(rint);	

		return is;
	}
};