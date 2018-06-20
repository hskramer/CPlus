#include "../../std_lib_facilities.h"

class Patron {
public:
	Patron(string uname, int libcard, double fees); // decided to add age so I could have something concrete to base fees on
	Patron();

	// nonmodifying operations:
	string get_name() const { return uname; }
	int get_libcard() const { return libcard; }
	double get_fees() const { return fees; }	

	// modifying operations
	void set_fee(double fees);

private:
	string uname;
	int libcard;
	double fees;
};

bool owe_fees(const Patron& p);
