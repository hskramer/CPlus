#include "../../std_lib_facilities.h"


int main(void)
{
	vector<double>distvec;
	double min{ 25000.0 }, max{ 0.0 }, sum{ 0.0 }, mean{ 0.0 }; //vs 2015 requires initiallized local variables to compile
	double dist;

	cout << "Enter several distances between cities either real or imagined (0 to end).\n";
	
	while (cin >> dist)
	{
		if (dist == 0.0)
		{
			cout << "The total distance is: " << sum << "\n";
			cout << "The longest distance is: " << max << "\n";
			cout << "The shortest ditance is : " << min << "\n";
			cout << "The mean distance between cities is: " << mean << "\n";
			break;
		}
		
		distvec.push_back(dist);
		if (min > dist)	min = dist;
		if (max < dist)  max = dist;
		sum += dist; 
		mean = sum / distvec.size();
	
	}

	return 0;
	
}