#include "../../std_lib_facilities.h"

void enter_price_weight(vector<double>& p, vector<double>& w) {
	
	double pr{ 0 }, wh{ 0 }; // need to validate input otherwis loop could run wild

	cout << "Enter a price and weight for your items enter -1 for price when finished" << endl;

	while (true) {
		cout << "price: ";
		cin>>pr;
		if (pr == -1) break;
		p.push_back(pr);
		cout << "weight: ";
		cin >> wh;
		w.push_back(wh);
	}
}

//---------------------------------------------------------------------------------

void total_value(const vector<double>& pc, const vector<double>& wc) {
	 
	double sum{ 0 };

	if (pc.size() != wc.size())  error("error price and weight size don't match");

	for (int i = 0; i < pc.size(); ++i)
		sum += pc[i] * wc[i];

	cout << "The total value for all items is %6.2f" << sum << endl;
}

//---------------------------------------------------------------------------------

int main()
try {

	vector<double>price;
	vector<double>weight;

	enter_price_weight(price, weight);
	total_value(price, weight);

	return 1;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "unkown exception occured" << endl;
	return 2;
}