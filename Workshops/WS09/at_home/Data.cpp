// Sue Ming Chun 
// 032343154

#include <iostream>
#include "Data.h"

using namespace std;

namespace sict {
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double population_change = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << population_change / 1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		const char* trend = "";								// why is it const char * and not just char? 
		if (violentCrime[0] > violentCrime[n - 1])
			trend = "down";
		else
			trend = "up";

		cout << "Violent Crime trend is " << trend << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double GTAnumber = average(grandTheftAuto, n);		// call template function average
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << "There are " << GTAnumber / 1000000 << " million Grand Theft Auto incidents on average a year" << endl;

		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;	// call template function min
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;	// call template function max 
	}
}