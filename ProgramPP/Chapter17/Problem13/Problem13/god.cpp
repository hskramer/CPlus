#include "gods.h"

int main()
try {

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}