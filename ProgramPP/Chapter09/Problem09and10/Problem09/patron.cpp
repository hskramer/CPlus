#include "patron.h"

Patron::Patron(string nm, int lcard, double fee)
	:uname{ nm }, libcard { lcard }, fees{ fee }
{
}
Patron::Patron()
	: uname{ "" },libcard { -1}, fees(0.)
{
}

void Patron::set_fee(double f)
{
	if (fees < 0) error("setUserFee(): error fee less than zero");
	fees = f;
}

bool owe_fees(const Patron& p)
{
	return p.get_fees() > 0;
}